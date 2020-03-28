### 5\. [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:
```
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
```

Example 2:
```
Input: "cbbd"
Output: "bb"
```

#### Solution 1

One way to check palindromes is to start from a middle point and use two pointers expanding
to left and right and check if left == right. Panlindromes can have an odd or an even number of 
characters. If it has an odd number of characters, left and right pointers start from the same
character; if it has an even number of characters, left and right pointers start from two adjacent
characters.

C++

```
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        int start = 0, maxLen = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            helper(s, i, i, start, maxLen);
            helper(s, i, i + 1, start, maxLen);
        }
        return s.substr(start, maxLen);
    }
    
    void helper(string& s, int left, int right, int& start, int& maxLen) {
        while (left >= 0 and right < s.size() and s[left] == s[right]) {
                left--;
                right++;
        }
        if (right - left - 1 > maxLen) {
            maxLen = right - left - 1;
            start = left + 1;
        }
    }
};
```

Python

```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        def helper(s: str, left: int, right: int, start: int, maxLen: int):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            if right - left - 1 > maxLen:
                maxLen = right - left - 1
                start = left + 1
            return start, maxLen
        
        if len(s) < 2:
            return s
        maxLen = 0
        start = 0
        for i in range(len(s) - 1):
            start, maxLen = helper(s, i, i, start, maxLen)
            start, maxLen = helper(s, i, i + 1, start, maxLen)
        return s[start : start + maxLen]
    
```
