### 15\. [3Sum](https://leetcode.com/problems/3sum/)

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:
```
Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```

#### Solution 1

It's important to stop early and remove duplicates for all three indices.

C++

```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 and nums[i] == nums[i - 1]) continue;
            int target = -nums[i];
            int j = i + 1, k = n - 1;
            while (j < k) {
                if (nums[i] + nums[j] > 0) break;
                int sum = nums[j] + nums[k];
                if (sum == target) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    while (j < k and nums[j] == nums[j + 1]) ++j;
                    while (j < k and nums[k] == nums[k - 1]) --k;
                    ++j;
                    --k;
                }
                else if (sum < target) ++j;
                else --k;
            }
        }
        return res;
    }
};
```
