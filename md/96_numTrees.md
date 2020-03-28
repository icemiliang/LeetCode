### 96\. [Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees/)

Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:
```
Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```

#### Solution 1

dp[i] = \sum_j dp[j] * dp[i - j]

C++

```
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};
```

#### Solution 2

Cn = C(2n, n) / (n + 1)

C++

```
class Solution {
public:
    int numTrees(int n) {
        long res = 1;
        for (int i = n + 1; i <= 2 * n; i++) {
            res = res * i / (i - n);
        }
        return res / (n + 1);
    }
};
```
