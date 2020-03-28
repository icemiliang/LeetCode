### 763\. [Partition Labels](https://leetcode.com/problems/partition-labels/)

A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
```
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
```

Note:
1. S will have length in range [1, 500].
2. S will consist of lowercase letters ('a' to 'z') only.

#### Solution 1

Suppose we are building the first part. For each letter in this part, we need to make sure that all of
its occurances are in this part. We just need to make sure that the last apperance is in this part. For
this strategy to work, we need to scan the string once and record the last appearance of each letter.
Then, we scan the string from begining again and record the farthest position of any seen letter. If the
current position is the farthest position, then the letters before that can form a part.

C++

```
class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> m;
        for (int i = 0; i < S.size(); i++) m[S[i]] = i;
        vector<int> res;
        int start = 0, last = 0;
        for (int i = 0; i < S.size(); i++) {
            last = max(last, m[S[i]]);
            if (i == last) {
                res.push_back(last - start + 1);
                start = last + 1;
            }
        }
        return res;
    }
};
```

Python

```
class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        m = {}
        for i in range(len(S)):
            m[S[i]] = i
        start = 0
        last = 0
        res = []
        for i in range(len(S)):
            last = max(last, m[S[i]])
            if i == last:
                res.append(last - start + 1)
                start = last + 1
        return res
```
