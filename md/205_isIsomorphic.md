### 205\. [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/)

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Example 1:
```
Input: s = "egg", t = "add"
Output: true
```

Example 2:
```
Input: s = "foo", t = "bar"
Output: false
```

Example 3:
```
Input: s = "paper", t = "title"
Output: true
```

Note:
You may assume both s and t have the same length.


#### Solution 1

Use two hashmaps each for a string. 
They map the current char to its last seen position (+1).

```
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> m1, m2;
        for (int i = 0; i < s.size(); i++) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};
```
