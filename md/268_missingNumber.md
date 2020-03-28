### 268\. [Missing Number](https://leetcode.com/problems/missing-number/)

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:
```
Input: [3,0,1]
Output: 2
```

Example 2:
```
Input: [9,6,4,2,3,5,7,0,1]
Output: 8
```

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

#### Solution 1

bitwise or all elements in the array and all from 1 to n. 
The remainder is the missing element.

Time: O(n)
Space: O(1)

C++

```
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res ^= (i + 1) ^ nums[i];
        }
        return res;
    }
};
```

#### Solution 2

Sum of 1 to n minus sum of array.

Time: O(n)
Space: O(1)

C++

```
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (auto &a : nums) {
            sum += a;
        }
        return 0.5 * n * (n + 1) - sum;
    }
};
```
