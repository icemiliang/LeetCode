### 628\. [Maximum Product of Three Numbers](https://leetcode.com/problems/maximum-product-of-three-numbers/)

Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:
```
Input: [1,2,3]
Output: 6
```

Example 2:
```
Input: [1,2,3,4]
Output: 24
```

Note:

1. The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
2. Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.

#### Solution 1

Sort.

C++

```
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int p1 = nums[0] * nums[1] * nums[n - 1];
        int p2 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        return p1 > p2 ? p1 : p2;
    }
};
```

Keep five values.

```
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        int n1 = INT_MAX, n2 = INT_MAX, n3 = INT_MIN, n4 = INT_MIN, n5 = INT_MIN;
        for (int num : nums) {
        	if (num > n5) { n3 = n4; n4 = n5; n5 = num; }
        	else if (num > n4) { n3 = n4; n4 = num; }
        	else if (num > n3) n3 = num;
        	if (num < n1) { n2 = n1; n1 = num; }
        	else if (num < n2) n2 = num;
        }
        int p1 = n1 * n2 * n5;
        int p2 = n3 * n4 * n5;
        return p1 > p2 ? p1 : p2;
    }
};
```