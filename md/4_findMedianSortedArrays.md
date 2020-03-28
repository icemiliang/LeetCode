### 4\. [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:
```
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
```
Example 2:
```
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
```

#### Solution 1

https://www.cnblogs.com/grandyang/p/4465932.html

C++

```
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m < n) return findMedianSortedArrays(nums2, nums1);
        if (n == 0) return double(nums1[(m - 1) / 2] + nums1[m / 2]) / 2.0;
        int lo = 0, hi = n * 2;
        while (lo <= hi) {
            int mid2 = lo + (hi - lo) / 2;
            int mid1 = m + n - mid2;
            double L1 = mid1 == 0 ? INT_MIN : nums1[(mid1 - 1) / 2];
            double L2 = mid2 == 0 ? INT_MIN : nums2[(mid2 - 1) / 2];
            double R1 = mid1 == m * 2 ? INT_MAX : nums1[mid1 / 2];
            double R2 = mid2 == n * 2 ? INT_MAX : nums2[mid2 / 2];
            if (L1 > R2) lo = mid2 + 1;
            else if (L2 > R1) hi = mid2 - 1;
            else return (max(L1, L2) + min(R1, R2)) / 2;
        }
        return -1;
    }
};
```

#### Solution 2

https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2547/Share-my-iterative-solution-with-O(log(min(n-m)))

http://ocw.alfaisal.edu/NR/rdonlyres/Electrical-Engineering-and-Computer-Science/6-046JFall-2005/30C68118-E436-4FE3-8C79-6BAFBB07D935/0/ps9sol.pdf

C++

```
class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
    int n = A.size();
    int m = B.size();
    if (n > m) return findMedianSortedArrays(B, A);

    // now, do binary search
    int k = (n + m - 1) / 2;
    int l = 0, r = min(k, n); // r is n, NOT n-1, this is important!!
    while (l < r) {
        int midA = l + (r - l) / 2;
        int midB = k - midA;
        if (A[midA] < B[midB])
            l = midA + 1;
        else
            r = midA;
    }
    
    // after binary search, we almost get the median because it must be between
    // these 4 numbers: A[l-1], A[l], B[k-l], and B[k-l+1] 

    // if (n+m) is odd, the median is the larger one between A[l-1] and B[k-l].
    // and there are some corner cases we need to take care of.
    int a = max(l > 0 ? A[l - 1] : INT_MIN, k - l >= 0 ? B[k - l] : INT_MIN);
    if (((n + m) & 1) == 1)
        return (double) a;

    // if (n+m) is even, the median can be calculated by 
    //      median = (max(A[l-1], B[k-l]) + min(A[l], B[k-l+1]) / 2.0
    // also, there are some corner cases to take care of.
    int b = min(l < n ? A[l] : INT_MAX, k - l + 1 < m ? B[k - l + 1] : INT_MAX);
    return (a + b) / 2.0;
    }
};
```
