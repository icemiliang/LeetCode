### 376\. [Wiggle Subsequence](https://leetcode.com/problems/wiggle-subsequence/)

A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.

For example, ```[1,7,4,9,2,5]``` is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, ```[1,4,7,2,5]``` and ```[1,7,4,5,5]``` are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.

Example 1:
```
Input: [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence.
```
Example 2:
```
Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
Explanation: There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
```
Example 3:
```
Input: [1,2,3,4,5,6,7,8,9]
Output: 2
```
Follow up:
Can you do it in O(n) time?

#### Solution 1

dp1: second > first
dp2: second < first

C++

```
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        vector<int> dp1(nums.size(), 1);
        vector<int> dp2(nums.size(), 1);
        for (int i = 1; i <nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) dp1[i] = max(dp1[i], dp2[j] + 1);
                if (nums[j] > nums[i]) dp2[i] = max(dp2[i], dp1[j] + 1);
            }
        }
        return max(dp1.back(), dp2.back());
    }
};
```

#### Solution 2

Greedy

C++

```
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int dp1 = 1;
        int dp2 = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) dp1 = dp2 + 1;
            if (nums[i] > nums[i - 1]) dp2 = dp1 + 1;
        }
        return max(dp1, dp2);
    }
};
```
