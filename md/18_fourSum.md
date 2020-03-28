### 18\. [4Sum](https://leetcode.com/problems/4sum/)

Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:
```
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
```

#### Solution 1

A mimic of three sum. Pruning is important to reduce running time.

C++

```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 and nums[i] == nums[i - 1]) continue; // early-stop
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break; // early-stop
            if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue; // early-stop
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 and nums[j] == nums[j - 1]) continue; // early-stop
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break; // early-stop
                if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue; // early-stop
                int t = target - nums[i] - nums[j];
                int k = j + 1, l = n - 1;
                while (k < l) {
                    int sum = nums[k] + nums[l];
                    if (sum == t) {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while (k < l and nums[k] == nums[k + 1]) ++k; // early-stop
                        while (k < l and nums[l] == nums[l - 1]) --l; // early-stop
                        ++k;
                        --l;
                    }
                    else if (sum < t) ++k;
                    else --l;
                }
            }
        }
        return res;
    }
};
```
