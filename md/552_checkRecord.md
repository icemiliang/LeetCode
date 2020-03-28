### 552\. [Student Attendance Record II](https://leetcode.com/problems/student-attendance-record-ii/)

Given a positive integer n, return the number of all possible attendance records with length n, which will be regarded as rewardable. The answer may be very large, return it after mod 109 + 7.

A student attendance record is a string that only contains the following three characters:

1. 'A' : Absent.
2. 'L' : Late.
3. 'P' : Present.
A record is regarded as rewardable if it doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

Example 1:
```
Input: n = 2
Output: 8 
Explanation:
There are 8 records with length 2 will be regarded as rewardable:
"PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
Only "AA" won't be regarded as rewardable owing to more than one absent times. 
```

Note: The value of n won't exceed 100,000.

#### Solution 1

https://www.cnblogs.com/grandyang/p/6866756.html

C++

```
class Solution {
public:
    int checkRecord(int n) {
        const int M = 1e9 + 7;
        long A[n], P[n], L[n];
        A[0] = 1;
        P[0] = 1;
        L[0] = 1;
        if (n > 1) {
            L[1] = 3;
            A[1] = 2;
        }
        if (n > 2) A[2] = 4;
        for (int i = 1; i < n; i++) {
            P[i] = (P[i - 1] + A[i - 1]+ L[i - 1]) % M;
            if (i > 1) L[i] = (A[i - 1] + P[i - 1] + A[i - 2] + P[i - 2]) % M;
            if (i > 2) A[i] = (A[i - 1] + A[i - 2] + A[i - 3]) % M;
        }
        return int((A[n - 1] + P[n - 1] + L[n - 1]) % M);
    }
};
```
