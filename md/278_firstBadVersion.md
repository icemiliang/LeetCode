### 278\. [First Bad Version](https://leetcode.com/problems/first-bad-version/)

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Example:
```
Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version. 
```

#### Solution 1

The version numbers are a sorted array, so we can use binary search to find the 
1st bad version. It is like finding the first 1 in the array [0,0,1,1,1]. 
The rest of it is the classic binary search code.

C++

```
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
    	int left = 0, right = n;
    	while (left < right) {
    		int mid = left + (right - left) / 2;
    		if (!isBadVersion(mid)) left = mid + 1;
    		else right = mid;
    	}
    	return right;
    }
};
```

Python

```
# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        

```

#### Solution 2

For completion, let's write the brute-form solution here as well.
Loop the array and return the 1st version that is a bad one. This 
solution cannot pass the Leetcode OJ because of time limit exceeded.

C++

```
class Solution {
public:
	int firstBadVersion(int n) {
		for (int i = 0; i <= n; i++) {
			if (isBadVersion(i)) return i;
		}
		return -1;
	}
};
```

Python

```
class Solution:
	def firstBadVersion(n):
		 """
        :type n: int
        :rtype: int
        """

        for i in range(n+1):
        	if isBadVersion(i):
        		return i
        return -1
```
