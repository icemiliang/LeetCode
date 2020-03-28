### 93\. [Restore IP Addresses](https://leetcode.com/problems/restore-ip-addresses/)

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:
```
Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
```

#### Solution 1

Brute force. Cut the string into 4 pieces. 
If each piece is smaller than 255, 
push the pieces into the result.

Time: O(n^3)
Space: O(1)

C++

```
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        for (int a = 1; a < 4; ++a) 
        for (int b = 1; b < 4; ++b) 
        for (int c = 1; c < 4; ++c) 
        for (int d = 1; d < 4; ++d) 
            if (a + b + c + d == s.size()) {
                int A = stoi(s.substr(0, a));
                int B = stoi(s.substr(a, b));
                int C = stoi(s.substr(a + b, c));
                int D = stoi(s.substr(a + b + c, d));
                if (A <= 255 and B <= 255 and C <= 255 and D <= 255) {
                    string t = to_string(A) + "." + to_string(B) + "." + to_string(C) + "." + to_string(D);
                    if (t.size() == s.size() + 3) res.push_back(t);
                }
            }
        return res;
    }
};
```

#### Solution 2

DFS

Time: O(n^2)
Space: O(1)

C++

```
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        dfs(s, 4, "", res);
        return res;
    }
    
    void dfs(string s, int k, string out, vector<string>& res) {
        if (k == 0) {
            if (s.empty()) {
                out.pop_back();
                res.push_back(out);
            }
        }
        else {
            for (int i = 1; i <= 3; ++i) {
                if (s.size() >= i and isValid(s.substr(0, i))) {
                    dfs(s.substr(i), k - 1, out + s.substr(0, i) + ".", res);
                }
            }
        }
    }
    
    bool isValid(string s) {
        if (s.empty() or s.size() > 3 or (s.size() > 1 and s[0] == '0')) return false;
        int res = atoi(s.c_str());
        return res <= 255 and res >= 0;
    }
};
```

No isValid function.

```
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        dfs(s, 4, "", res);
        return res;
    }
    
    void dfs(string s, int k, string out, vector<string>& res) {
        if (k == 0) {
            if (s.empty()) {
                out.pop_back();
                res.push_back(out);
            }
        }
        else {
            for (int i = 1; i <= 3; ++i) {
                if (s.size() < i) break;
                int val = stoi(s.substr(0, i));
                if (val > 255 or i != to_string(val).size()) continue;
                dfs(s.substr(i), k - 1, out + s.substr(0, i) + ".", res);
            }
        }
    }
};
```

