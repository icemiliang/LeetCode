### 290\. [Word Pattern](https://leetcode.com/problems/word-pattern/)

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:
```
Input: pattern = "abba", str = "dog cat cat dog"
Output: true
```

Example 2:
```
Input:pattern = "abba", str = "dog cat cat fish"
Output: false
```

Example 3:
```
Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
```

Example 4:
```
Input: pattern = "abba", str = "dog dog dog dog"
Output: false
```

Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.


#### Solution 1

one hashmap from string to char.
For seen string, check if hashed value equals current pattern char.
For unseen string, search for the current pattern char in the hashmap.
If found, then error.

C++

```
bool wordPattern(string pattern, string str) {
    unordered_map<char,string> m;
    istringstream in(str);
    int i = 0;
    for (string word; in >> word; i++) {
        if (m.find(pattern[i]) != m.end()) {
            if (m[pattern[i]] != word) return false;
        }
        else {
            // loop over the map and check if word already exists
            for (unordered_map<char,string>::iterator it = m.begin(); it != m.end(); it++) {
                if (it->second == word) return false;
            }
            m[pattern[i]] = word;
        }
    }
    return i == pattern.size();
}
```

#### Solution 2 

Two hashmaps for recording the last position of seen patterns and strings.
Build a stringstream out of the input string. Check each word of the stream
and each char of the pattern. If word stream not empty but pattern reaches end,
meaning number of chars smaller than number of words, return false.
If one is seen and the other is unseen, return false.
If both are seen but positions are different, return false;
Add current word and char to hashmaps if unseen.

C++

```
bool wordPattern(string pattern, string str) {
    unordered_map<char,int> m_pattern;
    unordered_map<string,int> m_str;
    int i = 0; // first seen index
    string word; // current string
    istringstream in(str);
    while (in >> word) {
        // if string size > pattern size return false
        if (i == pattern.size()) return false;
        // if seen pattern
        if (m_pattern.find(pattern[i]) != m_pattern.end()) {
            // if unseen string return false
            if (m_str.find(word) == m_str.end()) return false;
            // if indices don't match, return false
            if (m_str[word] != m_pattern[pattern[i]]) return false;
        }
        // if unseen pattern
        else {
            // if seen string, return false
            if (m_str.find(word) != m_str.end()) return false;
            // add first seen indices
            m_pattern[pattern[i]] = i;
            m_str[word] = i;
        }
        i++;
    }
    // if string size < pattern size return false
    return i == pattern.size();
}
```
#### Solution 3

A different style of solution 2.

C++

```
bool wordPattern(string pattern, string str) {
    unordered_map<char, int> m_p;
    unordered_map<string, int> m_s;
    int i = 0;
    string word;
    istringstream ss(str);
    while (ss >> word) {
        if (i == pattern.size()) return false;
        char c = pattern[i];
        if ((m_p.find(c) == m_p.end())^(m_s.find(word) == m_s.end())) return false;
        if (m_p.find(c) != m_p.end() and m_s.find(word) != m_s.end() 
                                     and m_p[c] != m_s[word]) {
            return false;
        }
        m_p[c] = i;
        m_s[word] = i;
        i++;
    }
    return i == pattern.size();
}
```
