### 922\. [Sort Array By Parity II](https://leetcode.com/problems/sort-array-by-parity-ii/)

Given an array ```A``` of non-negative integers, half of the integers in ```A``` are odd, and half of the integers are even.

Sort the array so that whenever ```A[i]``` is odd, ```i``` is odd; and whenever ```A[i]``` is even, ```i``` is even.

You may return any answer array that satisfies this condition.

 
Example 1:

```
Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
```

Note:

1. ```2 <= A.length <= 20000```
2. ```A.length % 2 == 0```
3. ```0 <= A[i] <= 1000```

#### Solution 1

Modify original array.

C++

```
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        if (A.size() < 2) return A;
        int i = 0, j = 1, n = A.size();
        while (i < n and j < n) {
            while (i < n and A[i] % 2 == 0) i += 2;
            while (j < n and A[j] % 2 == 1) j += 2;
            if (i >= n or j >= n) return A;
            swap(A[i], A[j]);
            i+= 2;
            j+= 2;
        }
        return A;
    }
};
```

Return new array

```
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        // checker
        int i = 0, j = 1, n = A.size();
        vector<int> res(n);
        for (int k = 0; k < n; ++k) {
            if (A[k] % 2 == 0) {
                res[i] = A[k];
                i += 2;
            }
            else {
                res[j] = A[k];
                j += 2;
            }
        }
        return res;
    }
};
```
