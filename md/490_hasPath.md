### 490\. [The Maze](https://leetcode.com/problems/the-maze/)

There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.

 

Example 1:
```
Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (4, 4)

Output: true

Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
```

![alt text](maze_1_example_1.png)

Example 2:
```
Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (3, 2)

Output: false

Explanation: There is no way for the ball to stop at the destination.
```
![alt text](maze_1_example_2.png)

Note:

1. There is only one ball and one destination in the maze.
2. Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
3. The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
4. The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.

#### Solution 1

BFS.

Classic BFS. Only record visited at the end of each motion.

Time: ??
Space: O(n)

C++

```
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(); if (m == 0) return false;
        int n = maze[0].size();
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> todo;
        todo.push({start[0], start[1]});
        vector<vector<int>> visited(m, vector<int>(n, 0));
        while (!todo.empty()) {
            auto t = todo.front(); todo.pop();
            if (t.first == destination[0] and t.second == destination[1]) return true;
            int x = t.first;
            int y = t.second;
            for (auto& dir : dirs) {
                int x_new = x + dir.first;
                int y_new = y + dir.second;
                if (x_new < 0 or x_new >= m or y_new < 0 or y_new >= n) continue;
                while (x_new >= 0 and x_new < m and y_new >= 0 and y_new < n and maze[x_new][y_new] == 0) {
                    x_new += dir.first;
                    y_new += dir.second;
                }
                x_new -= dir.first;
                y_new -= dir.second;
                if (visited[x_new][y_new]) continue;
                visited[x_new][y_new] = 1;
                todo.push({x_new, y_new});
            }
        }
        return false;
    }
};
```

```
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        vector<pair<int, int>> dirs = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
        queue<vector<int>> todo;
        todo.push(start);
        maze[start[0]][start[1]] = -1;
        while (!todo.empty()) {
            auto t = todo.front(); todo.pop();
            for (auto& dir : dirs) {
                int di = dir.first;
                int dj = dir.second;
                int i = t[0];
                int j = t[1];
                while (i + di >= 0 && i + di < m && j + dj >= 0 && j + dj < n && maze[i + di][j + dj] <= 0) {
                    i += di;
                    j += dj;
                }
                if (i == destination[0] && j == destination[1]) {
                    return true;
                }
                if (!maze[i][j]) {
                    maze[i][j] = -1;
                    todo.push({i, j});
                }
            }
        }
        return false;
    }
};
``` 

Use set to store visited positions to save spaces as they can be very sparse,
but it also increases running time, although set has a constant inserting and
querying complexity.

C++

```
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(); if (m == 0) return false;
        int n = maze[0].size();
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> todo;
        todo.push({start[0], start[1]});
        set<pair<int, int>> visited;
        while (!todo.empty()) {
            auto t = todo.front(); todo.pop();
            if (t.first == destination[0] and t.second == destination[1]) return true;
            int x = t.first;
            int y = t.second;
            for (auto& dir : dirs) {
                int x_new = x + dir.first;
                int y_new = y + dir.second;
                if (x_new < 0 or x_new >= m or y_new < 0 or y_new >= n) continue;
                while (x_new >= 0 and x_new < m and y_new >= 0 and y_new < n and maze[x_new][y_new] == 0) {
                    x_new += dir.first;
                    y_new += dir.second;
                }
                x_new -= dir.first;
                y_new -= dir.second;
                auto msg = visited.insert({x_new, y_new});
                if (!msg.second) continue;
                todo.push({x_new, y_new});
            }
        }
        return false;
    }
};
```
