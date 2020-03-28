### 64\. [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/)

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:
```
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
```

#### Solution 1

Dynamic programming is a way of obtaining the extreme value. We can keep a 2d array of the same size 
storing the minimum sum at each location. DP has two elements -- state array and update function.
The update function follows the problem. The minimum of each loation is the previous location plus
the current value of the input array. The previous location can be either from up or from left,
because we can either go right or go down when computing the sum. Of course, when filling in the
top row we only need to consider left position and similarly when filling in the left column we only
need to consider above potition.

C++

```
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() or grid[0].empty()) return -1;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (i != 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
                if (j != 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
            }
        }
        return dp[dp.size() - 1][dp[0].size() - 1];
    }
};
```

Python

```
class Solution:
    int_max = 10000000000000
    def minPathSum(self, grid: List[List[int]]) -> int:
        if len(grid) == 0 or len(grid[0]) == 0:
            return -1
        dp = [[self.int_max for i in range(len(grid[0]))] for j in range(len(grid))]
        dp[0][0] = grid[0][0]
        
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if i != 0:
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j])
                if j != 0:
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j])
        return dp[len(grid) - 1][len(grid[len(grid) - 1]) - 1]
```
