### 130\. [Surrounded Regions](https://leetcode.com/problems/surrounded-regions/)

Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:
```
X X X X
X O O X
X X O X
X O X X
```
After running your function, the board should be:
```
X X X X
X X X X
X X X X
X O X X
```
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

#### Solution 1

DFS 1
Only zeros that are connected to boundaries will be flipped. 
DFS for zeros from boundaries. Change boundary O to $.

C++

```
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() or board[0].empty()) return;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 or j == 0 or i == m - 1 or j == n - 1) and board[i][j] == 'O') {
                    dfs(board, i, j);
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '$') board[i][j] = 'O';
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] == 'O') {
            board[i][j] = '$';
            if (i > 0 and board[i - 1][j] == 'O') dfs(board, i - 1, j);
            if (i < board.size() - 1 and board[i + 1][j] == 'O') dfs(board, i + 1, j);
            if (j > 0 and board[i][j - 1] == 'O') dfs(board, i, j - 1);
            if (j < board[i].size() - 1 and board[i][j + 1] == 'O') dfs(board, i, j + 1);
        }
    }
};
```

#### Solution 2

BFS

C++

```
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() or board[0].empty()) return;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 or i == m - 1 or j == 0 or j == n - 1) and board[i][j] == 'O') {
                    queue<pair<int, int>> todo;
                    board[i][j] = '$';
                    todo.push({i, j});
                    while (!todo.empty()) {
                        auto t = todo.front(); todo.pop();
                        int x = t.first;
                        int y = t.second;
                        if (x > 0 and board[x - 1][y] == 'O') {board[x - 1][y] = '$'; todo.push({x - 1, y});}
                        if (x < m - 1 and board[x + 1][y] == 'O') {board[x + 1][y] = '$'; todo.push({x + 1, y});}
                        if (y > 0 and board[x][y - 1] == 'O') {board[x][y - 1] = '$'; todo.push({x, y - 1});}
                        if (y < n - 1 and board[x][y + 1] == 'O') {board[x][y + 1] = '$'; todo.push({x, y + 1});}
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '$') board[i][j] = 'O';
            }
        }
    }
};
```