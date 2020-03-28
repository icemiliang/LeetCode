### 287\. [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/)

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:
```
Input: [1,3,4,2,2]
Output: 2
```

Example 2:
```
Input: [3,1,3,4,2]
Output: 3
```

Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

#### Solution 1

Constant O(1) extra space means we cannot use a hashmap. Complexity should be less
than O(n^2) which is also a clue. It means our algorithm should run in less than
O(n^2) but also not too smaller than O(n^2). The most common one is O(nlog(n)).
When we consider a O(nlog(n)) algorithm, it is likely to have a sort in it. If 
we sort the array using O(nlog(n)) and then use less than O(nlog(n)) to finish
the algorithm, then we are done. One straightforward solution is sort the array
and loop it from the begining to the end and find if the current element is equal
to the previous element.

C++

```
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) return nums[i];
        }
        return 0;
    }
};
```

Python

```
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        nums.sort()
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1]:
                return nums[i]
        return 0
```

#### Solution 2

Certainly, after the sort, we can use binary search to solve it. This 
solution only uses the classic binary search algorithm with no modification.
We have covered it in other problems. Will skip the detail.

C++

```
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > mid) left = mid + 1;
            else right = mid;
        }
        return nums[right];
    }
};
```

Python

```
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        nums.sort()
        left = 0
        right = len(nums)
        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] > mid:
                left = mid + 1
            else:
                right = mid
        return nums[right]
```
