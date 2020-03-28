### 1002\. [Find Common Characters](https://leetcode.com/problems/find-common-characters/)

Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.

 

Example 1:
```
Input: ["bella","label","roller"]
Output: ["e","l","l"]
```
Example 2:
```
Input: ["cool","lock","cook"]
Output: ["c","o"]
 ```

Note:

1. 1 <= A.length <= 100
2. 1 <= A[i].length <= 100
3. A[i][j] is a lowercase letter

#### Solution 1

There seems not a more efficient way than brute force. We need to scan the input,
for each string compute the frequency of each character. Then, for each new string,
we update the frequency array.

C++

```
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> cnt(26, INT_MAX);
        for (string a : A) {
            int freq[26] = {0};
            for (char c : a) freq[c-'a']++;
            for (int i = 0; i < 26; i++) {
                cnt[i] = min(cnt[i], freq[i]);
            }
        }
        
        vector<string> res;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                res.push_back(string(1, i + 'a'));
            }
        }
        return res;
    }
};
```

