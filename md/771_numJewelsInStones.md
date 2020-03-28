### 771\. [Jewels and Stones](https://leetcode.com/problems/jewels-and-stones/)

You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:
```
Input: J = "aA", S = "aAAbbbb"
Output: 3
```

Example 2:
```
Input: J = "z", S = "ZZ"
Output: 0
```

Note:

* S and J will consist of letters and have length at most 50.
* The characters in J are distinct.

#### Solution 1

C++

```
class Solution {
public:
	int numJewelsInStones(string J, string S) {
		bool dict[256] = {false};
		for (char c : J) dict[c] = true;
		int cnt = 0;
		for (char c : S) if (dict[c]) ++cnt;
		return cnt;
	}
};
```

C++

```
class Solution {
public:
	int numJewelsInStones(string J, string S) {
		unordered_set<char> jewels;
		for (char c : J) jewels.insert(c);
		int cnt = 0;
		for (char c : S) if (jewels.count(c)) ++cnt;
		return cnt;
	}
};
```
