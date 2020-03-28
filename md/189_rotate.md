### 189\. [Rotate Array](https://leetcode.com/problems/rotate-array/)

Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:
```
Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
```

Example 2:
```
Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
```

Note:

* Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
* Could you do it in-place with O(1) extra space?

#### Solution 1

Rotation step by step for k times 
Time: O(kn)
Space: (1)

C++

```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;
        k %= nums.size();
        while (k-- > 0) {
            int tmp = nums.back();
            for (int i = nums.size() - 2; i >= 0; --i) {
                nums[i + 1] = nums[i];
            }
            nums[0] = tmp;
        }
    }
};
```

#### Solution 2

reverse two subarrays

   [1,2,3,4,5,6,7]
-> [7,6,5,4,3,2,1]
-> [5,6,7,4,3,2,1]
-> [5,6,7,1,2,3,4]

C++

```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
```
