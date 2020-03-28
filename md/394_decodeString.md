### 394\. [Decode String](https://leetcode.com/problems/decode-string/)

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:
```
s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
```

#### Solution 1

Iteration

C++

```
class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<int> todo_num;
        stack<string> todo_char;
        int num = 0;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (isalpha(c)) {
                res.push_back(c);
            }
            else if (c == '[') {
                todo_num.push(num);
                num = 0;
                todo_char.push(res);
                res = "";
            }
            else if (c == ']') {
                int k = todo_num.top(); todo_num.pop();
                string tmp = res;
                for (int i = 0; i < k - 1; ++i) {
                    res += tmp;
                }
                res = todo_char.top() + res; todo_char.pop();
            }
        }
        return res;
    }
};
```

#### Solution 2

Recursion.

Start a new string for each left '['. Return current result when hitting ']'.

C++

```
class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return dfs(s, i);
    }
    
    string dfs(string& s, int& i) {
        string res = "";
        // if see a closing ']' return the current string
        while (i < s.size() and s[i] != ']') {
            // if it is not a digit it must be a letter 
            // because we will skip any opening '[''
            if (!isdigit(s[i])) {
                res += s[i++];
            }
            else {
                int num = 0;
                while (isdigit(s[i])) {
                    num = num * 10 + (s[i++] - '0');
                }
                ++i; // skip '['
                // start a new string right after a '['
                string t = dfs(s, i);
                ++i; // skip ']'
                while (num-- > 0) {
                    res += t;
                }
            }
        }
        return res;
    }
};
```
