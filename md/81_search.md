### 81\. [Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:
```
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
```

Example 2:
```
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false

```
Follow up:

* This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
* Would this affect the run-time complexity? How and why?

#### Solution 1

C++

```
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        if (nums.size() == 1) return nums[0] == target;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] < nums[right]) {
                if (nums[mid] < target and target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
            else if (nums[mid] > nums[right]) {
                if (nums[left] <= target and target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
            else right--;
        }
        return false;
    }
};
```
