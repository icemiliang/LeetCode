### 152\. [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/)

Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:
```
Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
```

Example 2:
```
Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
```

#### Solution 1

C++

```
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = INT_MIN, mn = 1, mx = 1;
        for (int num : nums) {
            int tmp = mn; // keep previous mn for calculating new mx
            mn = min(num, min(mn * num, mx * num));
            mx = max(num, max(mx * num, tmp * num));
            res = max(res, mx);
        }
        return res;
    }
};
```

