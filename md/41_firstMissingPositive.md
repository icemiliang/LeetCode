### 41\. [First Missing Positive](https://leetcode.com/problems/first-missing-positive/)

Given an unsorted integer array, find the smallest missing positive integer.

Example 1:
```
Input: [1,2,0]
Output: 3
```
Example 2:
```
Input: [3,4,-1,1]
Output: 2
```
Example 3:
```
Input: [7,8,9,11,12]
Output: 1
```
Note:

Your algorithm should run in O(n) time and uses constant extra space.

#### Solution 1

https://leetcode.com/problems/first-missing-positive/discuss/17071/My-short-c%2B%2B-solution-O(1)-space-and-O(n)-time

Put each number in its right place. For example: When we find 5, then swap it with A[4]. 
At last, the first place where its number is not right, return the place + 1.


How did you prove that swap(A[i], A[A[i] - 1]) can complete in finite steps?
	A[A[i] - 1] != A[i] means that the right position for the current number (A[i]) is occupied with another number, that is, the position(A[i]-1) holds the wrong number. After swapping, we make sure that the position holds the right one. Before we modify the array, the number of positions that hold wrong number is at most n, and after each loop, we ascertain that another one is right.

Time: O(n)
Space: O(1)

C++

```
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 and nums[i] <= n and nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};
```
