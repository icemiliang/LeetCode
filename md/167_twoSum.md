### 167\. [Two Sum II - Input array is sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.

Example:
```
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
```
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

#### Solution 1

Different from the previous two sum problem, in this problem, the array is sorted.
Thus, we can use binary search to find the difference which is target minus current
element. Previously, we have to store seen numbers in a hash set. To solve this
problem, we loop the array and for each number find its complement in the rest of
the array.

Time: O(nlog(n)), Space: O(1)

C++

```
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size() - 1; i++) {
            int diff = target - numbers[i];
            int left = i + 1;
            int right = numbers.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (numbers[mid] == diff) return {i + 1, mid + 1};
                if (numbers[mid] < diff) left = mid + 1;
                else right = mid - 1;
            }
        }
        return {};
    }
};

```

Python

```
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> int:
        for i in range(len(numbers)-1):
            diff = target - numbers[i]
            left = i + 1
            right = len(numbers) - 1
            while left <= right:
                mid = left + (right - left) // 2
                if numbers[mid] == diff:
                    return [i + 1, mid + 1]
                if numbers[mid] < diff:
                    left = mid + 1
                else:
                    right = mid - 1
        return []
```


#### Solution 2

This problem actually has a better solution that runs on O(n). We just
need to maintain two pointers one from left one from right. If the left
and the right don't add up to the target, if the summation is smaller
move left forward; if it is larger move right backward.

Time: O(n). Each element is visited at most once.
Space: O(n)

C++

```
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] == target) return {left, right};
            if (numbers[left] + numbers[right] < target) left++;
            else right--;
        }
        return {};
    }
};
```

Python

```
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left, right = 0, len(numbers) - 1
        while left < right:
            sum = numbers[left] + numbers[right]
            if sum == target:
                return [left + 1, right + 1]
            if sum < target:
                left += 1
            else:
                right -= 1
        return []
```
