### 541\. [Reverse String II](https://leetcode.com/problems/reverse-string-ii/)

Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.

Example:
```
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
```
Restrictions:
```
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]
```

#### Solution 1

We can follow the description to write the algorithm. We loop the string from the begining. At each time, reverse k characters and then skip 2k characters. If there are less than k characters remaining, reverse all of them.

C++

```
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            // reverse(s.begin() + i, min(s.begin() + i + k, s.end()));
            int left = i;
            int right = min(i + k - 1, int(s.size())-1);
            while (left < right) {
                swap(s[left++], s[right--]);
            }
        }
        return s;
    }
};
```

Python

```
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
		if k >= len(s):
            return s[::-1]
        s = list(s)
        for i in range(0, len(a), 2 * k):
            a[i:i+k] = a[i:i+k][::-1]
        return "".join(s)
```

