### 209\. [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/)

Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 
```
Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
```

Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 

#### Solution 1

Time: O(n^2)
Space: O(1)

C++

```
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                if (j - i + 1 > res) break;
                sum += nums[j];
                if (sum >= s) {
                    res = j - i + 1;
                }
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
```

#### Solution 2

Time: O(n)
Space: O(1)

C++

```
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0, right = 0, sum = 0, res = INT_MAX;
        while (right < nums.size()) {
            while (right < nums.size() and sum < s) {
                sum += nums[right];
                right++;
            }
            // right pointer is one step ahead of the subarray
            while (left < right and sum >= s) {
                res = min(res, right - left);
                sum -= nums[left];
                left++;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
```

#### Solution 3

Time: O(nlogn)
Space: O(n)

C++

```
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> sums(nums.size() + 1, nums[0]);
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) sums[i + 1] = sums[i] + nums[i];
        for (int i = 0; i < nums.size(); i++) {
            int left = i + 1, right = nums.size(), target = sums[i] + s;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (sums[mid] < target) left = mid + 1;
                else right = mid - 1;
            }
            if (left == nums.size() + 1) break;
            res = min(res, left - i);
        }
        return res == INT_MAX ? 0 : res;
    }
};
```

Use lower_bound

```
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> sums = nums;
        for (int i = 1; i < sums.size(); i++) {
            sums[i] += sums[i - 1];
        }
        sums.insert(sums.begin(), 0);
        int res = INT_MAX;
        for (auto i = sums.begin(); i != sums.end(); ++i) {
            int target = *i + s;
            auto it = lower_bound(i, sums.end(), target);
            if (it != sums.end()) res = min(res, int(it - i));
        }
        return res == INT_MAX ? 0 : res;
    }
};
```
