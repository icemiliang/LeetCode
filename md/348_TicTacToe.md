### 348\. [Design Tic-Tac-Toe](https://leetcode.com/problems/design-tic-tac-toe/)

Design a Tic-tac-toe game that is played between two players on a n x n grid.

You may assume the following rules:

1. A move is guaranteed to be valid and is placed on an empty block.
2. Once a winning condition is reached, no more moves is allowed.
3. A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.


Example:

```
Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.

TicTacToe toe = new TicTacToe(3);

toe.move(0, 0, 1); -> Returns 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

toe.move(0, 2, 2); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

toe.move(2, 2, 1); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

toe.move(1, 1, 2); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

toe.move(2, 0, 1); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

toe.move(1, 0, 2); -> Returns 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|
```

Follow up:
Could you do better than O(n2) per move() operation?

#### Solution 1

A shalow solution. Put the value into the position. Check row, col, and diags.

Time: O(n^2)
Space: O(1)

C++

```
class TicTacToe {
    vector<vector<int>> board;
    int n;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        board.resize(n, vector<int>(n, 0));
        this->n = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        board[row][col] = player;
        // col
        int i = 0;
        for (; i < n; ++i) {
            if (board[i][col] != player) break;
        }
        if (i == n) return player;
        
        // row
        int j = 0;
        for (; j < n; ++j) {
            if (board[row][j] != player) break;
        }
        if (j == n) return player;
        
        // diag 1
        if (row == col) {
            for (i = 0; i < n; ++i) {
                if (board[i][i] != player) break;
            }
            if (i == n) return player;
        }
        
        // diag 2
        if (row + col == n - 1) {
            for (i = 0; i < n; ++i) {
                if (board[i][n - i - 1] != player) break;
            }
            if (i == n) return player;
        }
        
        // continue
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
```

#### Solution 2

Keep the sum of each row, each col, and each diag.
If player 1, +1; if player 2, -1;
If n, player 1 wins; if -n, player 2 wins;

Time: O(1)
space: O(1)

C++

```
class TicTacToe {
    vector<int> rows;
    vector<int> cols;
    int diag1;
    int diag2;
    int n;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rows.resize(n, 0);
        cols.resize(n, 0);
        diag1 = 0;
        diag2 = 0;
        this->n = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int m = player == 1 ? 1 : -1;
        rows[row] += m; if (abs(rows[row]) == n) return player;
        cols[col] += m; if (abs(cols[col]) == n) return player;
        if (row == col) { diag1 += m; if (abs(diag1) == n) return player; }
        if (row + col == n - 1) { diag2 += m; if (abs(diag2) == n) return player; }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
```
