### 29\. [Divide Two Integers](https://leetcode.com/problems/divide-two-integers/)

Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:
```
Input: dividend = 10, divisor = 3
Output: 3
```

Example 2:
```
Input: dividend = 7, divisor = -3
Output: -2
```

Note:

* Both dividend and divisor will be 32-bit signed integers.
* The divisor will never be 0.
* Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.


#### Solution 1

C++

```
class Solution {
public:
    int divide(int dividend, int divisor) {
        long m = abs((long)dividend), n = abs((long)divisor), res = 0;
        while (m >= n) {
            long t = n;
            int p = 1;
            while (m > (t << 1)) {
                t = t << 1;
                p = p << 1;
            }
            res += p;
            m -= t;
        }
        if ((dividend < 0) ^ (divisor < 0)) res = -res;
        if (res > INT_MAX) res = INT_MAX;
        return res;
    }
};
```


#### Solution 2

C++

```
class Solution {
public:
    int divide(int dividend, int divisor) {
        long m = abs((long)dividend), n = abs((long)divisor);
        if (m < n) return 0;
        long t = n;
        int p = 1;
        while (m > (t << 1)) {
            t = t << 1;
            p = p << 1;
        }
        long res = p + (long)divide(m - t, n);
        if ((dividend < 0) ^ (divisor < 0)) res = -res;
        if (res > INT_MAX) res = INT_MAX;
        return res;
    }
};
```
