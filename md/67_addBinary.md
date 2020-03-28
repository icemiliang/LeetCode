### 67\. [Add Binary](https://leetcode.com/problems/add-binary/)

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:
```
Input: a = "11", b = "1"
Output: "100"
```

Example 2:
```
Input: a = "1010", b = "1011"
Output: "10101"
```

#### Solution 1

C++

```
class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string res = "";
        int i = a.size() - 1, j = b.size() - 1;
        while (i >=0 or j >= 0) {
            if (i >= 0) carry += a[i--] - '0';
            if (j >= 0) carry += b[j--] - '0';
            res.insert(res.begin(), '0' + carry % 2);
            carry /= 2;
        }
        if (carry) res.insert(res.begin(), '1');
        return res;
    }
};
```

A different version

```
class Solution {
public:
    string addBinary(string a, string b) {
        string ret = "";
        int carry = 0;
        for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j--) {
            int m = (i >= 0 && a[i] == '1');
            int n = (j >= 0 && b[j] == '1');
            ret = to_string((m + n + carry) & 0x1) + ret;
            carry = (m + n + carry) >> 1;
        }
        return carry ? '1' + ret : ret;
    }
};
```
