### 1170\. [Compare Strings by Frequency of the Smallest Character](https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/)

Let's define a function f(s) over a non-empty string s, which calculates the frequency of the smallest character in s. For example, if s = "dcce" then f(s) = 2 because the smallest character is "c" and its frequency is 2.

Now, given string arrays queries and words, return an integer array answer, where each answer[i] is the number of words such that f(queries[i]) < f(W), where W is a word in words.

Example 1:
```
Input: queries = ["cbd"], words = ["zaaaz"]
Output: [1]
Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").
```
Example 2:
```
Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
Output: [1,2]
Explanation: On the first query only f("bbb") < f("aaaa"). On the second query both f("aaa") and f("aaaa") are both > f("cc").
```

Constraints:

* 1 <= queries.length <= 2000
* 1 <= words.length <= 2000
* 1 <= queries[i].length, words[i].length <= 10
* queries[i][j], words[i][j] are English lowercase letters.

#### Solution 1

Follow the question.

C++

```
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> freqs(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            freqs[i] = f(words[i]);
        }
        
        vector<int> res(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++) {
            int a = f(queries[i]);
            int cnt = 0;
            for (int j = 0; j < freqs.size(); j++) {
                if (a < freqs[j]) cnt++;
            }
            res[i] = cnt;
        }
        return res;
    }
    
    int f(string word) {
        int freq[26] = {0};
        for (char c : word) freq[c - 'a']++;
        
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) return freq[i];
        }
        return -1;
    }
};
```

Compute the accumulative frequency beforehand to remove the inner for loop.

```
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> freqs(11, 0);
        for (int i = 0; i < words.size(); i++) {
            int a = f(words[i]);
            freqs[a]++;
        }

        for (int i = freqs.size() - 1; i > 0; i--) {
            freqs[i - 1] += freqs[i];
        }

        vector<int> res(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++) {
            int a = f(queries[i]);
            if (a < 10) res[i] = freqs[a + 1];
        }
        return res;
    }
    
    int f(string word) {
        int freq[26] = {0};
        for (char c : word) freq[c - 'a']++;
        
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) return freq[i];
        }
        return -1;
    }
};
```