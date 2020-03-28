### 377\. [Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/)

Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:
```
nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
```

***Follow up:***
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?

***Credits:***
Special thanks to @pbrother for adding this problem and creating all test cases.


#### Solution 1

DP.

Similar to [70. Climbing Stairs](70_climbStairs.md).

For each target, it can be from a previous target + available coins/steps/numbers.

C++

```
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (auto num : nums) {
                if (i >= num) dp[i] += dp[i - num];
            }
        }
        return dp.back();
    }
};
```

Sort and then prune: if current amount smaller than current coin value break because
all coins after that are larger that that

```
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= target; ++i) {
            for (auto num : nums) {
                if (i < num) break;
                if (i >= num) dp[i] += dp[i - num];
            }
        }
        return dp.back();
    }
};
```
