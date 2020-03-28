### 953\. [Verifying an Alien Dictionary](https://leetcode.com/problems/verifying-an-alien-dictionary/)

In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.

 

Example 1:
```
Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
```

Example 2:
```
Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
```

Example 3:
```
Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
```

Constraints:

* 1 <= words.length <= 100
* 1 <= words[i].length <= 20
* order.length == 26
* All characters in words[i] and order are English lowercase letters.

#### Solution 1

Build a map from old order to new order. Check if words are sorted according to new order.

C++

```
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> m;
        for (int i = 0; i < order.size(); ++i) m[order[i]] = i;
        
        for (int i = 0; i < words.size() - 1; ++i) {
            int j = 0, k = 0;
            while (j < words[i].size() and k < words[i + 1].size()) {
                if (words[i][j] == words[i + 1][k]) {
                    ++j;
                    ++k;
                    continue;
                }
                if (m[words[i][j]] > m[words[i + 1][k]]) return false;
                else break;
            }
            if (words[i].size() > words[i + 1].size() and k == words[i + 1].size()) return false;
        }
        return true;
    }
};
```


#### Solution 2

Map the words from new order to old order and check if they are sorted.

C++

```
    bool isAlienSorted(vector<string> words, string order) {
        int mapping[26];
        for (int i = 0; i < 26; i++)
            mapping[order[i] - 'a'] = i;
        for (string &w : words)
            for (char &c : w)
                c = mapping[c - 'a'];
        return is_sorted(words.begin(), words.end());
    }
```
