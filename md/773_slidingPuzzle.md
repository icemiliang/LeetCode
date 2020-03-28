### 773\. [Sliding Puzzle](https://leetcode.com/problems/sliding-puzzle/)

On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.

A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.

Examples:
```
Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.
```
```
Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.
```
```
Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]
Input: board = [[3,2,4],[1,5,0]]
Output: 14
```

Note:

* board will be a 2 x 3 array as described above.
* board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5].

#### Solution 1

For a general case, very slow. Need to store the board.
To avoid searching for 0 every time, also store the 
position of 0.

C++

```
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
  		int step = 0;
  		set<vector<vector<int>>> visited;
  		queue<pair<vector<vector<int>>, vector<int>>> todo;
  		vector<vector<int>> target = {{1, 2, 3}, {4, 5, 0}};
  		vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  		for (int i = 0; i < board.size(); ++i) {
  			for (int j = 0; j < board[0].size(); ++j) {
  				if (board[i][j] == 0) {
  					todo.push({board, {i, j}});
  					break;
  				}
  			}
  		}

  		while (!todo.empty()) {
  			for (int i = todo.size() - 1; i >= 0; --i) {
  				auto t = todo.front().first;
  				if (t == target) return step;
  				auto pos = todo.front().second;  todo.pop();
  				visited.insert(t);
  				for (auto& dir : dirs) {
  					int x = pos[0] + dir[0];
  					int y = pos[1] + dir[1];
  					if (x < 0 or y < 0 or x >= 2 or y >= 3) continue;
  					vector<vector<int>> cand = t;
  					swap(cand[pos[0]][pos[1]], cand[x][y]);
  					if (visited.count(cand)) continue;
  					todo.push({cand, {x, y}});
  				}
  			}
  			++step;
  		}
  		return -1;
    }
};
```

#### Solution 2

Because the board is 2 x 3, we can encode it into a string.

C++

```
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
  		unordered_set<string> visited;
  		string target = "123450";
  		string start = "";
  		for (int i = 0; i < 2; ++i) {
  			for (int j = 0; j < 3; ++j) {
  				start += board[i][j] + '0';
  			}
  		}

  		vector<vector<int>> dirs = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
  		queue<string> todo;
  		todo.push(start);
  		int step = 0;
  		while (!todo.empty()) {
  			for (int i = todo.size() - 1; i >= 0; --i) {
				auto t = todo.front(); todo.pop();
  				if (t == target) return step;
  				visited.insert(t);
  				int j = 0;
  				for (; j < 6; j++) {
  					if (t[j] == '0') break;
  				}
  				for (auto& dir : dirs[j]) {
  					string s = t;
  					swap(s[j], s[dir]);
  					if (visited.count(s)) continue;
  					todo.push(s);
  				}
  			}
  			++step;
  		}
  		return -1;
    }
};
```
