### 125\. [Valid Palindrome](https://leetcode.com/problems/valid-palindrome)

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.
```
Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
```
```
Example 2:

Input: "race a car"
Output: false
```

common blocks
```
bool equal(char c1, char c2) {
    if (c1 == c2) return true;
    if (c1-'a' == c2-'A' && c1-'a' >= 0 && c1-'z' <= 0) return true;
    if (c1-'A' == c2-'a' && c1-'A' >= 0 && c1-'Z' <= 0) return true;
    return false;
}


```

#### Solution 1

The idea is simple. We keep a left pointer and right pointer from two ends moving toward
each other. If the current character is not a alphanumeric one, skip it. Then, if the 
left character is not equal to the right character, return false. One thing to notice 
when comparing the characters is that the alphabetic character could be in uppercase
or lowercase. We can conver it to lowercase first before comparing. Or we can directly
compare left and right in three cases: 1) left = right 2) left lowercase = right uppercase
3) left uppercase = right lowercase. BUT, there is an exaception because
 -17 = 0 - 'A' == 'P' - 'a'. Thus, we have to be more specific like I will show in the code.

Time: O(n)

Space: O(1)

C++

```
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while (left < right) {
            if (!isalnum(s[left])) { left++; continue; }
            if (!isalnum(s[right])) { right--; continue; }
            if (!equal(s[left++], s[right--])) return false;
        }
        return true;
    }
    
    bool equal(char c1, char c2) {
        if (c1 == c2) return true;
        if (c1-'a' == c2-'A' && c1-'a' >= 0 && c1-'z' <= 0) return true;
        if (c1-'A' == c2-'a' && c1-'A' >= 0 && c1-'Z' <= 0) return true;
        return false;
    }
};
```

A more concise solution.

```
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (!isalnum(s[left])) { ++left; continue; }
            if (!isalnum(s[right])) { --right; continue; }
            if (tolower(s[left++]) != tolower(s[right--])) return false;
        }
        return true;
    }
};
```

Python

```
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        left = 0
        right = len(s) - 1
        while left < right:
            if not s[left].isalnum():
                left += 1
            elif not s[right].isalnum():
                right -= 1
            elif s[left] != s[right]:
                return False
            else:
                left += 1
                right -= 1
        return True
```

#### Solution 2

Using recursion is also a solution but that will exceed the time limit. The idea is the
same as Solution 1 except that we recursively check if the substring is a Palindrome.
We need to copy many times during recursion in this way.

C++

```
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() < 2) return true;
        int left = 0, right = s.size()-1;
        while (left < right and !isalnum(s[left])) left++;
        while (left < right and !isalnum(s[right])) right--;
        if (tolower(s[left]) != tolower(s[right])) return false;
        return isPalindrome(s.substr(left+1, right-left-1));
    }   
};
```

Python

```
class Solution:
    def isPalindrome(self, s: str) -> bool:

        def helper(s: str) -> bool:
            if len(s) < 2:
                return True
            left = 0
            right = len(s) - 1
            while left < right and not s[left].isalnum():
                left += 1
            while left < right and not s[right].isalnum():
                right -= 1
            if s[left] != s[right]:
                return False
            return helper(s[left+1: right])

        s = s.lower()
        return helper(s)
```
