### 784\. [Letter Case Permutation](https://leetcode.com/problems/letter-case-permutation/)

Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
```
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
```

Note:

* S will be a string with length between 1 and 12.
* S will consist only of letters or digits.

#### Solution 1

C++

```
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res = {""};
        for (char c : S) {
            if (c >= '0' and c <= '9') {
                for (auto& v : res) {
                    v.push_back(c);
                }
            }
            else {
                for (int i = res.size() - 1; i >= 0; --i) {
                    string t = res[i];
                    t.push_back(tolower(c));
                    res.push_back(t);
                    res[i] += toupper(c);
                }
            }
        }
        return res;
    }
};
```

Another implementation. 
Copy original string and use an iterator to avoid pushing back.

```
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res = {S};
        for (int i = 0; i < S.size(); ++i) {
        	char c = S[i];
            if (c < '0' or c > '9') {
                for (int j = res.size() - 1; j >= 0; --j) {
                    string t = res[j];
                    t[i] = tolower(c);
                    res.push_back(t);
                    res[j][i] = toupper(c);
                }
            }
        }
        return res;
    }
};
```

Further clean code.

```
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res = {S};
        for (int i = 0; i < S.size(); ++i) {
        	char c = S[i];
            if (c < '0' or c > '9') {
                for (int j = res.size() - 1; j >= 0; --j) {
                    string t = res[j];
                    t[i] = islower(c) ? toupper(c) : tolower(c);
                    res.push_back(t);
                }
            }
        }
        return res;
    }
};
```

#### Solution 2, 3

https://www.cnblogs.com/grandyang/p/9065702.html
