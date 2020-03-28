### 303\. [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/)

Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
```
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
```
Note:
1. You may assume that the array does not change.
2. There are many calls to sumRange function.

#### Solution 1

C++

```
class NumArray {
    vector<int> dp;
public:
    NumArray(vector<int>& nums) {
        dp.resize(nums.size() + 1);
        dp[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            dp[i + 1] = dp[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return dp[j + 1] - dp[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
```
