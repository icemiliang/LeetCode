### 269\. [Alien Dictionary](https://leetcode.com/problems/alien-dictionary/)

There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

Example 1:
```
Input:
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]

Output: "wertf"
```

Example 2:
```
Input:
[
  "z",
  "x"
]

Output: "zx"
```

Example 3:
```
Input:
[
  "z",
  "x",
  "z"
] 

Output: "" 

Explanation: The order is invalid, so return "".
```

Note:

1. You may assume all letters are in lowercase.
2. You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
3. If the order is invalid, return an empty string.
4. There may be multiple valid order of letters, return any one of them is fine.

#### Solution 1

1. build edges

2. toposort

C++

```
class Solution {
public:
    string alienOrder(vector<string>& words) {
        set<pair<char, char>> edges;
        unordered_set<char> dict;
        vector<int> in(256);
        string res;
        for (string& word : words) {
            dict.insert(word.begin(), word.end());
        }
        for (int i = 0; i < (int)words.size() - 1; i++) {
            int mn = min(words[i].size(), words[i + 1].size());
            for (int j = 0; j < mn; j++) {
                if (words[i][j] != words[i + 1][j]) {
                    // the first difference reveals the order
                    edges.insert({words[i][j], words[i+ 1][j]});
                    break;
                }
            }
        }
        queue<char> todo;
        for (auto& edge : edges) in[edge.second]++;
        for (auto& c : dict) {
            if (in[c] == 0) {
                todo.push(c);
                res += c;
            }
        }
        while (!todo.empty()) {
            char c = todo.front(); todo.pop();
            for (auto& edge : edges) {
                if (edge.first == c) {
                    in[edge.second]--;
                    if (in[edge.second] == 0) {
                        todo.push(edge.second);
                        res += edge.second;
                    }
                }
            }
        }
        return res.size() == dict.size() ? res : "";
    }
};
```


#### Solution 2

1. build edges
2. build graph
3. toposort

C++

```
class Solution {
public:
    string alienOrder(vector<string>& words) {
        set<pair<char, char>> edges;
        unordered_set<char> dict;
        vector<int> in(256);

        for (string word : words) {
            dict.insert(word.begin(), word.end());
        }
        for (int i = 0; i < (int)words.size() - 1; i++) {
            int mn = min(words[i].size(), words[i + 1].size());
            for (int j = 0; j < mn; j++) {
                if (words[i][j] != words[i + 1][j]) {
                    edges.insert({words[i][j], words[i+ 1][j]});
                    break;
                }
            }
        }
        
        vector<vector<char>> graph(256);
        for (auto& edge : edges) {
            graph[edge.first].push_back(edge.second);
            in[edge.second]++;
        }
        
        queue<char> todo;
        for (auto& c : dict) {
            if (in[c] == 0) todo.push(c);
        }
        
        string res;
        while (!todo.empty()) {
            for (int i = todo.size() - 1; i >= 0; --i) {
                char t = todo.front(); todo.pop();
                res.push_back(t);
                for (char c : graph[t]) {
                    --in[c];
                    if (in[c] == 0) todo.push(c);
                }
            }
        }
        return res.size() == dict.size() ? res : "";
    }
};
```
