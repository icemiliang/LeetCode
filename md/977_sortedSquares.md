### 977\. [Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/)

Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

 

Example 1:
```
Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
```

Example 2:
```
Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
```

Note:

1. 1 <= A.length <= 10000
2. -10000 <= A[i] <= 10000
3. A is sorted in non-decreasing order.

#### Solution 1

Fill the new array from end to start. 
Two pointers from start and end of original array to middle.
Put whichever is bigger to the current position.

C++

```
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int lo = 0, hi = A.size() - 1;
        vector<int> res(A.size());
        int k = res.size() - 1;
        while (lo <= hi) {
            if (abs(A[lo]) >= abs(A[hi])) {
                res[k--] = A[lo] * A[lo];
                ++lo;
            }
            else {
                res[k--] = A[hi] * A[hi];
                --hi;
            }
        }
        return res;
    }
};
```
