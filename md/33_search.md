### 33\. [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:
```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```
Example 2:
```
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```

#### Solution 1

Although the array is rotated, but each of the two segments are still sorted, which 
leads us to binary search. For binary search to work, each time we must determine
if the target is on the left or on the right of the median. The trick is this. Looking
at the examples, if the median is smaller than the right element, then the elements
from the median to the right element is in ascending order and if the contrary, the 
elements from the left element to the median is in ascending order. Therefore, we can
check if the target is in any of these two subarrays. The code below shows how we can
check the conditions.

C++

```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < nums[right]) {
                if (nums[mid] < target and target <= nums[right]) left = mid + 1;
                else right = mid -1;
            }
            else {
                if (nums[left] <= target and target < nums[mid]) right = mid -1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};
```

Python 

```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0; right = len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2;
            if nums[mid] == target:
                return mid
            if nums[mid] < nums[right]:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
            else:
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
        return -1
```
