### 472\. [Concatenated Words](https://leetcode.com/problems/concatenated-words/)

Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.
A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

Example:
```
Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
```

Note:
1. The number of elements of the given array will not exceed 10,000
2. The length sum of elements in the given array will not exceed 600,000.
3. All the input string will only include lower case letters.
4. The returned elements order does not matter.

#### Solution 1

Sort the words first according to their length. We have two rules. One is that
concatenated words must have at least twice the length of the shortest word.
The other one is that concatenated can be divided into at least two words.
The first word has at least the minimum length. The last word also has the
minimum length.

C++

```
class Solution {
    vector<string> res;
    unordered_set<string> dict;
    int len;
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& s1, const string& s2) { return s1.size() < s2.size(); });
        while (!words.empty() and words.front() == "") words.erase(words.begin());
        len = words.front().size();
        
        for (string& word : words) {
            if (word.size() >= 2 * len and isCon(word)) {
                res.push_back(word);
            }
            dict.insert(word);
        }
        return res;
    }
    
    bool isCon(string const & word) {
        if (dict.count(word)) return true;
        for (int i = len; i < word.size() - len + 1; ++i) {
            if (dict.count(word.substr(0, i)) and isCon(word.substr(i))) {
                return true;
            }
        }
        return false;
    }
};
```
