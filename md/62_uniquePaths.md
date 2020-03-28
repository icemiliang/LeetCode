### 62\. [Unique Paths](https://leetcode.com/problems/unique-paths/)

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

![alt text](robot_maze.png "robot_maze.png")


Above is a 7 x 3 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:
```
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
```
Example 2:
```
Input: m = 7, n = 3
Output: 28
```

#### Solution 1

DP

C++

2D DP

```
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 or n <= 0) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // if (i == 0 or j == 0) dp[i][j] = 1;
                if (i > 0) dp[i][j] += dp[i - 1][j];
                if (j > 0) dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
```


1D DP 1 row

```
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 or n <= 0) return 0;
        vector<int> dp(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
                cout << dp[j] << endl;
            }
        }
        return dp.back();
    }
};
```

#### Solution 2

m - 1 steps to right, n - 1 steps to down
Select m - 1 steps from m + n - 2 steps.

C++

```
class Solution {
public:
    int uniquePaths(int m, int n) {
        long num = 1, denom = 1;
        int small = m < n ? m - 1 : n - 1;
        for (int i = 1; i <= small; i++) {
            denom *= i;
            num *= m + n - 1 - i;
        }
        return num / denom;
    }
};
```
