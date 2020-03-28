### 139\. [Word Break](https://leetcode.com/problems/word-break/)

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.

Example 1:
```
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
```

Example 2:
```
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
```

Example 3:
```
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
```

#### Solution 1

DP

dp[i]: string until i is breakable?
dp[i] is breakable if dp[j] is breakable and s[j:i] is in dict.

C++

```
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        if(dict.empty()) return false;
        vector<bool> dp(s.size() + 1, false);
        dp.front() = true;
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (dp[j]) {
                    if (dict.count(s.substr(j, i - j))) {
                        dp[i] = true;
                        break; //next i
                    }
                }
            }
        }
        return dp.back();  
    }
};
```

Another DP logic: 

dp[j] is breakable if dp[i] is breakable and s[i:j] is in dict.

```
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        s = "!" + s;
        vector<bool> dp(s.size(), false);
        dp[0] = true;
        for (int i = 0; i < s.size(); ++i){
            for (int j = i + 1; j < s.size(); ++j) {
                if (dp[j]) continue;
                if (dict.count(s.substr(i + 1, j - i)) and dp[i]) {
                    dp[j] = true;
                }  
            }
        }
        return dp.back();
    }
};
```

#### Solution 2

DFS + memory

C++

```
class Solution {
    unordered_set<string> dict;
    vector<int> memo;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        memo.resize(s.size(), -1);
        return check(s, 0);
    }

    bool check(string& s, int i) {
        if (i >= s.size()) return true;
        if (memo[i] != -1) return memo[i];
        for (int j = i + 1; j <= s.size(); ++j) {
            if (dict.count(s.substr(i, j - i)) and check(s, i)) {
                return memo[i] = 1; // breakable
            }
        }
        return memo[i] = 0; // unbreakable
    }
};
```
