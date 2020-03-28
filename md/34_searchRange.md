### 34\. [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:
```
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
```

Example 2:
```
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
```

#### Solution 1

This is a good problem for practicing binary search. It asks for both the lower bound and the upper bound.
We have a prototype for binary search. left starts from 0. right starts from size which is outside of the
array. Then, if we want to find the lower bound, the stopping criteria is mid < target and right is the 
lower bound.; if we want to find the upper bound, it is mid <= target and right - 1 is the upperbound.
Either way, left = mid + 1 or right = mid. Lower bound means we will stop if mid >= target at which time
right = mid. Upper bound means we will stop if mid > target at which time right = mid, but mid is already
not the target so the solution is right - 1.

C++

```
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        vector<int> res;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (left == nums.size() or nums[left] != target) return {-1, -1};
        res.push_back(left);
        right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) left = mid + 1;
            else right = mid;
        }
        res.push_back(right - 1);
        return res;
    }
};
```

Python

```
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left = 0
        right = len(nums)
        res = []
        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid
        if right == len(nums) or nums[right] != target:
            return [-1, -1]
        res.append(right)
        right = len(nums)
        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] <= target:
                left = mid + 1
            else:
                right = mid
        res.append(right - 1)
        return res
```
