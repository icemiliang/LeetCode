### 242\. [Valid Anagram](https://leetcode.com/problems/valid-anagram/)

Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:
```
Input: s = "anagram", t = "nagaram"
Output: true
```
Example 2:
```
Input: s = "rat", t = "car"
Output: false
```
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?


#### Solution 1

One hashmap recording the frequency of each of 26 char in s.
Loop over t. Each time minus by 1 the frequency of the current char.
Because the sizes are equal, if frequency doesn't match for a char,
that char or one of another char's frequency must be < 0.


Time: O(N)
Space: O(N)

C++

```
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> freq;
        int n = s.size();
        for (int i = 0; i < n; i++) freq[s[i]]++;
        for (int i = 0; i < n; i++) {
            if (--freq[t[i]] < 0) return false;
        }
        return true;
    }
};
```


Two hashmaps each for a string, recording the char frequency.
Loop over the maps, if frequencies don't match, return false.

C++

```
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> freqS;
        unordered_map<char, int> freqT;
        int n = s.size();
        for (int i = 0; i < n; i++) freqS[s[i]]++;
        for (int i = 0; i < n; i++) freqT[t[i]]++;
        for (auto t : freqS) {
            if (freqT[t.first] != t.second) return false;
        }
        return true;
    }
};
```

#### Solution 2

Sort

Time: O(NlogN)
Space: O(1)

C++

```
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) return false;
        }
        return true;
    }
};
```
