### 819\. [Most Common Word](https://leetcode.com/problems/most-common-word/)

Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.
 

Example:
```
Input: 
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]

Output: "ball"

Explanation: 
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.
```

Note:

* 1 <= paragraph.length <= 1000.
* 0 <= banned.length <= 100.
* 1 <= banned[i].length <= 10.
* The answer is unique, and written in lowercase (even if its occurrences in paragraph may have uppercase symbols, and even if it is a proper noun.)
* paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
* There are no hyphens or hyphenated words.
* Words only consist of letters, never apostrophes or other punctuation symbols.

#### Solution 1

The idea is to build a set out of the banned words and a hashmap to record frequency.
Then, loop the paragraph, if the current string is not a banned word, frequency + 1.
In the end, loop the hashmap to find the most frequent word. Don't forget to remove 
punctuation symbols from the paragraph first, and to convert each char to the lowercase.

C++

```
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> banDict(banned.begin(), banned.end());
        unordered_map<string, int> freq;
        string tmp;
        
        for (auto& ch : paragraph) {
            ch = isalpha(ch) ? tolower(ch) : ' ';
        }
        
        istringstream is(paragraph);
        while (is >> tmp) {
            if (banDict.count(tmp) == 0) freq[tmp]++;
        }
        
        int high = 0;
        string res = "";
        for (auto a : freq) {
            if (a.second > high) {
                res = a.first;
                high = a.second;
            }
        }
        return res;
    }
};
```

Python has some built-in functions that can simplify the code.

Python

```
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        banDict = set(banned)
        freq = {}
        for c in "!?',;.":
            paragraph = paragraph.replace(c, " ")
        for word in paragraph.lower().split():
            if not word in banDict:
                if not word in freq:
                    freq[word] = 1
                else:
                    freq[word] += 1
        
        return max(freq, key=freq.get)
    

```
