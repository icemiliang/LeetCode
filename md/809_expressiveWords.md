### 809\. [Expressive Words](https://leetcode.com/problems/expressive-words/)

Sometimes people repeat letters to represent extra feeling, such as "hello" -> "heeellooo", "hi" -> "hiiii".  In these strings like "heeellooo", we have groups of adjacent letters that are all the same:  "h", "eee", "ll", "ooo".

For some given string S, a query word is stretchy if it can be made to be equal to S by any number of applications of the following extension operation: choose a group consisting of characters c, and add some number of characters c to the group so that the size of the group is 3 or more.

For example, starting with "hello", we could do an extension on the group "o" to get "hellooo", but we cannot get "helloo" since the group "oo" has size less than 3.  Also, we could do another extension like "ll" -> "lllll" to get "helllllooo".  If S = "helllllooo", then the query word "hello" would be stretchy because of these two extension operations: query = "hello" -> "hellooo" -> "helllllooo" = S.

Given a list of query words, return the number of words that are stretchy. 

Example:
```
Input: 
S = "heeellooo"
words = ["hello", "hi", "helo"]
Output: 1
Explanation: 
We can extend "e" and "o" in the word "hello" to get "heeellooo".
We can't extend "helo" to get "heeellooo" because the group "ll" is not size 3 or more.
```

Notes:

* 0 <= len(S) <= 100.
* 0 <= len(words) <= 100.
* 0 <= len(words[i]) <= 100.
* S and all words in words consist only of lowercase letters

#### Solution 1

C++

```
class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int res = 0;
        for (string& word : words) {
            int i = 0, j = 0;
            while (i < S.size()) {
                // same elements
                if (j < word.size() and S[i] == word[j]) {
                    j++;
                    i++;
                    continue;
                }
                // The first time elements do not equal e.g. he[e]ellooo and he[l]lo
                // S prev should be equal to S cur and S next
                if (i != 0 and S[i] == S[i - 1] and i != S.size() - 1 and S[i] == S[i + 1]) {
                    i += 2;
                    continue;
                }
                // If not the above two cases, it must be the tail or otherwise do not match
                if (i > 1 and S[i] == S[i - 1] and S[i] == S[i - 2]) i++;
                else break;
            }
            if (i == S.size() and j == word.size()) res++;
        }
        return res;
    }
};
```

