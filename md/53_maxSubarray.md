### 53\. [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)

Given an integer array nums, find the contiguous subarray 
(containing at least one number) which has the largest sum 
and return its sum.

Example:
```
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```

Follow up:

If you have figured out the O(n) solution, try coding 
another solution using  the divide and conquer approach, 
which is more subtle.


#### Solution 1

DP Time: O(n) Space O(1)

Maintain a current solution, curSum, and an overall solution, res.
Loop the array. For each element, either add it to the current solution,
or replace the current solution with it and then compare the current
solution with the overall solution. The reason is this. If the current
solution is negative, then certainly discard the current solution and
replace it with whatever the current element is. If the current solution
is positive, then include the current element. As long as the current element 
does not flip the sign of the current solution, we should keep it because
later we may see a positive number and since the current solution is still
positive, we can safely add the current solution with a positive number.
If you wander why we discard the whole solution if it is negative. Can't we 
discard a part of the solution. The reason is that if we need to discard
a part of the solution, then we should have already discard that part before 
even going forward from there. An example: [-3 -4 2 3]. If the current 
solution is -3 -4 + 2 = -5 and we include 3 and discard -3 and -4, making 
the solution 2 + 3 = 5. Then, when we met 2, we have already discard 
the then solution -7, and use 2 as the current solution.

C++

```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0, res = INT_MIN;
        for (int num : nums) {
            curSum = max(curSum + num, num);
            res = max(curSum, res);
        }
        return res;
    }
};
```

Python

```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        curSum = 0
        res = float('-inf')
        for num in nums:
            curSum = max(curSum + num, num)
            res = max(curSum, res)
        return int(res)
```

#### Solution 2

DP Time: O(n) Space O(n)

This is the same solution with the previous one except we store 
all the current solutions in an array, which is unnecessary...

C++

```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int res = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = nums[i] + (dp[i-1] > 0 ? dp[i-1] : 0);
            res = max(res, dp[i]);
        }
        return res;
    }
};
```

Python

```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        curSum = [nums[0] for i in range(len(nums))]
        res = curSum[0]
        for i in range(1, len(nums)):
            curSum[i] = max(curSum[i-1] + nums[i], nums[i])
            res = max(curSum[i], res)
        return res
```

#### Solution 3

Divide and conquer Time: O(nlogn)? Space O(1)

The problem also asks for a divide-and-conquer solution.
The main idea is to divide the array into left and right.
Compute the max of the left and the right AND also compute 
a max starting from the mid and expending to left and right.
In this way, we cover all the cases: given a mid, we find 
1) the max of the subarray to its left;
2) the max of the subarray to its right; 
3) the max of the subarray that crosses the mid.

C++

```
class Solution{
public:
    int maxSubArray_helper(vector<int>& nums, int left, int right) {
        if (left >= right) return nums[left];
        int mid = left + (right-left)/2;
        // max of left and right
        int lmax = maxSubArray3_helper(nums, left, mid-1),
            rmax = maxSubArray3_helper(nums, mid+1, right);

        // max of mid
        int mmax = nums[mid], curSum = mmax;
        for (int i = mid-1; i >= left; i--) {
            curSum += nums[i];
            mmax = max(mmax, curSum);
        }
        curSum = mmax;
        for (int i = mid+1; i <= right; i++) {
            curSum = nums[i];
            mmax = max(mmax, curSum);
        }

        // return max of max's
        return max(mmax, max(lmax, rmax));
    }

    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        return maxSubArray3_helper(nums, 0, (int)nums.size()-1);
    }
};

```

Python

```
To be filled
```
