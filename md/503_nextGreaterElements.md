### 503\. [Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/)

Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:

Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.

Note: The length of given array won't exceed 10000. 

#### Solution 1

C++

```

```

#### Solution 2

Use a stack to store the indices for which we will find the next greater number.
A single for loop is the current number we will compare with for the top
of the stack.

C++

```
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(nums.size(), -1);
        stack<int> todo;
        for (int i = 0; i < n * 2; i++) {
            int num = nums[i % n];
            while (!todo.empty() and nums[todo.top()] < num) {
                res[todo.top()] = num; todo.pop();
            }
            if (i < n) todo.push(i);
        }
        return res;
    }
};
```
