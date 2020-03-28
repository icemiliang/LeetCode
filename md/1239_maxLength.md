#### 1239\. [Maximum Length of a Concatenated String with Unique Characters](https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/)

Given an array of strings arr. String s is a concatenation of a sub-sequence of arr which have unique characters.

Return the maximum possible length of s.

Example 1:
```
Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All possible concatenations are "","un","iq","ue","uniq" and "ique".
Maximum length is 4.
```

Example 2:
```
Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible solutions are "chaers" and "acters".
```

Example 3:
```
Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
```

Constraints:

* 1 <= arr.length <= 16
* 1 <= arr[i].length <= 26
* arr[i] contains only lower case English letters.

#### Solution 1

DP + Backtrack

C++

```
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> dp = {bitset<26>()};
        int res = 0;
        for (auto& s : arr) {
            bitset<26> tmp;
            for (auto& c : s) tmp.set(c - 'a');
            // if duplicate chars, skip
            if (tmp.count() < s.size()) continue;
            
            for (int i = dp.size() - 1; i >= 0; --i) {
                if ((dp[i] & tmp).any()) continue;
                dp.push_back(dp[i] | tmp);
                res = max(res, (int)dp.back().count());
            }
        }
        return res;
    }
};
```


#### Solution 2

DFS + Backtrack

C++

```
class Solution {
public:
    int maxLength(vector<string>& arr) {
        return dfs(arr, "", 0);
    }
    
    int dfs(vector<string>& arr, string str, int index) {
	    //Use set to check if the string contains all unique characters
        unordered_set<char>s(str.begin(), str.end());
        if (s.size() != ((int)str.length())) 
            return 0;
        
        int res = str.length();
        for (int i = index; i < arr.size(); i++)
            res = max(res, dfs(arr, str+arr[i], i+1));

        return res;
    }
};
```
