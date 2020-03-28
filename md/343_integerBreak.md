### 343\. [Integer Break](https://leetcode.com/problems/integer-break/)

Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

Example 1:
```
Input: 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
```
Example 2:
```
Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
```
Note: You may assume that n is not less than 2 and not larger than 58.

#### Solution 1

3 x 3 = 9 > 8 = 2 x 2 x 2

Break the integer by 3 as many as possible until the remaining is 4 or less.

C++

```
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int res = 1;
        while (n > 4) {
            res *= 3;
            n -= 3;
        }
        return res * n;
        
    }
};
```

#### Solution 2

Three cases: 
1. dp[i] has been scanned.
2. break into two: j * (i - j) is bigger
3. break into three or more: j * dp[i - j] is bigger

C++

```
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 1);
        for (int i = 3; i <= n; i++) {
            for (int j = 2; j < i; j++) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp.back();
    }
};
```
