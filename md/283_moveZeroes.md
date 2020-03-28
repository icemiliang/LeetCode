### 283\. [Move Zeroes](https://leetcode.com/problems/move-zeroes/)

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:
```
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
```
Note:

1. You must do this in-place without making a copy of the array.
2. Minimize the total number of operations.

#### Solution 1

Move non-zero elements to the front. Fill the rest with zeros.
j: last non-zero

C++

```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) nums[k++] = nums[i];
        }
        for (int i = k; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
```

#### Solution 2

j: first zero.

C++

```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        while (j < nums.size() and nums[j] != 0) ++j;
        for (int i = j + 1; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j++]);
                while (j < nums.size() and nums[j] != 0) ++j;
            }
        }
    }
};
```

