### 132\. [Palindrome Partitioning II](https://leetcode.com/problems/palindrome-partitioning-ii/)

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example:
```
Input: "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
```

#### Solution 1

[https://www.cnblogs.com/grandyang/p/4271456.html](https://www.cnblogs.com/grandyang/p/4271456.html)

C++

```
class Solution {
public:
    int minCut(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<vector<bool>> p(n, vector<bool>(n));
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = i;
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (i - j < 2 || p[j + 1][i - 1])) {
                    p[j][i] = true;
                    dp[i] = (j == 0) ? 0 : min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[n - 1];
    }
};
```


#### Solution 2

C++

```
class Solution {
public:
    int minCut(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = -1;
        for (int i = 0; i < n; ++i) {
            for (int len = 0; i - len >= 0 && i + len < n && s[i - len] == s[i + len]; ++len) {
                dp[i + len + 1] = min(dp[i + len + 1], 1 + dp[i - len]);
            }
            for (int len = 0; i - len >= 0 && i + len + 1 < n && s[i - len] == s[i + len + 1]; ++len) {
                dp[i + len + 2] = min(dp[i + len + 2], 1 + dp[i - len]);
            }
        }
        return dp[n];
    }
};
```
