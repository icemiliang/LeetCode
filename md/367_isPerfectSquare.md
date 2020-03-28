### 367\. [Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square/)

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:
```
Input: 16
Output: true
```

Example 2:
```
Input: 14
Output: false
```

#### Solution 1

This is a spin-off of [69. mySqrt](69_mySqrt.md). The difference is that this
problem asks about the perfect square/square root. There are many variants of
Solution 1.

The first uses binary search. Each time we check if mid * mid equals num.

C++

```
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num <= 1) return num;
        int left = 2, right = num;
        while (left < right) {
            long mid = left + (right - left) / 2;
            long square = mid * mid;
            if (square == num) return true;
            if (square < num) left = mid + 1;
            else right = mid;
        }
        return false;
    }
};
```

Python

```
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        left = 0
        right = num
        while left <= right:
            mid = left + (right - left) // 2
            square = mid * mid
            if square == num:
                return True
            if square < num:
                left = mid + 1
            else:
                right = mid - 1
        return False
```

#### Solution 2

The second solution searches from 1 to sqrt(num). 

Time: O(sqrt(n))

C++

```
class Solution {
public:
    bool isPerfectSquare(int num) {
        for (int i = 1; i <= num / i; i++) {
            if (i * i == num) return true;
        }
        return false;
    }
};
```

Python

```
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        i = 1
        while i <= num // i:
            if i * i == num:
                return True
            i += 1
        return False
```

#### Solution 3

The third variant uses the property that the summation of odd
numbers is a perfect square number.

Example:
```
1 = 1
4 = 1 + 3
9 = 1 + 3 + 5
16 = 1 + 3 + 5 + 7
25 = 1 + 3 + 5 + 7 + 9
...
n * n = 1 + 3 + 5 + ... + (2n - 1) = (1 + 2n - 1) * n / 2
```

C++

```
class Solution {
public:
    bool isPerfectSquare(int num) {
        for (int i = 1; i < num / i; i++) {
            if (i * i == num) return true;
        }
        return false;
    }
}
```

Python

```
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        i = 1
        while i <= num // i:
            if i * i == num:
                return True
            i += 1
        return False
```

#### Solution 4

Below offers another solution. It leverages the observation that for any number 
smaller than num, the square root must be between that number and the quotient,
that is, x < sqrt < num / x. Thus, each time we compute the average of x and num / x.

C++

```
class Solution {
public:
    bool isPerfectSquare(int num) {
        long x = num;
        while (x * x > num) {
            x = (x + num / x) / 2;
        }
        return x * x == num;
    }
};
```

Python

```
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        x = num
        while x * x > num:
            x = (x + num // x) // 2
        return x * x == num
```
