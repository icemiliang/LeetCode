### 387\. [First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string/)

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:
```
s = "leetcode"
return 0.
```
```
s = "loveleetcode",
return 2.
```

Note: You may assume the string contain only lowercase letters.


#### Solution 1

Use a 26-element array to count the char frequencies.
Count the requencies of all chars in the string.
Loop from the begining again and return the first char 
that appeared once.

```
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c-'a']++;
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
```

Store both frequency and last index to avoid scaning the string twice.

```
class Solution {
public:
    int firstUniqChar(string s) {
        vector< pair<int, int>> freq_idx(26, {0, -1});
        for (int i = 0; i < s.size(); i++) {
            freq_idx[s[i] - 'a'].first++;
            freq_idx[s[i] - 'a'].second = i;
        }
        int res = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (freq_idx[i].first == 1) res = min(res, freq_idx[i].second);
        }
        return res == INT_MAX ? -1 : res;
    }
};
```
