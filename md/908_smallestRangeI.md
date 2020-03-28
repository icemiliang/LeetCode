### 908\. [Smallest Range I](https://leetcode.com/problems/smallest-range-i/)

Given an array A of integers, for each integer A[i] we may choose any x with -K <= x <= K, and add x to A[i].

After this process, we have some array B.

Return the smallest possible difference between the maximum value of B and the minimum value of B.


Example 1:
```
Input: A = [1], K = 0
Output: 0
Explanation: B = [1]
```

Example 2:
```
Input: A = [0,10], K = 2
Output: 6
Explanation: B = [2,8]
```

Example 3:
```
Input: A = [1,3,6], K = 3
Output: 0
Explanation: B = [3,3,3] or B = [4,4,4]
```
 
Note:

1. 1 <= A.length <= 10000
2. 0 <= A[i] <= 10000
3. 0 <= K <= 10000


### Solution 1

Intuition:
If min(A) + K < max(A) - K, then return max(A) - min(A) - 2 * K
If min(A) + K >= max(A) - K, then return 0

Time: O(N)

C++

```
class Solution {
public:
    int smallestRangeI(vector<int> A, int K) {
        int mx = A[0], mn = A[0];
        for (int a : A) {
        	mx = max(mx, a);
        	mn = min(mn, a);
        }
        return max(0, mx - mn - 2 * K);
    }
};
```
