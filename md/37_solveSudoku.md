### 37\. [Sudoku Solver](https://leetcode.com/problems/sudoku-solver/)

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.

![alt text](250px-Sudoku-by-L2G-20050714.svg.png)

A sudoku puzzle...

![alt text](250px-Sudoku-by-L2G-20050714_solution.svg.png)

...and its solution numbers marked in red.

Note:

* The given board contain only digits 1-9 and the character '.'.
* You may assume that the given Sudoku puzzle will have a single unique solution.
* The given board size is always 9x9.

#### Solution 1

Backtrack

C++

```
class Solution {
private:
    bool row[9][9] = {false};
    bool col[9][9] = {false};
    bool box[9][9] = {false};
public:
    void solveSudoku(vector<vector<char>>& board) {        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int n = board[i][j] - '0' - 1;
                    int k = i / 3 * 3 + j / 3;
                    col[j][n] = true;
                    row[i][n] = true;
                    box[k][n] = true;
                }
            }
        }
        
        backtrack(board, 0, 0);
    }
    
    bool backtrack(vector<vector<char>>& board, int start_i, int start_j) {
        for (int i = start_i; i < 9; i++) {
            for (int j = i == start_i ? start_j : 0; j < 9; j++) {
                if (board[i][j] != '.') continue;
                int k = i / 3 * 3 + j / 3;
                for (int x = 0; x < 9; x++) {
                    if (row[i][x] or col[j][x] or box[k][x]) continue;
                    row[i][x] = col[j][x] = box[k][x] = true;
                    board[i][j] = x + 1 + '0';
                    
                    if (backtrack(board, i, j+1)) return true;
                    row[i][x] = col[j][x] = box[k][x] = false;
                    board[i][j] = '.';
                }
                return false;
            }
        }
        return true;
    }
};
```
