### 20\. [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:
```
Input: "()"
Output: true
```
Example 2:
```
Input: "()[]{}"
Output: true
```
Example 3:
```
Input: "(]"
Output: false
```
Example 4:
```
Input: "([)]"
Output: false
```
Example 5:
```
Input: "{[]}"
Output: true
```
#### Solution 1

The strategy is simple: 

Use a stack to store examined chars. Loop the string. 
If the current char is a left, push it into the stack.
If not, which means a right, check the stack. If it is empty,
or its top is not a left, return false because a right must be 
coupled with a left immediately before that. Don't push a right
into the stack, instead pop out the top. Finally, check if
the stack is empty which means some le

C++

```
class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		for (char c : s) {
			if (c == '(' or c == '{' or c == '[') {
				st.push(c);
			}
			else {
				if (st.empty()) return false;
				if (c == ')' && st.top() != '(') return false;
				if (c == '}' && st.top() != '{') return false;
				if (c == ']' && st.top() != '[') return false;
				st.pop();
			}
		}
		return st.size() == 0;
	}
};
```