### 557\. [Reverse Words in a String III](https://leetcode.com/problems/reverse-words-in-a-string-iii/)

Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
```
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
```

Note: In the string, each word is separated by single space and there will not be any extra space in the string.

#### Solution 1

C++

```
class Solution {
public:
    string reverseWords(string s) {
        int last = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') continue;
            reverse(s.begin() + last, s.begin() + i);
            last = i + 1;
        }
        reverse(s.begin() + last, s.end());
        return s;
    }
};
```
