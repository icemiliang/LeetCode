### 300\. [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)

Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:
```
Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
```

Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?

#### Solution 1

DP: max length until i

C++

```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
```

#### Solution 2

Binary Search.

Maintain a increasing array. Scan the input array. For each element, 
find the lower bound. If it is the end of the array which means no 
element in the new array is bigger, then add it to the new array.
If the lower bound is in the array, replace the element with the 
query element. Note that the new array may not be in the real order.

C++

```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for (int num : nums) {
            auto it = lower_bound(v.begin(), v.end(), num);
            if (it == v.end()) v.push_back(num);
            else *it = num;
        }
        return v.size();
    }
};
```
