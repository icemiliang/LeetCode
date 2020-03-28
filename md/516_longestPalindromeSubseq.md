### 516\. [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/)

Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
```
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
```

Example 2:
```
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
```


#### Solution 1

DP, 2D

C++

```
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
```

DP, 1D

```
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int res = 0;
        vector<int> dp(n, 1);
        for (int i = n - 1; i >= 0; i--) {
            int len = 0;
            for (int j = i + 1; j < n; j++) {
                int tmp = dp[j];
                if (s[i] == s[j]) {
                    dp[j] = len + 2;
                }
                len = max(len, tmp);
            }
        }
        for (int num : dp) res = max(res, num);
        return res;
    }
};
```
