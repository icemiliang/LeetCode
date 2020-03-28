### 231\. [Power of Two](https://leetcode.com/problems/power-of-two/)

Given an integer, write a function to determine if it is a power of two.

Example 1:
```
Input: 1
Output: true 
Explanation: 20 = 1
```

Example 2:
```
Input: 16
Output: true
Explanation: 24 = 16
```

Example 3:
```
Input: 218
Output: false
```

#### Solution 1

Staightforward and slower

Time: O(logn)
Space: O(1)

C++

```
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int t = 1;
        const int inf = INT_MAX / 2;
        while (t < n and t <= inf) {
            t *= 2;
        }
        return t == n;
    }
};
```

#### Solution 2

Time: O(1)
Space: O(1)

C++

```
class Solution {
public:
    bool isPowerOfTwo(int n) {
    	return (n > 0) and !(n & (n - 1));
    }
};
```
