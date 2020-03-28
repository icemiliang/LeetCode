### 415\. [Add Strings](https://leetcode.com/problems/add-strings/)

Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

1. The length of both num1 and num2 is < 5100.
2. Both num1 and num2 contains only digits 0-9.
3. Both num1 and num2 does not contain any leading zero.
4. You must not use any built-in BigInteger library or convert the inputs to integer directly.

#### Solution 1

C++

```
class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size() - 1;
        int n2 = num2.size() - 1;
        string res = string(max(n1, n2) + 2, '1');
        int carry = 0;
        int k = res.size() - 1;
        while (n1 >= 0 or n2 >= 0) {
            if (n1 >= 0) carry += num1[n1--] - '0';
            if (n2 >= 0) carry += num2[n2--] - '0';
            res[k--] = carry % 10 + '0';
            carry /= 10;
        }
        return carry == 1 ? res : res.substr(1);
    }
};
```
