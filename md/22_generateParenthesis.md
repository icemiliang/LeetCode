### 22\. [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/submissions/)

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:
```
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
```

#### Solution 1

Recursion is a good way to find all possible solutions. We build the solution from an empty string.
Each time, we add a left or right bracket to the string. If we have added n left brackets and n
right brackets, then we push the string to the result. For the string to be valid, the number of right 
brackets must be equal to or smaller than the left brackets. Otherwise, we abort the current search.
We can use two varibles to record how many bracktes we can add to the current string and substract it
by 1 each time we go the the next recusion.

C++

```
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(n, n, "", res);
        return res;
    }
    
    void dfs(int left, int right, string out, vector<string>& res) {
        if (left > right) return;
        if (left == 0 and right == 0)  {
            res.push_back(out);
            return;   
        }
        if (left > 0) dfs(left - 1, right, out + "(", res);
        if (right > 0) dfs(left, right - 1, out + ")", res);
    }
};
```

Python

```
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def dfs(left, right, out, res):
            if left > right:
                return
            if left == 0 and right == 0:
                res.append(out)
            if left > 0:
                dfs(left - 1, right, out + "(", res)
            if right > 0:
                dfs(left, right - 1, out + ")", res)
        res = [];
        dfs(n, n, "", res)
        return res
        
```
