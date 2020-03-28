### 168\. [Excel Sheet Column Title](https://leetcode.com/problems/excel-sheet-column-title/)

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:
```
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
```

Example 1:
```
Input: 1
Output: "A"
```

Example 2:
```
Input: 28
Output: "AB"
```
Example 3:
```
Input: 701
Output: "ZY"
```

#### Solution 1

C++

```
class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while (n) {
            int tmp = n % 26;
            if (tmp == 0) res.push_back('Z');
            else res.push_back('A' - 1 + tmp);
            n /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```
