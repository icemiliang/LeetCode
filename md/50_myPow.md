### 50\. [Pow(x, n)](https://leetcode.com/problems/powx-n/)

Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:
```
Input: 2.00000, 10
Output: 1024.00000
```

Example 2:
```
Input: 2.10000, 3
Output: 9.26100
```

Example 3:
```
Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
```

Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]

#### Solution 1


The general idea to solve this problem is that x = (x^(n/2))^2. Thus, we can
use either recursion or iteration to solve it. Let's see show we use recursion.
Each time we first compute half = x^(n/2). If n is a even number, then result
would be half * half. If n is an odd number, we need to check if it is positive
or negative. If it is positive, we return half * half * x; otherwise, return
half * half / x. One thing to notice is that in Python -1 // 2 = -1, not 0.
Thus, we have to check if n > 0 or not and use its absolute value to recurse.


C++

```
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        double half = myPow(x, n/2);
        if (n % 2 == 0) return half * half;
        if (n > 0) return half * half * x;
        return half * half / x;
    }
}

```

Python

```
class Solution:
    def myPow(self, x: float, n: int) -> float:
        def helper(x: float, n: int) -> float:
            if n == 0:
                return 1
            half = helper(x, n // 2)
            if n % 2 == 0:
                return half * half
            return half * half * x
        if n > 0:
            return helper(x, n)
        return 1/ helper(x, -n)
```


#### Solution 2

Using iteration to solve this problem is as follows. Let an index i equal n. If it is odd,
multiply result by x; otherwise, multiply x by x. Iterate the process with i devided by 2
each time until i is 0. Then, return result according the sign or n. I honesly don't know
the logic behind this solution. I think it has something to do with math...


C++

```
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        for (int i = n; i != 0; i /= 2) {
            if (i % 2 != 0) res *= x;
            x *= x;
        }
        return n > 0 ? res : 1 / res;
    }
};
```

Python 

```
class Solution:
    def myPow(self, x: float, n: int) -> float:
        res = 1.0
        sign = n > 0
        n = abs(n)
        while n > 0:
            if n % 2 != 0:
                res *= x
            x *= x
            n = n // 2
        return res if sign else 1 / res 
```
