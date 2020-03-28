### 233\. [Number of Digit One](https://leetcode.com/problems/number-of-digit-one/)

Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

Example:
```
Input: 13
Output: 6 
Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
```

#### Solution 1

C++

```
class Solution {
public:
    int countDigitOne(int n) {
        long res = 0, a = 1, b = 1;
        while (n > 0) {
            res += (n + 8) / 10 * a + (n % 10 == 1) * b;
            b += n % 10 * a;
            a *= 10;
            n /= 10;
        }
        return int(res);
    }
};
```

#### Solution 2

C++

```
class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        for (long k = 1; k <= n; k *= 10) {
            long r = n / k, m = n % k;
            res += (r + 8) / 10 * k + (r % 10 == 1 ? m + 1 : 0);
        }
        return res;
    }
};
```
