### 69\. [Sqrt(x)](https://leetcode.com/problems/sqrtx/)

Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:
```
Input: 4
Output: 2
```
Example 2:
```
Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
```

#### Solution 1

The general idea is to compute the square of each candicate and compare it with x.
To reduce the search time, we can use binary search. The left pointer starts from 0,
and the right pointer starts from x. Be careful about the right pointer. This time
it starts from x because the input is a number not an array whose last index is 
smaller than the size by 1. At the end, return right - 1.

C++

```
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int left = 0, right = x;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x / mid >= mid) left = mid + 1;
            else right = mid;
        }
        return right - 1;
    }
};
```

Python

```
class Solution:
    def mySqrt(self, x: int):
        if x <= 1:
            return x
        left = 0
        right = x;
        while left < right:
            mid = left + (right - left) // 2
            if x // mid >= mid:
                left = mid + 1
            else:
                right = mid
        return right - 1
```

Example:
```
x = 61

left right mid x/mid
0    61    30  2
0    30    15  4
0    15    7   8
8    15    11  5
8    11    9   6
8    9     8   7
8    8

sqrt(61) = 7
```

#### Solution 2

We can use Newton's method to approxiamte the suqare root which will be covered later.
