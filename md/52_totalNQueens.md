### 52\. [N-Queens II](https://leetcode.com/problems/n-queens-ii/)

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

![alt text](8-queens.png "8-queens")

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example:
```
Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
```

#### Solution 1

C++

```
class Solution {
public:
    int totalNQueens(int n) {
        vector<int> board(n, -1);  // pos of queen at each row
        int res = 0;
        dfs(board, 0, res);
        return res;
    }
    
    void dfs(vector<int>& board, int row, int& res) {
        if (row == board.size()) {
            ++res;
            return;
        }
        
        for (int col = 0; col < board.size(); ++col) {
            if (isValid(board, row, col)) {
                board[row] = col;
                dfs(board, row + 1, res);
                board[row] = -1;
            }
        }
    }
    
    bool isValid(vector<int>& board, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i] == col or abs(board[i] - col) == abs(row - i)) return false;
        }
        
        return true;
    }
};
```
