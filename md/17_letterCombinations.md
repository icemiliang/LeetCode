### 17\. [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

Given a string containing digits from 2-9 inclusive, return all 
possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) 
is given below. Note that 1 does not map to any letters.

![alt text](200px-Telephone-keypad2.svg.png)

Example:
```
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
```
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.


#### Solution 1
Cartesian product.

Maintain a vector of string storing temporary result. Loop the digits.
For each new digit, we add the corresponding letters to the current result,
that is, for each combination in the current result, push back the corresponding
letter respectively. Then, replace the old result with the new result. The essential
idea of this process is called backtracking. The new result is built upon the orld
result and once we have the new result, we discard the old one because the old one
does not satisfy the requirement.

```
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.empty()) return {};
		string dict[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		vector<string> res = {""};
		for (char digit : digits) {
			vector<string> tmp;
			for (string comb :res) {
				for (char c : dict[digit - '0']) {
					tmp.push_back(comb + c);
				}
			}
			res = tmp;
		}
		return res;
	}
}
```
