### 224\. [Basic Calculator](https://leetcode.com/problems/basic-calculator/)

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

Example 1:
```
Input: "1 + 1"
Output: 2
```
Example 2:
```
Input: " 2-1 + 2 "
Output: 3
```
Example 3:
```
Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23
```
Note:
* You may assume that the given expression is always valid.
* Do not use the eval built-in library function.

#### Solution 1

Stack the signs according to parentheses.

C++

```
class Solution {
public:
    int calculate(string s) {
        int sum = 0;
        stack<int> signs;
        int sign = 1;
        signs.push(sign);
        int Sign = signs.top();
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(') {
                signs.push(signs.top() * sign);
                sign = 1;
            }
            else if (c == ')') signs.pop();
            else if (c == '+') sign = 1;
            else if (c == '-') sign = -1;
            else if (s[i] >= '0' and s[i] <= '9'){
                int num = 0;
                while (i < s.size() and s[i] >= '0' and s[i] <= '9') {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                sum += sign * num * signs.top();
            }
        }
        return sum;
    }
};
```

A more concise version.

```
class Solution {
public:
    int calculate(string s) {
        stack<int> st({1});
        int sum = 0;
        int num = 0;
        int sign = 1;
        for (char c : s) {
            if (c >= '0' and c <= '9') {
                num = num * 10 + (c - '0');
            }
            else {
                sum += num * sign * st.top();
                num = 0;
                if (c == '+') sign = 1;
                if (c == '-') sign = -1;
                if (c == ')') st.pop();
                if (c == '(') {
                    st.push(st.top() * sign);
                    sign = 1;
                }
            }
        }
        sum += num * sign * st.top();
        return sum;
    }
};
```
