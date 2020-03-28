### 264\. [Ugly Number II](https://leetcode.com/problems/ugly-number-ii/)

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:
```
Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
```

Note:  

1. 1 is typically treated as an ugly number.
2. n does not exceed 1690.


#### Solution 1

Multiply 2, 3, or 5 to previous numbers, each add the smallest to the tail.
Use three indices to keep track of previous numbers.

Time: O(n)
Space: O(n)

C++

```
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(1, 1);
        int i = 0, j = 0, k = 0;
        while (dp.size() < n) {
            // three candidates of the smallest
            int r = dp[i] * 2;
            int s = dp[j] * 3;
            int t = dp[k] * 5;
            // if r small
            if (r <= s and r <= t) {
                dp.push_back(r);
                ++i;
                if (r == s) ++j;
                if (r == t) ++k;
            }
            // if s small
            else if (s <= r and s <= t) {
                dp.push_back(s);
                ++j;
                if (s == r) ++i;
                if (s == t) ++k;
            }
            // if t small
            else {
                dp.push_back(t);
                ++k;
                if (t == r) ++i;
                if (t == s) ++j;
            }
        }
        return dp.back();
    }
};
```

https://leetcode.com/problems/ugly-number-ii/discuss/69368/Elegant-C%2B%2B-Solution-O(N)-space-time-with-detailed-explanation
Another implementation

```
class Solution {
public:
    int nthUglyNumber(int n) {
        vector <int> res (1, 1);
        int i = 0, j = 0, k = 0;
        while (res.size() < n) {
            res.push_back(min(res[i] * 2, min(res[j] * 3, res[k] * 5)));
            if (res.back() == res[i] * 2) ++i;
            if (res.back() == res[j] * 3) ++j;
            if (res.back() == res[k] * 5) ++k;
        }
        return res.back();
    }
};
```

#### Solution 2

Brute force. Check each number ugly or not.

Time: O(MAXlogMAX)
Space: O(1)

C++

```
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        int cnt = 0;
        for (int i = 2; i <= INT_MAX; ++i) {
            if (i % 5 != 0 and i % 3 != 0 and i % 2 != 0) continue;
            int t = i;
            while (t % 5 == 0) t /= 5;
            while (t % 3 == 0) t /= 3;
            while (t % 2 == 0) t /= 2;
            if (t == 1) {
                ++cnt; 
            }
            if (cnt == n - 1) return i;
        }
        return 0;
    }
};
```