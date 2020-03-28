### 91\. [Decode Ways](https://leetcode.com/problems/decode-ways/)

A message containing letters from A-Z is being encoded to numbers using the following mapping:
```
'A' -> 1
'B' -> 2
...
'Z' -> 26
```
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:
```
Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
```
Example 2:
```
Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
```

#### Solution 1

DP

dp[i]: # of ways
dp[i] = dp[i - 1] // decode current number alone
dp[i] += dp[i - 2] // combine the previous number 

C++

```
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() or s[0] == '0') return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); i++) {
            if (i < s.size() and s[i] == '0' and s[i - 1] > '2') return 0;
            if (s[i - 1] != '0') dp[i] += dp[i - 1]; // parse single number
            if ((i > 1 and s[i - 2] == '1') or (i > 1 and s[i - 2] == '2' and s[i - 1] <= '6')) {
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }
};
```

We only need to keep the last twp dp elements.

```
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() or s[0] == '0') return 0;
        int dp1, dp2 = 1;
        for (int i = 1; i <= s.size(); i++) {
            if (i < s.size() and s[i] == '0' and s[i - 1] > '2') return 0;
            int dp3 = s[i - 1] == '0' ? 0 : dp2;
            if ((i > 1 and s[i - 2] == '1') or (i > 1 and s[i - 2] == '2' and s[i - 1] <= '6')) {
                dp3 += dp1;
            }
            dp1 = dp2;
            dp2 = dp3;
        }
        return dp2;
    }
};
```

#### Solution 2

C++

```
class Solution {
public:
    int numDecodings(string s) {
        return s.empty() ? 0 : dfs(0, s);    
    }
    int dfs(int p, string& s) {
        int n = s.size();
        if (p == n) return 1;
        if (s[p] == '0') return 0;
        int res = dfs(p + 1, s);
        if (p < n - 1 and (s[p] == '1' or (s[p] == '2' and s[p + 1] < '7'))) res += dfs(p + 2, s);
        return res;
    }
};
```
