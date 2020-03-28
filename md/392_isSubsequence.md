### 392\. [Is Subsequence](https://leetcode.com/problems/is-subsequence/)

Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length \~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
```
s = "abc", t = "ahbgdc"

Return true.
```

Example 2:
```
s = "axc", t = "ahbgdc"

Return false.
```
Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

#### Solution 1

Two pointers.

C++

```
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (int j = 0; j < t.size(); j++) {
            if (t[j] == s[i]) i++;
        }
        if (i < s.size()) return false;
        return true;
    }
};
```

#### Solution 2

C++

```
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pre = -1;
        unordered_map<char, vector<int>> char2pos;
        for (int i = 0; i < t.size(); i++) {
            char2pos[t[i]].push_back(i);
        }
        for (char c : s) {
            // find a c in t that has a bigger pos than pre which is the pos of last found char.
            auto it = upper_bound(char2pos[c].begin(), char2pos[c].end(), pre);
            if (it == char2pos[c].end()) return false;
            pre = *it;
        }
        return true;
    }
};
```
