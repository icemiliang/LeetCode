### 63\. [Unique Paths II](https://leetcode.com/problems/unique-paths-ii/)

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

![alt text](robot_maze.png)

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:
```
Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
```

#### Solution 1

Same approach as in [62 Unique Paths](62_uniquePaths.md). If obstable, skip.

C++

```
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (obstacleGrid.front().front() == 1 or obstacleGrid.back().back() == 1) return 0;
        vector<vector<long>> dp(m, vector<long>(n, 0));
        dp[0][0] = 1;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) continue;
                if (i > 0) dp[i][j] += dp[i - 1][j];
                if (j > 0) dp[i][j] += dp[i][j - 1];
            }
        }
        return dp.back().back();
    }
};
```
