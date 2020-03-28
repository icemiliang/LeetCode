### 38\. [Count and Say](https://leetcode.com/problems/count-and-say/)

The count-and-say sequence is the sequence of integers with the first five terms as following:
```
1.     1
2.     11
3.     21
4.     1211
5.     111221
```

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

 

Example 1:
```
Input: 1
Output: "1"

```
Example 2:
```
Input: 4
Output: "1211"
```

#### Solution 1

C++

```
class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        string pre = "1", next;
        for (int i = 0; i < n - 1; ++i) {
            for (int i = 0, j = 0; j < pre.size(); i = j) {
                while (j < pre.size() - 1 and pre[j] == pre[j + 1]) ++j;
                int cnt = j - i + 1;
                next += to_string(cnt);
                next += pre[i];
                ++j;
            }
            pre = next;
            next = "";
        }
        return pre;
    }
};
```
