### 7\. [Reverse Integer](https://leetcode.com/problems/reverse-integer/)
```
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21

Note:
Assume we are dealing with an environment which could only store integers within 
the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, 
assume that your function returns 0 when the reversed integer overflows.
```

#### Solution 1

Define a new int, res, equal to 0. Multiply res by 10 and 
add the mod 10 of x and divide x by 10. Repeat until x = 0.
One thing to note is handling the number whose inverse >= INT_MIN.
-INT_MIN = INT_MAX+1. Thus, each time first we need to check if the
current reversed int is already > INT_MAX/10. If so, then return 0,
because we are going to multiple it by 10. If you wonder that 
res * 10 < INT_MAX but res * 10 + x % 10 > INT_MAX. That can't happen
because for that to happen the original number has to be < INT_MIN.
You can check it youself. INT_MAX = 2147483647, INT_MIN = -2147483648.


```
int reverse(int x) {
    int res = 0;
    while (x) {
        if (abs(res) > INT_MAX/10) return 0;
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}
```
