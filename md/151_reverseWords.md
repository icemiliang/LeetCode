### 151\. [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/)

Given an input string, reverse the string word by word.\

Example 1:
```
Input: "the sky is blue"
Output: "blue is sky the"
```

Example 2:
```
Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
```

Example 3:
```
Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
```

Note:

* A word is defined as a sequence of non-space characters.
* Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
* You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Follow up:

For C programmers, try to solve it in-place in O(1) extra space.

#### Solution 1

The main idea is reverse the whole string and then reverse each word separately.
The trick is that there might be multiple whitespaces in a row.
Three pointers. A 'last' pointer to record the index of the last filled char.
A 'cur' pointer to the latest char examined in the string.
'i' is pointing to the first char of each word.
Remember to add a space after each word and remove the last space in the end.

C++

```
class Solution {
public:
    string reverseWords(string s) {
        int last = 0, n = s.size();
        reverse(s.begin(), s.end());
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') continue;
            int cur = i;
            while (cur < n && s[cur] != ' ') s[last++] = s[cur++];
            reverse(s.begin() + last - (cur - i), s.begin() + last);
            s[last++] = ' ';
            i = cur;
        }
        s.resize(last);
        if (s.back() == ' ') s.pop_back();
        return s;
    }
};
```

#### Solution 2

Not in place.

C++

```
class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string tmp;
        istringstream ss(s);
        while (ss >> tmp) {
            res = tmp + " " + res;
        }
        res.pop_back();
        return res;
    }
};
```
