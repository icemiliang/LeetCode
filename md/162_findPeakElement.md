### 162\. [Find Peak Element](https://leetcode.com/problems/find-peak-element/)

A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:
```
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
```

Example 2:
```
Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5 
Explanation: Your function can return either index number 1 where the peak element is 2, 
             or index number 5 where the peak element is 6.
```

#### Solution 1

The first solution is very simple and short. It uses the condition that
the peak must exit and the first element is greater than its imaginary left.
Thus, the first element is already in an increasing order. We only need to 
find the first element that starts decreasing. That's it. When we reach the
last element and haven't found a peak, then the last element must be the peak.

C++

```
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) return i - 1;
        }
        return nums.size() - 1;
    }
};
```

Python

```
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        for i in range(1, len(nums)):
            if nums[i] < nums[i - 1]:
                return i - 1
        return len(nums) - 1
```

#### Solution 2

Because essentially we are checking whether the next element is
smaller or larger than the current number, it follows the idea
of binary search where each time we check whether the target is
on the left or on the right of the median. Thus, we can just
follow the standard binary search algorithm to solve this problem.
Remember to substrct one from the exiting index because it is 
the first element on the downhill. The peak is before it.

C++

```
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 1, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid - 1]) left = mid + 1;
            else right = mid;
        }      
        return right - 1;
    }
};
```

Python

```
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        left = 1
        right = len(nums)
        while left < right:
            mid = left + (right - left) // 2;
            if nums[mid] > nums[mid - 1]:
                left = mid + 1
            else:
                right = mid
        return right - 1
```
