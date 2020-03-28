### 35\. [Search Insert Position](https://leetcode.com/problems/search-insert-position/)

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:
```
Input: [1,3,5,6], 5
Output: 2
```

Example 2:
```
Input: [1,3,5,6], 2
Output: 1
```

Example 3:
```
Input: [1,3,5,6], 7
Output: 4
```

Example 4:
```
Input: [1,3,5,6], 0
Output: 0
```


#### Solution 1

This is another perfect testbed for binary search because we are to
find a target in a sorted array. Keep two pointers, one from 0, one from 
the size, n. Each time check the median. If it is smaller than the target,
then left is the median index plus one. Otherwise, move the right pointer
to the median index. Repeat until left is no longer smaller than right.
In the end, return the right pointer because that is either the target index
or the smallest one that is larger than target which is where target should be.

C++

```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};
```

Python

```
class Solution:
    def searchInsert(self, nums: List[int], target: int):
        left = 0
        right = len(nums)
        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid
        return right
```
