### 221\. [Maximal Square](https://leetcode.com/problems/maximal-square/)

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:
```
Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
```

#### Solution 1

DP\[i\]\[j\]: edge length of the square with the lower right corner at i,j

DP\[i\]\[j\]: min(dp\[i-1\]\[j\], dp\[i\]\[j-1\], dp\[i-1\]\[j-1\]) 

C++

```
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() or matrix[0].empty()) return 0;
        int res = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (i == 0 or j == 0) dp[i][j] = matrix[i][j] - '0';
                else if (matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                }
                res = max(res, dp[i][j]);
            }
        }
        return res * res;
    }
};
```
