### 523\. [Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/)

Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to a multiple of k, that is, sums up to n\*k where n is also an integer.

Example 1:
```
Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
```
Example 2:
```
Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
```

Note:

1. The length of the array won't exceed 10,000.
2. You may assume the sum of all the numbers is in the range of a signed 32-bit integer.

#### Solution 1

Brute force.

C++

```
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size() - 1; i++) {
            int sum = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                sum += nums[j];
                if (sum == k) return true;
                if (k != 0 and sum % k == 0) return true;
            }
        }
        return false;
    }
};
```

#### Solution 2

Prefix sum.

If the same redisual by divided by sum appears twice,
then the sum of the numbers between them is a multiple of k.

C++

using a set. 

```
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0, pre = 0;
        unordered_set<int> residual;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int t = (k == 0) ? sum : (sum % k);
            if (residual.count(t)) return true;
            residual.insert(pre);
            pre = t;
        }
        return false;
    }
};
```

Using a hashmap

```
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> residual; // position
        residual[0] = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int t = (k == 0) ? sum : (sum % k);
            if (residual.count(t)) {
                if (i - residual[t] > 1) return true;
            }
            else residual[t] = i;
        }
        return false;
    }
};
```