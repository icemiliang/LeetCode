### 49\. [Group Anagrams](https://leetcode.com/problems/group-anagrams/)

Given an array of strings, group anagrams together.

Example:
```
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
```
Note:

* All inputs will be in lowercase.
* The order of your output does not matter.

#### Solution 1

hashmap

The basic idea is a unique key for all anagrams. Three ways to define key.
1. sorted anagrams
2. char frequencies as strings
3. prime number products

C++

```
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (string str : strs) {
            string t = str;
            sort(t.begin(), t.end());
            m[t].push_back(str);
        }

        vector<vector<string>> res;
        for (auto& it : m) {
            res.push_back(it.second);
        }
        return res;
    }
};
```

C++

```
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (string& str : strs) {
            int count[26] = {0};
            string t = ""; // key
            for (char c : str) count[c - 'a']++;
            for (int i : count) t += to_string(i) + "/";
            m[t].push_back(str);
        }   

        vector<vector<string>> res;
        for (auto& it : m) {
            res.push_back(it.second);
        }
        return res;
    }
};
```

C++

```
class Solution {
public:
    int primes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<long,vector<string>> m;
        vector<vector<string>> res;
        for (string str : strs) {
            long key = 1;
            for (char c : str) key *= primes[c - 'a'];
            m[key].push_back(str);
        }
        for (auto it : m) {
            res.push_back(it.second);
        }
        return res;
    }
};
```
