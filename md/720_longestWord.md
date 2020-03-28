### 720\. [Longest Word in Dictionary](https://leetcode.com/problems/longest-word-in-dictionary/)

Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character at a time by other words in words. If there is more than one possible answer, return the longest word with the smallest lexicographical order.

If there is no answer, return the empty string.

Example 1:
```
Input: 
words = ["w","wo","wor","worl", "world"]

Output: "world"

Explanation: 
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
```

Example 2:
```
Input: 
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]

Output: "apple"

Explanation: 
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
```

Note:

All the strings in the input will only contain lowercase letters.
The length of words will be in the range [1, 1000].
The length of words[i] will be in the range [1, 30].


#### Solution 1

Sort words. Starting from the first word, if its size is 1, and bigger than 
res's size, replace res with word. If the word, last char removed, is in the set
and its size is bigger than res's size, replace res with it. Add the word into the set.

C++

```
class Solution {
public:
    string longestWord(vector<string>& words) {
        string res = "";
        unordered_set<string> dict;
        sort(words.begin(),words.end());
        for (string word : words) {
            if (word.size() == 1 || dict.count(word.substr(0,word.size()-1))) {
                if (res.size() < word.size()) {
                    res = word;
                }
                dict.insert(word);
            }
        }
        return res;
    }
};
```


#### Solution 2.1

BFS.
Build a set of all the words. 
Build a queue from all the eligible words, starting with those whose size are 1.
Examine the top word in the queue. If word's size < res's size, replace res with word.
If sizes are equal, whichever is smaller wins. 
Add each of a-z to word's back. If new word is in the set, push it into the queue.

C++

```
class Solution {
public:
    string longestWord(vector<string>& words) {
        string res = ""; 
        unordered_set<string> dict;
        queue<string> todo;
        for (string word : words) {
            dict.insert(word);
            if (word.size() == 1) todo.push(word);
        }
        while (!todo.empty()) {
            auto t = todo.front(); q.pop();
            if (t.size() > res.size()) res = t;
            else if (t.size() == res.size()) {
                if (t < res) res = t;
            }
            t.push_back('a');
            for (int i = 0 ; i < 26; i++) {
                t.back() = i + 'a';
                if (dict.count(t)) todo.push(t);
            }
        }
        return res;
    }
};
```

#### Solution 2.2

DFS.
Build a set of all the words from the vector. 
Start from single chars. Add each of a-z to the back.
If the new word is in the set, continue add chars.
If word's size < res's size, replace res with word.
If sizes are equal, whichever is smaller wins.

C++

```
class Solution {
public:
    void dfs(string& res, string word, unordered_set<string>& s) {
        if (word.size() > res.size()) res = word;
        else if (word.size() == res.size()) {
            if (word < res) res = word;
        }
        for (int i = 0; i < 26; i++) {
            word.push_back(i+'a');
            if (s.find(word) != s.end()) dfs(res,word,s);
            word.pop_back();
        }
    }
    string longestWord(vector<string>& words) {
        string res = "";
        unordered_set<string> dict(words.begin(),words.end());
        for (string word : words) {
            if (word.size() == 1) dfs(res, word, dict);
        }
        return res;
    }
};
```
