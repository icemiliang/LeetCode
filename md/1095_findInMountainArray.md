### 1095\. [Find in Mountain Array](https://leetcode.com/problems/find-in-mountain-array/)

(This problem is an interactive problem.)

You may recall that an array A is a mountain array if and only if:

* A.length >= 3
* There exists some i with 0 < i < A.length - 1 such that:
	* A[0] < A[1] < ... A[i-1] < A[i]
	* A[i] f> A[i+1] > ... > A[A.length - 1]

Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target.  If such an index doesn't exist, return -1.

You can't access the mountain array directly.  You may only access the array using a MountainArray interface:

* MountainArray.get(k) returns the element of the array at index k (0-indexed).
* MountainArray.length() returns the length of the array.

Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

#### Solution 1

C++

```
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
int findInMountainArray(int target, MountainArray& A) {
        int n = A.length(), lo, hi, m, peak = 0;
        // find index of peak
        lo  = 0;
        hi = n - 1;
        while (lo < hi) {
            m = lo + (hi - lo) / 2;
            if (A.get(m) < A.get(m + 1))
                lo = peak = m + 1;
            else
                hi = m;
        }
        // find target in the left of peak
        lo = 0;
        hi = peak;
        while (lo < hi) {
            m = lo + (hi - lo) / 2;
            if (A.get(m) < target)
                lo = m + 1;
            else
                hi = m;
        }
        if (lo >= 0 and A.get(lo) == target) return lo;
        // find target in the right of peak
        lo = peak;
        hi = n - 1;
        while (lo < hi) {
            m = lo + (hi - lo) / 2;
            if (A.get(m) > target)
                lo = m + 1;
            else
                hi = m;
        }
        if (lo < n and A.get(lo) == target) return lo;
        return -1;
    }
};
```
