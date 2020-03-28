### 357\. [Count Numbers with Unique Digits](https://leetcode.com/problems/count-numbers-with-unique-digits/)

Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:
```
Input: 2
Output: 91 
Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, 
             excluding 11,22,33,44,55,66,77,88,99
```

#### Solution 1

C++

```
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int res = 0;
        vector<int> fac(11);
        fac[0] = 1;
        for (int i = 1; i <= 10; i++) fac[i] = fac[i - 1] * i;
        int total = fac[10] - fac[9];
        while (n > 0) {
            res += total / fac[10 - n];
            n--;
        }
        return res + 1;
    }
};
```

#### Solution 2

C+=

```
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int res = 10, cnt = 9;
        for (int i = 2; i <= n; i++) {
            cnt *= (11 - i);
            res += cnt;
        }
        return res;
    }
};
```
