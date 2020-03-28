### 772\. [Basic Calculator III](https://leetcode.com/problems/basic-calculator-iii/)

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

The expression string contains only non-negative integers, ```+```, ```-```, ```*```, ```/``` operators , open ( and closing parentheses ) and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647].

Some examples:
```
"1 + 1" = 2
" 6-4 / 2 " = 4
"2*(5+5*2)/3+(6/2+8)" = 21
"(2+6* 3+5- (3*14/7+2)*5)+3"=-12
```

Note: Do not use the eval built-in library function.

#### Solution 1

C++

```
class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return parseExpr(s, i);
    }
    
    int parseExpr(string& s, int& i) {
        vector<int> todo;
        char op = '+';
        for (; i < s.size() and op != ')'; ++i) {
            if (s[i] == ' ') continue;
            long num = s[i] == '(' ? parseExpr(s, ++i) : parseNum(s, i);
            switch(op) {
                case '+': todo.push_back(num); break;
                case '-': todo.push_back(-num); break;
                case '*': todo.back() *= num; break;
                case '/': todo.back() /= num; break;
            }
            if (i < s.size()) op = s[i];
        }
        return accumulate(todo.begin(), todo.end(), 0);
    }
    
    long parseNum(string& s, int& i) { // change to long to pass case like "0-2147483648"
        long n = 0;
        while(i < s.length() && isdigit(s[i]))
            n = s[i++] - '0' + 10 * n;
        return n;
    }
};
```
