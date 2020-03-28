### 3\. [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

Given a string, find the length of the longest substring without repeating characters.

Example 1:
```
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
```
Example 2:
```
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```
Example 3:
```
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

#### Solution 1

Maintain a substring. Loop over the input string. 
If the current char is in the substring, find its last position
and remove all the chars before it including it. 
Push back the current char in to the substring. Compare size with max.

Time: O(N^2) Space: O(N)

C++

```
int lengthOfLongestSubstring(string s) {
	int mxLen = 0;
	string str = "";
	int start = 0;
	for (char c : s) {
		int cur = str.find_last_of(c);
		if (cur != -1) str = str.substr(cur+1);
		str.push_back(c);
		if (str.size() > mxLen) mxLen = str.size();
	}
	return mxLen;
}
```

We can use a pointer to record the starting point of the substring that ends right before the current i.
And then start from the back to search for the char at i. If found, update the length if the current 
substring is longer and then bring the starting pointer to the next position. A corner case is that
the last char of the string is not in the last substring. In that case we need to update the length
again before quiting the outer for loop.

C++

Time: O(N^2) Space: O(1)

```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2) return s.size();
        int start = 0;
        int len = 1;
        for (int i = 1; i < s.size(); i++) {
            int j = i - 1;
            while (j >= start) {
                if (s[j] == s[i]) {
                    len = max(len, i - start);
                    start = j + 1;
                    break;
                }
                j--;
            }
            if (j == start - 1) {
                len = max(len, i - start + 1);
            }
        }
        return len;
    }
};
```
