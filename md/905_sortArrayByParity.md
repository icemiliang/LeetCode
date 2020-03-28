### 905\. [Sort Array By Parity](https://leetcode.com/problems/sort-array-by-parity/)

Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

Example 1:

```
Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
```

Note:

1. 1 <= A.length <= 5000
2. 0 <= A[i] <= 5000

#### Solution 1

Two pointers one from zero one from end.

C++

```
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int lo = 0, hi = A.size() - 1;
        while (lo < hi) {
            while (lo < hi and A[lo] % 2 == 0) ++lo;
            while (lo < hi and A[lo] % 2 == 1) {
                swap(A[lo], A[hi--]);
            }
        }
        return A;
    }
};
```

A simplified version.

```
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        for (int lo = 0, hi = A.size() - 1; lo < hi; ++lo) {
            while (lo < hi and A[lo] % 2 == 1) {
                swap(A[lo], A[hi--]);
            }
        }
        return A;
    }
};
```

Two pointers both from zero.

```
class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &A) {
        for (int i = 0, j = 0; j < A.size(); j++)
            if (A[j] % 2 == 0) {
                swap(A[i++], A[j]);
            }
        return A;
    }
};
```
