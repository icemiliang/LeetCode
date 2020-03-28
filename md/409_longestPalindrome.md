### 409\. [Longest Palindrome](https://leetcode.com/problems/longest-palindrome/)

Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:
```
Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
```

#### Solution 1

Use a hashmap to count the frequency of each seen char. Then loop over the hashmap
and add up all the frequencies. A palindrome can have one and only one char that 
appears for odd times. Thus, if a char in the hashmap is seen for odd times,
add the frequency minus one and, if the sum is even meaning no odd frequency char 
has been checked, add one to sum to allow one more char for the middle of the palindrome.

C++

```
class Solution {
public:
	int longestPalindrome(string s) {
		unordered_map<char, int> m;
		for (char c : s) m[c]++;
		int res = 0;
		for (auto it : m) {
			if (it.second % 2 == 0) res += it.second;
			else {
				res += it.second-1;
				if (res % 2 == 0) res++;
			}
		}
		return res;
	}
};
```

Use a 256-element array to replace the hashmap in solution 1.

C++

```
class Solution {
public:
	int longestPalindrome(string s) {
		int cnt[256] = {0};
		for (char c : s) cnt[c]++;
		int res = 0;
		for (int i = 0; i < 256; i++) {
			if (cnt[i] % 2 == 0) res += cnt[i];
			else {
				res += cnt[i]-1;
				if (res % 2 == 0) res++;
			}
		}
		return res;
	}
};
```
