### 1048\. [Longest String Chain](https://leetcode.com/problems/longest-string-chain/)

Given a list of words, each word consists of English lowercase letters.

Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.  For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

Return the longest possible length of a word chain with words chosen from the given list of words.

 

Example 1:
```
Input: ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: one of the longest word chain is "a","ba","bda","bdca".
```

Note:

1. 1 <= words.length <= 1000
2. 1 <= words[i].length <= 16
3. words[i] only consists of English lowercase letters.

#### Solution 1

C++

```
class Solution {
    static bool compare(const string& s1, const string& s2) {
        return s1.size() < s2.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare); // shortest word comes first
        unordered_map<string, int> dp; // longest chain until the word
        int allMax = 0;
        for (string w : words) {
            int curMax = 0;
            // remove one char, dp[old] = max(dp[new] + 1)
            for (int i = 0; i < w.size(); i++) {
                string word = w.substr(0, i) + w.substr(i + 1);
                curMax = max(curMax, dp[word] + 1);
            }
            dp[w] = curMax;
            allMax = max(allMax, curMax);
        }
        return allMax;
    }
};
```


#### Solution 2

C++

```
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        if (words.size() < 2) return words.size();

        sort(words.begin(),words.end(),[](const string& l, const string& r) { return l.size() > r.size(); });
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < words.size(); i++) mp[words[i].size()].push_back(i);
        
        vector<int> dp(words.size(), 1); // dp[0] = 1; max at i
        for(int i = 0; i < words.size(); i++){
            auto it = mp.find(words[i].size() + 1);
            if (it == mp.end()) continue;         
            for(int index : it->second){
                // cout<<words[i]<<" -> "<<words[index]<<' ';
                if(isPre(words[i], words[index])){
                    // cout<<'!'<<'\n';
                    // cout<<words[i]<<' '<<words[index]<<'\n';
                    dp[i] = max(dp[i], dp[index] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
    
    bool isPre(const string& pre, const string& post){
        if(pre.empty())return true;
        
        bool diff = false;
        for(int i = 0; i < pre.size(); i++){
            if (pre[i] == post[i + diff]) continue;
			else if (diff) return false;
            else {
                if(pre[i] != post[i + 1]) return false;
                diff = true;
            }
        }
        return true;
    }
};
```
