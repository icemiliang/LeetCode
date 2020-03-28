### 217\. [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)

Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:
```
Input: [1,2,3,1]
Output: true
```
Example 2:
```
Input: [1,2,3,4]
Output: false
```
Example 3:
```
Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
```

#### Solution 1

Since the array is not sorted, we have to use a hashset to store
seen numbers and if a number is already in the set, return true.
If no such number is found, return false at the end.

time: O(n), space: O(n)

C++

```
class Solution {
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (s.count(nums[i])) {
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};
```

Python

```
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        dict = set()
        for num in nums:
            if num in dict:
                return True
            dict.add(num)
        return False
```

#### Solution 2

A trick that we can use is that if the array does have duplicates, then
there are a smaller number of unique numbers than the size of the array.
Thus, we build a hashset with the array and check if their sizes equal.

time: O(n), space: O(n)

C++

```
class Solution {
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        return s.size() != nums.size();
    }
};
```

Python

```
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(nums) != len(set(nums))
```

#### Solution 3

If the array is sorted, then we do not need to record all seen numbers.
We only need to compare adjacent numbers to see if they equal. Thus,
we can sort the array first, and then check for duplicates.

time: O(nlogn), space: O(1)

C++

```
class Solution {
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                return true;
            }
        }
        return false;
    }
};
```

Python

```
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        nums = sorted(nums)
        for i in range(1, len(nums)):
            if (nums[i - 1] == nums[i]) return True
        return False
```
