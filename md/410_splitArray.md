### 410\. [Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/)

Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.

Note:
If n is the length of array, assume the following constraints are satisfied:

* 1 ≤ n ≤ 1000
* 1 ≤ m ≤ min(50, n)

Examples:
```
Input:
nums = [7,2,5,10,8]
m = 2

Output:
18

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
```

#### Solution 1

Binary Search.

If m = 1, then sum is the total of the array. If m = nums.size(), then, sum
is the maximum number. Thus, sum must be between max and total. Use binary search
to find upperbound of sum that induces m subarrays.

C++

```
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long low = 0, high = 0;

        // find low which is max, and high which is total
        for (int num : nums) {
            if (num > low) low = num;
            high += num;
        }
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (!canSplit(nums, m, mid)) low = mid + 1; // mid is too small
            else high = mid; // mid is too large
        }
        return high;
    }
    
    bool canSplit(vector<int>& nums, int m, long sum) {
        int cnt = 1;
        long curSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            curSum += nums[i];
            if (curSum > sum) {
                curSum = nums[i];
                cnt++;
                if (cnt > m) return false;
            }
        }
        return true;
    }
};
```

#### Solution 2

DP

C++

```

```
