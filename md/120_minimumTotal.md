### 120\. [Triangle](https://leetcode.com/problems/triangle/)

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

#### Solution 1

DP

From bottom to top. Add the smaller child to the parent.

C++

```
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        if (triangle.size() == 1) return triangle[0][0];
        
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};
```

To void modifying the input, use an array.
Each time modify the array according to input.

```
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        
        vector<int> dp(triangle[triangle.size() - 1]);
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
};
```
