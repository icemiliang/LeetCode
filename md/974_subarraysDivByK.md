### 974\. [Subarray Sums Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k/)

Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.

Example 1:
```
Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by K = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
```

Note:

1. 1 <= A.length <= 30000
2. -10000 <= A[i] <= 10000
3. 2 <= K <= 10000

#### Solution 1

C++

```
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> count(K);
        count[0] = 1;
        int prefix = 0, res = 0;
        for (int a : A) {
            prefix = (prefix + a % K + K) % K; // positive residual
            res += count[prefix]++;
        }
        return res;
    }
};
```
