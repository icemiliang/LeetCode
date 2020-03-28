### 560\. [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
```
Input:nums = [1,1,1], k = 2
Output: 2
```
Note:
1. The length of the array is in range [1, 20,000].
2. The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

#### Solution 1

Elements can be negative. Thus, same sum can appear multiple times.
Use a hashmap to store frequency of sum. Scan the array.
If current sum minus a previous sum equals k, add the frequency to 
the result.

C++

```
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        unordered_map<int, int> freq; // sum count until current element
        int sum = 0;
        freq[0] = 1;
        int res = 0;
        for (int& num : nums) {
            sum += num;
            if (freq.find(sum - k) != freq.end()) {
                // find sum - k
                res += freq[sum - k];
            }
            ++freq[sum];
        }
        return res;
    }
};
```

#### Solution 2

Build a sum array. Very slow.

C++

```
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        vector<int> sum(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        cout << sum.size();
        int res = 0;
        for (int i = 1; i < sum.size(); i++) {
            for (int j = i; j < sum.size(); j++) {
                if (sum[j] - sum[i - 1] == k) res++;
            }
        }
        return res;
    }
};
```

#### Solution 3

Brute-force.

C++

```
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == k) {
                    res++;
                }
            }
        }
        return res;
    }
};
```
