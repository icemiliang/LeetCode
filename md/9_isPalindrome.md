### 9\. [Palindrome Number](https://leetcode.com/problems/palindrome-number/)

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:
```
Input: 121
Output: true
```

Example 2:
```
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
```

Example 3:
```
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
```

Follow up:

Coud you solve it without converting the integer to a string?


I have no idea what this block of code does
but it reduces the Leetcode run time by 2/3.
```
static const auto kSpeedUp = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
```

#### Solution 1

The most straightforward way is to reverse the number and check if the 
reversed equals the original.
 
C++

```
class Solution {
public:
	bool isPalindrome1(int x) {
	    if (x < 0 or x % 10 == 0) return false;
		int _x = x;
		int reversed = 0;
		while(_x) {
		    reversed = 10 * reversed + _x % 10;
		    _x /= 10;
		}
		return reversed == x;
	}
};
```

Python

```
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x != 0 and x % 10 == 0):
            return False
        _x = x
        reverse = 0
        while _x:
            reverse = reverse * 10 + _x % 10
            _x = _x // 10
        return reverse == x
```

#### Solution 2

Reversing the whole number is not necessary since we only need to check 
if the first half equals the second half. Thus, we reverse the original 
number digit by digit until the original is not larger than the reversed. 
If the number is a palindrome, then whatever is left out of the original 
should be equal to the reversed. In case the original number has an odd 
number of digits, we also need to check reversed/10.

C++

```
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 or (x != 0 and x % 10 == 0)) return false;
        int reverse = 0;
        while(x > reverse) {
            int residual = x % 10;
            reverse = reverse * 10 + residual;
            x /= 10;
        }
        return x == reverse or x == reverse / 10;
    }
};
```

Python

```
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x != 0 and x % 10 == 0):
            return False
        reverse = 0
        while reverse < x:
            reverse = reverse * 10 + x % 10
            x = x // 10
        return x == reverse or x == reverse // 10
```
