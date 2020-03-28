### 28\. [Implement strStr()](https://leetcode.com/problems/implement-strstr/)

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
```
Input: haystack = "hello", needle = "ll"
Output: 2
```
Example 2:
```
Input: haystack = "aaaaa", needle = "bba"
Output: -1
```
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().


#### Solution 1

I haven't found a way to do it other than by brute force. 
Loop the haystack and at each index find if the following chars 
up to the size of needle match the needle. Immediately return 
the current index if so and continue for the next index if not.
Return 0 if the size of the needle. Return -1 if no such index found.

```
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		int m = haystack.size(), n = needle.size(), diff = m - n;
		for (int i = 0; i <= m - n; ++i) {
			int j = 0;
			for (; j < n; ++j) {
				if (haystack[i + j] != needle[j]) break;
			}
			if (j == n) return i;
		}
		return -1;
	}
};
```
