### 941\. [Valid Mountain Array](https://leetcode.com/problems/valid-mountain-array/)

Given an array A of integers, return true if and only if it is a valid mountain array.

Recall that A is a mountain array if and only if:

```A.length >= 3```
There exists some i with ```0 < i < A.length - 1``` such that:
```A[0] < A[1] < ... A[i-1] < A[i]```
```A[i] > A[i+1] > ... > A[A.length - 1]```

![alt text](https://leetcode.com/problems/valid-mountain-array/)

Example 1:
```
Input: [2,1]
Output: false
```

Example 2:
```
Input: [3,5,5]
Output: false
```

Example 3:
```
Input: [0,3,2,1]
Output: true
```

Note:

1. 0 <= A.length <= 10000
2. 0 <= A[i] <= 10000 

#### Solution 1

Two people climb mountain from left and right, respectively. If they meet, then only one peak.

C++

```
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        int lo = 0;
        int hi = n - 1;
        while (lo < n - 1 and A[lo + 1] > A[lo]) ++lo;
        while (hi > 0 and A[hi - 1] > A[hi]) --hi;
        return lo > 0 and hi < n - 1 and lo == hi;
    }
};
```

#### Solution 2

Go up and down will reach right.

C++

```
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3 or A[0] >= A[1]) return false;
        int n = A.size();
        int lo = 0;
        while (lo < n - 2 and A[lo + 1] > A[lo]) ++lo;
        while (lo < n - 1 and A[lo + 1] < A[lo]) ++lo;
        return lo == n - 1;
    }
};
```

#### Solution 3

One and only one peak

C++

```
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3 or A[0] > A[1]) return false;
        bool peak = false;
        for (int i = 1; i < A.size(); ++i) {
            if ((peak and A[i] > A[i - 1]) or A[i] == A[i - 1]) return false;
            peak = A[i] < A[i - 1];
        }
        return peak;
    }
};
```
