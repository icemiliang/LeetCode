### 202\. [Happy Number](https://leetcode.com/problems/happy-number/)

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 
```
Input: 19
Output: true
Explanation: 
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
```

#### Solution 1

Use a hashset to track all seen numbers.
If current number seen, break and check if it is 1.

C++

```
class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> visited;
		while (n != 1) {
			visited.insert(n);
			int sum = 0;
			while (n) {
				sum += (n % 10) * (n % 10);
				n /= 10;
			}
			n = sum;
			if (visited.count(n)) break;
		}
		return n == 1;
	}
};
```

#### Solution 2

If 4 appears, then not a happy number. Proof?

C++

```
class Solution {
public:
	bool isHappy(int n) {
		while (n != 1 and n != 4) {
			int sum = 0;
			while (n) {
				sum += (n % 10) * (n % 10);
				n /= 10;
			}
			n = sum;
		}
		return n == 1;
	}
};
```
