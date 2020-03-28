### 127\. [Word Ladder](https://leetcode.com/problems/word-ladder/)

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

#### Solution 1

This solution directly comes from [127 Word Ladder](https://leetcode.com/problems/word-ladder/). Instead of storeing 
the last string in the queue, we also need store the path in the queue. One thing that is different from 127 is
that we cannot immediately remove the new word from the set, because all the path that has the same length can 
still have this word. It is just the paths from that word are the same and they could all be a solution.
Thus, we have to keep this kind of words and remove them at the end of each iteration.

C++

```
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return {};
        queue<vector<string>> todo;
        todo.push({beginWord});
        vector<vector<string>> res;
        unordered_set<string> erase;
        bool found = false;
        while (!todo.empty()) {
            for (int k = todo.size() - 1; k >= 0; k--) {
                auto t = todo.front(); todo.pop();
                string lastWord = t.back();
                for (int i = 0; i < lastWord.size(); i++) {
                    string newWord = lastWord;
                    for (char c = 'a'; c <= 'z'; c++) {
                        newWord[i] = c;
                        if (newWord == lastWord) continue;
                        if (wordSet.count(newWord)) {
                            t.push_back(newWord);
                            todo.push(t);
                            erase.insert(newWord);
                            if (newWord == endWord) {
                                res.push_back(t);
                                found = true;
                            }
                            t.pop_back();
                        }
                    }
                }
            }
            
            for (string s : erase) {
                wordSet.erase(s);
            }
            
            if (found) break;
        }
        return res;
    }
};
```
