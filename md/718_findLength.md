### 718\. [Maximum Length of Repeated Subarray](https://leetcode.com/problems/maximum-length-of-repeated-subarray/)

Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:
```
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].
```

Note:

1. 1 <= len(A), len(B) <= 1000
2. 0 <= A[i], B[i] < 100

#### Solution 1

Brute force, start from each element in A and each in B. When two elements equal to each other, count++.

C++

```
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int res = 0;
        for (int i = 0; i < A.size(); i++) {
            int j = i;
            int k = 0;
            while (j < A.size() and k < B.size()) {
                int cnt = 0;
                while (j < A.size() and k < B.size() and A[j++] == B[k++]) cnt++;
                res = max(res, cnt);
            }
        }
        
        for (int i = 0; i < B.size(); i++) {
            int j = i;
            int k = 0;
            while (j < B.size() and k < B.size()) {
                int cnt = 0;
                while (j < B.size() and k < A.size() and B[j++] == A[k++]) cnt++;
                res = max(res, cnt);
            }
        }
        return res;
    }
};
```


#### Solution 2

DP\[i\]\[j\]: max length of repeated subarray until ith element of A and jth element of B.
DP\[i\]\[j\] = DP\[i-1\]\[j-1\] + 1

C++

```
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int sizeA = A.size();
        int sizeB = B.size();
        int len = 0;
        vector<vector<int>> dp(sizeA + 1, vector<int>(sizeB + 1, 0));
        for (int i = 1; i <= sizeA; i++) {
            for (int j = 1; j <= sizeB; j++) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    len = max(len, dp[i][j]);
                }
            }
        }
        return len;
    }
};
```
