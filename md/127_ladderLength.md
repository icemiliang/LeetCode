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
```
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
```

Example 2:
```
Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
```

#### Solution 1

BFS.
Maintain a queue of current words. For each round of transformation, examine all the words
in the queue. For each word, change its every char to another one from a to z. At the same time,
maintain a set of words. If the new word after transformation is in the word set, push the word 
into the queue and delete the word from the word set. After each round of transformation, res++.

```
class Solution{
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(), wordList.end());
		if (!dict.count(endWord)) return 0;
		queue<string> todo{{beginWord}};
		int res = 0;
		while (!todo.empty()) {
			for (int i = todo.size(); i > 0; i--) {
				string t = todo.front(); todo.pop();
				for (int j = 0; j < t.size(); j++) {
					string newWord = t;
					for (char c = 'a'; c <= 'z'; c++) {
						newWord[j] = c;
						if (newWord == endWord) return res + 1;
						if (dict.count(newWord) && newWord != t) {
							todo.push(newWord);
							dict.erase(newWord);
						}
					}
				}
			}
			res++;
		}
		return 0;
}
};
```
