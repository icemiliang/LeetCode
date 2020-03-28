### 416\. [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/)

Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.
 

Example 1:
```
Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
```

Example 2:
```
Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
```

#### Solution 1

C++

```
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int i = target; i >= num; i--) {
                dp[i] = dp[i] or dp[i - num];
            }
        }
        return dp[target];
    }
};
```

#### Solution 2

C++

```
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<5001> bits(1);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int num : nums) bits |= bits << num;
        return (sum % 2 == 0) && bits[sum >> 1];
    }
};
```
