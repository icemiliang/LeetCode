### 647\. [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/)

Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
```
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
```

Example 2:
```
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
```

Note:

1. The input string length won't exceed 1000.


#### Solution 1

C++

```
class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) return 0;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res += helper(s, i, i);
            res += helper(s, i, i + 1);
        }
        return res;
    }
    
    int helper(string& s, int i, int j) {
        int res = 0;
        while (i >= 0 and j < s.size() and s[i] == s[j]) {
            i--;
            j++;
            res++;
        }
        return res;
    }
};
```

#### Solution 2

DP

C++

dp\[j\]\[i\] from j to i

```
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), res = 0;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                dp[i][j] = (s[i] == s[j]) and (j - i <= 2 or dp[i + 1][j - 1]);
                if (dp[i][j]) res++;
            }
        }
        return res;
    }
};
```

dp\[i\]\[j\] from i to j

```
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), res = 0;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                dp[j][i] = (s[i] == s[j]) and (i - j <= 2 or dp[j + 1][i - 1]);
                if (dp[j][i]) res++;
            }
        }
        return res;
    }
};
```

