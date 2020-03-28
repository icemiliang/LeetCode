### 1\. [Two Sum](https://leetcode.com/problems/two-sum/)


Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```

#### Solution 1

Hashmap, Two loops

One solution to this problem is to loop the array from the begining to the end and record each number
as we see it. Then, for each new number, we check if we can find a seen number that is the difference
we need to make the target number. This problem asks use to return the indices of the numbers, so, we 
have use a hashmap to store all the numbers and their indices. Otherwise we can use a set to store
those seen numbers.

We first loop the whole array and record every number and their indices. Then, we start from the begining.
For example, if the target is 9 and the current number is 2, then all we need is to find 7 in the hashmap.
If the hashmap has 7, return the indices of 2 and 7. If it doen't have 7, continue the search. This 
problem doesn't require the order of the indices to be ascending or decending, but if it does, we can always
tell which index is smaller.

C++

```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for (int i = 0; i < nums.size(); i++) 
            m[nums[i]] = i;
        
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (m.count(diff) && m[diff]!= i) {
                return {i, m[diff]};
            }
        }

        return {};
    }
};
```

Python 
```
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict = {}
        for i in range(len(nums)):
            dict[nums[i]] = i
        for i in range(len(nums)):
            diff = target - nums[i]
            if dict.get(diff) is not None and dict.get(diff) != i:
                return [dict.get(diff), i]
        return []
```

#### Solution 2

Hashmap, one loop

We can also loop the array only once to find the combination. We still need a hashmap, but each time 
before we add a number and its index to the hashmap, we check if we can find the difference in the 
hashmap. Even if the difference does exist in the array but is not seen yet, we can still add the 
current number to the hashmap and later when we pass that difference we will then find the current 
number in the hashmap. In this way, we can also avoid re-using the same element because we check 
the hashmap before we add a new element into the hashmap.

C++

```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (m.count(diff)) {
                return {m[diff], i};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};
```

Python 

```
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict = {}
        for i in range(len(nums)):
            diff = target - nums[i]
            if dict.get(diff) is not None:
                return {dict.get(diff), i}
            dict[nums[i]] = i
        return []
```

#### Solution 3 

Brute force

Of course, we can brute-forcely compute the summation of each two elements and then return 
the their indices if the summation equals the target. This will increase the running time 
from O(n) to O($n^2$), but it also only use constant space O(1) instead of O(n) from the 
previous two solutions that use hashmaps.

C++

```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size()-1; i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] == target - nums[i]) {
                return {i,j};
            }
        }
    }
    return {};
    }
};
```

Python

```
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)-1):
            for j in range(i + 1, len(nums)):
                if nums[j] + nums[i] == target:
                    return [i, j]
        return []
```
