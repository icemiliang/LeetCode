### 1055\. [Shortest Way to Form String](https://leetcode.com/problems/shortest-way-to-form-string/)

From any string, we can form a subsequence of that string by deleting some number of characters (possibly no deletions).

Given two strings source and target, return the minimum number of subsequences of source such that their concatenation equals target. If the task is impossible, return -1.


Example 1:
```
Input: source = "abc", target = "abcbc"
Output: 2
Explanation: The target "abcbc" can be formed by "abc" and "bc", which are subsequences of source "abc".
```
Example 2:
```
Input: source = "abc", target = "acdbc"
Output: -1
Explanation: The target string cannot be constructed from the subsequences of source string due to the character "d" in target string.
```
Example 3:
```
Input: source = "xyz", target = "xzyxz"
Output: 3
Explanation: The target string can be constructed as follows "xz" + "y" + "xz".
```

Constraints:

* Both the source and target strings consist of only lowercase English letters from "a"-"z".
* The lengths of source and target string are between 1 and 1000.

#### Solution 1

Time: O(mn)
Space: O(1)

C++

```
class Solution {
public:
    int shortestWay(string source, string target) {
        int count = 1;
        int pos = -1;
        //scan chars in target
        for (int i = 0; i < target.size(); i++){
            if (source.find(target[i]) ==-1) return -1; // if target has unknown char, return -1
            // find after pos
            pos = source.find(target[i], pos + 1);
            // if no other in the source after pos 
            if (pos == -1){
                // start a new subsequence
                count++;
                pos = source.find(target[i]); // first position in source
            }
        }
        return count;
    }
};
```

Avoid searching twice.

C++

```
class Solution {
public:
    int shortestWay(string source, string target) {
        int cnt = 1;
        int pos = -1;
        for (char c : target) {
            int tmp = source.find(c);
            if (tmp == -1) return -1;
            if (tmp <= pos) pos = source.find(c, pos + 1);
            else pos = tmp;
            if (pos == -1) {
                ++cnt;
                pos = tmp;
            }            
        }
        return cnt;
    }
};
```


#### Solution 2

https://leetcode.com/problems/shortest-way-to-form-string/discuss/309404/C%2B%2B-with-picture-greedy

Similar to Solution 1, use two pointers to do the search.

Time: O(mn)
Space: O(1)

C++

```
class Solution {
public:
    int shortestWay(string s, string t) {
        int i = 0, j = 0, res = 0;
        while (i < t.size() && res <= i) {
            while (t[i] != s[j] && j < s.size()) ++j;
            if (j == s.size()) j = 0, ++res;
            else ++i, ++j;
        }
        return res <= i ? res + 1 : -1;
    }
};
```

#### Solution 3

Time: O(nlogm)
Space: O(m)

C++

```
class Solution {
public:
    int shortestWay(string s, string t) {
        int cnt = 1;
        vector<vector<int>> ch_ids(26);
        for (auto j = 0; j < s.size(); ++j) ch_ids[s[j] - 'a'].push_back(j);
        for (auto i = 0, j = -1; i < t.size(); ) {
            auto& ids = ch_ids[t[i] - 'a'];
            if (ids.empty()) return -1;
            auto it = upper_bound(ids.begin(), ids.end(), j);
            if (it == ids.end()){
                // start a new sequence
                ++cnt;
                j = -1;    
            } 
            else {
                // continue
                ++i;
                j = *it;  
            }
        } 
        return cnt;
    }
};
```
