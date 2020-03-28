### 844\. [Backspace String Compare](https://leetcode.com/problems/backspace-string-compare/)

Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:
```
Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
```

Example 2:
```
Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
```

Example 3:
```
Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
```

Example 4:
```
Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
```
Note:

1. 1 <= S.length <= 200
2. 1 <= T.length <= 200
3. S and T only contain lowercase letters and '#' characters.

Follow up:

Can you solve it in O(N) time and O(1) space?

#### Solution 1

Execute the backspace and see what the resulting string is.

Time: O(m + n) 
Space: O(m + n)

C++

```
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return helper(S) == helper(T);
    }
    
    string helper(string S) {
        string res = "";
        for (char c : S) {
            if (c == '#') {
                if (!res.empty()) res.pop_back();
            }
            else {
                res.push_back(c);
            }
        }
        return res;
    }
};
```

C++

```
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s = "", t = "";
        for (char c : S) {
            if (c == '#') {
                if (!s.empty()) s.pop_back();
            }
            else s.push_back(c);
        }
        for (char c : T) {
            if (c == '#') {
                if (!t.empty()) t.pop_back();
            }
            else t.push_back(c);
        }
        return s == t;
    }
};
```


#### Solution 2

Two pointers. Use two counters for number of backspaces.
Scan strings from the back. If '#' then counter++; if not '#' but counter not zero then counter--.
It means delete the char. If not '#' and counter zero, then compare two chars from two strings.
If not equal, return false. Finally, see if both pointers reach the head.

Time: O(m + n) 
Space: O(1)

C++

```
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size() - 1;
        int j = T.size() - 1;
        int cntS = 0;
        int cntT = 0;
        while (i >= 0 and j >= 0) {
            while (i >= 0 and (S[i] == '#' or cntS > 0)) S[i--] == '#' ? cntS++ : cntS--;
            while (j >= 0 and (T[j] == '#' or cntT > 0)) T[j--] == '#' ? cntT++ : cntT--;
            if (i < 0 or j < 0) return i == j;
            if (S[i--] != T[j--]) return false;
        }
        return i == j;
    }
};
```

