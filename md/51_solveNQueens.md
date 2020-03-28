### 51\. [N-Queens](https://leetcode.com/problems/n-queens/)
Hard

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

![alt text](8-queens.png "8-queens")

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:
```
Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
```

#### Solution 1

C++

```
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sols;
        vector<string> sol(n, string(n, '.'));
        dfs(sols, sol, 0);
        return sols;
    }
    
    void dfs(vector<vector<string>>& sols, vector<string>& sol, int row) {
        // All rows filled
        if (row == sol.size()) {
            sols.push_back(sol);
            return;
        }
        
        // Fill a Q at each column
        for (int j = 0; j < sol.size(); ++j) {
            if (isValid(sol, row, j)) {
                sol[row][j] = 'Q';
                dfs(sols, sol, row + 1);
                sol[row][j] = '.';
            }
        }
    }
    
    bool isValid (vector<string>& sol, int row, int col) {
        //if the column had a queen before.
        for (int i = 0; i < row; i++) {
            if (sol[i][col] == 'Q') return false;
        }
        
        //if the 45 diagonal had a queen before.
        for (int i = row - 1, j = col - 1; i >= 0 and j >= 0; --i, --j) {
            if (sol[i][j] == 'Q') return false;
        }
        
        // if the 135 diagonal had a queen before.
        for (int i = row - 1, j = col + 1; i >= 0 and j < sol.size(); --i, ++j) {
            if (sol[i][j] == 'Q') return false;
        }
        return true;
    }
};
```


#### Solution 2

https://leetcode.com/problems/n-queens/discuss/19808/Accepted-4ms-c%2B%2B-solution-use-backtracking-and-bitmask-easy-understand.

C++

```
class Solution {
public:
    std::vector<std::vector<std::string> > solveNQueens(int n) {
        std::vector<std::vector<std::string> > res;
        std::vector<std::string> nQueens(n, std::string(n, '.'));
        /*
        flag[0] to flag[n - 1] to indicate if the column had a queen before.
        flag[n] to flag[3 * n - 2] to indicate if the 45° diagonal had a queen before.
        flag[3 * n - 1] to flag[5 * n - 3] to indicate if the 135° diagonal had a queen before.
        */
        std::vector<int> flag(5 * n - 2, 1);
        solveNQueens(res, nQueens, flag, 0, n);
        return res;
    }
private:
    void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, std::vector<int> &flag, int row, int &n) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (flag[col] && flag[n + row + col] && flag[4 * n - 2 + col - row]) {
                flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 0;
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, flag, row + 1, n);
                nQueens[row][col] = '.';
                flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 1;
            }
    }
};
```
