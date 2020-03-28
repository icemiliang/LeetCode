### 36\. [Valid Sudoku](https://leetcode.com/problems/valid-sudoku/)

Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits ```1-9``` without repetition.
Each column must contain the digits ```1-9``` without repetition.
Each of the 9 ```3x3``` sub-boxes of the grid must contain the digits ```1-9``` without repetition.

A partially filled sudoku which is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character ```'.'```.

Example 1:
```
Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
```

Example 2:
```
Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
```

Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
Note:

* A Sudoku board (partially filled) could be valid but is not necessarily solvable.
* Only the filled cells need to be validated according to the mentioned rules.
* The given board contain only digits 1-9 and the character '.'.
* The given board size is always 9x9.


#### Solution 1

Maintain a 3D bool array to record seen numbers.

There are three coordinates in the board: row, col, block.
For each index of each coordinate, one number can appear at most once.
The first index of the 3D array indicates which coordinate -- row, col, block.
The second index of the array indicates where at the coordinate, ranging from 0 to 8.
The third index indicates what the number is at that coordinate.
idx\[0\]\[3\]\[2\] tells whether we have seen 2 at row 3.

The default value if false. For each number on the board, check if the number
has already appeared in the current row, or in the current col, or in the current block.
Return false if already seen. If not, set to true and continue.

We could use 3 seperate 2D arrays to store the same info, one for row, one for col, 
and one for block. I just use one 3D array to keep the code cleaner. We could also use 
a 3x9x128 to store the original raw char to avoid the subtraction each time.

C++

```
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool nums[3][9][9] = {false};
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] < '1' or board[i][j] > '9') continue;
                int k = (i / 3) * 3 + (j / 3);
                int num = board[i][j] - '1';
                if (nums[0][i][num]) return false;
                if (nums[1][j][num]) return false;
                if (nums[2][k][num]) return false;
                nums[0][i][num] = true;
                nums[1][j][num] = true;
                nums[2][k][num] = true;
            }
        }
        return true;
    }
};
```
