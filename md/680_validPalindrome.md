### 680\. [Valid Palindrome II]

Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
```
Input: "aba"
Output: True
```

Example 2:
```
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
```

Note:
1. The string will only contain lowercase characters a-z. The maximum length of the string is 50000.

#### Solution 1

Two pointers from start and end. If different chars, remove either and 
check if the rest of the string is a palindrome.

C++

```
class Solution {
public:
    bool validPalindrome(string s) {
        int lo = 0, hi = s.size() - 1;
        while (lo < hi) {
            if (s[lo] == s[hi]) { ++lo; --hi; }
            else {
                int lo1 = lo + 1, hi1 = hi;
                while (lo1 < hi1 and s[lo1] == s[hi1]) { ++lo1; --hi1; }
                if (lo1 >= hi1) return true;
                int lo2 = lo, hi2 = hi - 1;
                while (lo2 < hi2 and s[lo2] == s[hi2]) { ++lo2; --hi2; }
                if (lo2 >= hi2) return true;
                return false;
            }
        }
        return true;
    }
};
```
