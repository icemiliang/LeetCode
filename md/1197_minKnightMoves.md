### 1197\. [Minimum Knight Moves](https://leetcode.com/problems/minimum-knight-moves/)

In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].

A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.

![alt text](knight.png "knight")

Return the minimum number of steps needed to move the knight to the square [x, y].  It is guaranteed the answer exists.

Example 1:
```
Input: x = 2, y = 1
Output: 1
Explanation: [0, 0] → [2, 1]
```

Example 2:
```
Input: x = 5, y = 5
Output: 4
Explanation: [0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]
```

Constraints:

* |x| + |y| <= 300

#### Solution 1

C++

```
class Solution {
public:
    int minKnightMoves(int x, int y) {
        if (x == 0 and y == 0) return 0;
        x = abs(x); y = abs(y);
        queue<pair<int,int>> todo;
        todo.push({0,0});
        vector<vector<int>> dirs = {{1,2},{2,1},{2,-1},{1,-2},{-1,2},{-2,1},{-1,-2},{-2,-1}};
        int steps = 0;
        unordered_map<int, unordered_map<int, bool>> visited;
        visited[0][0] = true;
        while(!todo.empty()) {
            steps++;
            for(int size = todo.size() - 1; size >= 0; size--) {
                auto [i, j] = todo.front(); todo.pop();
                for(int k = 0; k < 8; k++) {
                    int new_x = i + dirs[k][0];
                    int new_y = j + dirs[k][1];
                    if(new_x == x and new_y == y) return steps;
                    if(!visited[new_x][new_y] and new_x > -2 and new_y > -2) {
                        visited[new_x][new_y] = true;
                        todo.push({new_x, new_y});
                    }
                }
            }
        }
        return -1;
    }
};
```

#### Solution 2

Use a 2d visited board to store step so that we don't need pop all the elements every time.

Time: O(N^2)
Space: O(N^2)

C++

```
class Solution {
public:
    int minKnightMoves(int x, int y) {
        if (x == 0 and y == 0) return 0;
        x = abs(x);
        y = abs(y);
        queue<pair<int, int>> todo;
        todo.push({0, 0});
        vector<vector<int>> board(302, vector<int>(302, 0));
        vector<pair<int, int>> dirs = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
        int step = 0;
        while (!todo.empty()) {
            auto [i, j] = todo.front(); todo.pop();
            int step = board[i + 1][j + 1];
            for (int k = 0; k < 8; k++) {
                int new_x = i + dirs[k].first;
                int new_y = j + dirs[k].second;
                if (new_x == x and new_y == y) return step + 1;
                if (new_x > -2 and new_y > -2 and new_x + new_y <= 300 and board[new_x + 1][new_y + 1] == 0) {
                    board[new_x + 1][new_y + 1] = step + 1;
                    todo.push({new_x, new_y});
                }
            }
        }
        return -1;
    }
};
```
