### 73\. [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/)

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:
```
Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
```

Example 2:
```
Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
```

Follow up:

* A straight forward solution using O(mn) space is probably a bad idea.
* A simple improvement uses O(m + n) space, but still not the best solution.
* Could you devise a constant space solution?

#### Solution 1

1. check if 1st row or 1st column have zeros
2. store zeros info in 1st row and column
3. set zeros except for 1st row and column
4. set zeros for 1st row and column according to step 1

C++

```
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.empty() or matrix[0].empty()) return;
        int m = matrix.size(), n = matrix[0].size();
        
        // check if 1st row or 1st column have zeros
        // we use the 1st row and column to store zeros info
        bool rowZero = false, colZero = false;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                colZero = true;
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (matrix[0][i] == 0) {
                rowZero = true;
                break;
            }
        } 
        
        // store zeros info in 1st row and column
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        // set zeros except for 1st row and column
        for (int i = 1; i < m; ++i) {
            if (matrix[i][0] == 0)
                for (int j = 1; j < n; ++j) {
                    matrix[i][j] = 0;
                }
        }
        for (int j = 1; j < n; ++j) {
            if (matrix[0][j] == 0)
                for (int i = 1; i < m; ++i) {
                    matrix[i][j] = 0;
                }
        }
        
        // set zeros for 1st row and column
        if (rowZero) {
            for (int i = 0; i < n; ++i) matrix[0][i] = 0;
        }
        if (colZero) {
            for (int i = 0; i < m; ++i) matrix[i][0] = 0;
        }
    }
};
```

#### Solution 2

set rows and columns to a magic number which we hope does not appear in the matrix.
Then, replace magic number with zero

C++

```
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() or matrix[0].empty()) return;
        int MAGIC = 1e9;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    for (int ii = 0; ii < m; ++ii) {
                        if (matrix[ii][j] != 0) matrix[ii][j] = MAGIC;
                    }
                    for (int jj = 0; jj < n; ++jj) {
                        if (matrix[i][jj] != 0) matrix[i][jj] = MAGIC;
                    }
                }
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == MAGIC) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
```
