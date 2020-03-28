### 852\. [Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array/)

Let's call an array A a mountain if the following properties hold:

A.length >= 3
There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

Example 1:
```
Input: [0,1,0]
Output: 1
```
Example 2:
```
Input: [0,2,1,0]
Output: 1
```
Note:

1. 3 <= A.length <= 10000
2. 0 <= A[i] <= 10^6
3. A is a mountain, as defined above.

#### Solution 1

Although the arrya in this problem is not sorted, but because the solution always 
exists if we use binary search to solve this problem we can still decide whether
the solution is one the left side of the median or the right. If the median is on
the left of the peak, then the median is lager than its left element and smaller
than its right element. If the median is on the right of the peak, then the median
is smaller than its left element and larger than its right element. When the
median is larger than both of its left and right elements, return median index.

C++

```
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int left = 0, right = A.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (A[mid - 1] < A[mid] and A[mid] > A[mid + 1]) return mid;
            if (A[mid - 1] < A[mid] and A[mid] < A[mid + 1]) left = mid + 1;
            else right = mid;
        }
        return -1;
    }
};
```

Python

```
class Solution:
    def peakIndexInMountainArray(self, A: List[int]) -> int:
        left = 0
        right = len(A)
        while left < right:
            mid=  left + (right - left) // 2
            if A[mid] > A[mid - 1] and A[mid] > A[mid + 1]:
                return mid
            if A[mid - 1] < A[mid] < A[mid + 1]:
                left = mid + 1
            else:
                right = mid
        return -1
```

#### Solution 2

I just learned that there is a seach algorithm called Fibonacci search
which also runs on O(log(n)). I will add that later.
