### 140\. [Word Break II](https://leetcode.com/problems/word-break-ii/)

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:
```
Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
```

Example 2:
```
Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
```

Example 3:
```
Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]
```

#### Solution 1

C++

```
class Solution {
    unordered_map<int, vector<string>> memo;
    unordered_set<string> dict;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        memo[s.size()] = {""};
        return dfs(s, 0);
    }
    
    vector<string> dfs(string& s, int i) {
        if (!memo.count(i))
            for (int j = i + 1; j <= s.size(); ++j)
                if (dict.count(s.substr(i, j - i)))
                    for (string tail : dfs(s, j))
                        memo[i].push_back(s.substr(i, j - i) + (tail == "" ? "" : ' ' + tail));
        return memo[i];
    };
};
```


#### Solution 2

dp n^3
dfs n^3

C++

```
// // 1. dp
// // time: O(n^3)
// // space: O(n^3)

// class Solution {
// public:
//     vector<string> wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> dict(wordDict.begin(), wordDict.end());
//         vector<vector<string>> dp(s.size()+1, vector<string>());
//         dp[0].push_back("");
        
//         for(int i = 1; i <= s.size(); i++){
//             for(int j = 0; j < i; j++){
//                 if(dp[j].size() > 0 && dict.find(s.substr(j, i-j)) != dict.end()){
//                     string temp = s.substr(j, i-j);
//                     for(string ele : dp[j]){
//                         dp[i].push_back(ele+ (ele.empty()? "" : " ") +temp);
//                     }
//                 }
//             }
//         }
        
//         return dp[s.size()];
//     }
// };



// 2. dfs memo
// time: O(n^3)
// space: O(n^3)

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;
        
        
        vector<string> res = dfs(0, "", s, memo, dict);
        
//         for(vector<string> ele : memo){
//             for(string s : ele){
//                 cout << s << " ";
//             }
//             cout << endl;
            
//         }
        
        return res;
    }
    
    vector<string> dfs(int idx, string temp, string& s, unordered_map<int, vector<string>>& memo, unordered_set<string>& dict){
        
        if(memo.find(idx) != memo.end()){
            return memo[idx];
        }
        if(idx >= s.size()){
            return vector<string>({""});
        }
        

        
        for(int i = idx; i < s.size(); i++){
            // cout << i << endl;
            temp += s[i];
            if(dict.find(temp) != dict.end() ){
                // cout << temp << endl;
                vector<string> tempRes = dfs(i+1, "", s, memo, dict);
                for(string ele : tempRes){
                    memo[idx].push_back(temp + (ele.empty()? "" : " ") + ele);
                }
            }
            
        }
        
        return memo[idx];
        
    }
    
    
};
```
