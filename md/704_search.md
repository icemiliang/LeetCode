### 704\. [Binary Search](https://leetcode.com/problems/binary-search/)

Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. If target exists, then return its index, otherwise return -1.


Example 1:
```
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
```
Example 2:
```
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
```

#### Solution 1

This is a classic binary search problem. We have covered binary search in [35. Search Insert Position](https://leetcode.com/problems/search-insert-position/).

C++
```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return -1;
    }
};
```

Python

```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums)
        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return mid
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid
        return -1
```
