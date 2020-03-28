### 438\. [Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/)

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:
```
Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
```

Example 2:
```
Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
```

#### Solution 1

Record the char frequency of p with a 26-elemnet array. Keep a sliding window 
of the size of p on s. Starting from the begining, check if the chars in the window
have the same frequencies as in p. Store the true indices in the return array.

C++

```
class Solution {
public:
    bool isEqual(int cnt_s[], int cnt_p[]) {
        for (int i = 0; i < 26; i++) {
            if (cnt_s[i] != cnt_p[i]) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        if (s.empty() or p.empty() or m < n) return {};
        int cnt_s[26] = {0}, cnt_p[26] = {0};
        for (char c : p) ++cnt_p[c - 'a'];
        for (int i = 0; i < n; i++) ++cnt_s[s[i] - 'a'];

        vector<int> res;
        if (isEqual(cnt_s, cnt_p)) res.push_back(0);
        for (int i = 0; i < m - n; i++) {
            --cnt_s[s[i] - 'a'];
            ++cnt_s[s[i + n] - 'a'];
            if (isEqual(cnt_s, cnt_p)) res.push_back(i + 1);
        }
        return res;
    }
};
```
