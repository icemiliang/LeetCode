### 227\. [Basic Calculator II](https://leetcode.com/problems/basic-calculator-ii/)

Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, \+, \-, \*, \/ operators and empty spaces . The integer division should truncate toward zero.

Example 1:
```
Input: "3+2*2"
Output: 7
```

Example 2:
```
Input: " 3/2 "
Output: 1
```

Example 3:
```
Input: " 3+5 / 2 "
Output: 5
```

Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.

#### Solution 1

C++

```
class Solution {
public:
    int calculate(string s) {
        long res = 0, curRes = 0, num = 0, n = s.size();
        char op = '+';
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                num = num * 10 + c - '0';
            }
            if (c == '+' || c == '-' || c == '*' || c == '/' || i == n - 1) {
                switch (op) {
                    case '+': curRes += num; break;
                    case '-': curRes -= num; break;
                    case '*': curRes *= num; break;
                    case '/': curRes /= num; break;
                }
                if (c == '+' || c == '-' || i == n - 1) {
                    res += curRes;
                    curRes = 0;
                }
                op = c;
                num = 0;
            } 
        }
        return res;
    }
};
```

#### Solution 2

using a stack

C++

```
class Solution {
public:
    int calculate(string s) {
        int res = 0, num = 0, curRes = 0, n = s.size();
        char op = '+';
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c >= '0' and c <= '9') {
                num = num * 10 + (c - '0');
            }
            if (c == '+' or c == '-' or c == '*' or c == '/' or i == n - 1) {
                switch (op) {
                    case '+': curRes += num; break;
                    case '-': curRes -= num; break;
                    case '*': curRes *= num; break;
                    case '/': curRes /= num; break;
                }
                if (c == '+' or c == '-' or i == n - 1) {
                    res += curRes;
                    curRes = 0;
                }
                op = c;
                num = 0;
            }
        }
        return res;
    }
};
```

