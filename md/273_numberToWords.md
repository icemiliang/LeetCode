### 273\. [Integer to English Words](https://leetcode.com/problems/integer-to-english-words/)

Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

Example 1:
```
Input: 123
Output: "One Hundred Twenty Three"
```

Example 2:
```
Input: 12345
Output: "Twelve Thousand Three Hundred Forty Five"
```

Example 3:
```
Input: 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
```

Example 4:
```
Input: 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
```

#### Solution 1

C++

```
class Solution {
    vector<string> v1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> v2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> v = {"Thousand", "Million", "Billion"};
public:
    string numberToWords(int num) {
        string res = convertHundred(num % 1000);
        for (int i = 0; i < 3; ++i) {
            num /= 1000;
            res = num % 1000 ? convertHundred(num % 1000) + " " + v[i] + " " + res : res;
        }
        while (res.back() == ' ') res.pop_back();
        return res.empty() ? "Zero" : res;
    }
    string convertHundred(int num) {
        string res;
        int a = num / 100, b = num % 100, c = num % 10;
        res = b < 20 ? v1[b] : v2[b / 10] + (c ? " " + v1[c] : "");
        if (a > 0) res = v1[a] + " Hundred" + (b ? " " + res : "");
        return res;
    }
};
```
