### 915\. [Partition Array into Disjoint Intervals](https://leetcode.com/problems/partition-array-into-disjoint-intervals/)

Given an array A, partition it into two (contiguous) subarrays left and right so that:

Every element in left is less than or equal to every element in right.
left and right are non-empty.
left has the smallest possible size.
Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.


Example 1:
```
Input: [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]
```

Example 2:
```
Input: [1,1,1,0,6,12]
Output: 4
Explanation: left = [1,1,1,0], right = [6,12]
```

Note:

1. 2 <= A.length <= 30000
2. 0 <= A[i] <= 10^6
3. It is guaranteed there is at least one way to partition A as described.
 
#### Solution 1

mx: max of seen elements
leftMax: max of the candidate left subarray
index: partition boundary

Scan array, if cur element < left array max, cur element is the new boundary,
replace the left max with the max until the boundary.

Time: O(n)
Space: O(1)

C++

```
class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int mx = A[0], leftMax = A[0];
        int index = 0;
        for (int i = 1; i < A.size(); ++i) {
            mx = max(mx, A[i]);
            if (A[i] < leftMax) {
                index = i;
                leftMax = mx;
            }
        }
        return index + 1;
    }
};
```

#### Solution 2

Scan array from left and keep a max. This max should be smaller than anything to the right.
Then, use an array to store the curMin when scanning from right. If left max is smaller than
a min, immediately return the current length.

Time: O(n)
Space: O(n)

C++

```
class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int n = A.size(), curMax = INT_MIN;
        vector<int> backMin(n, A.back());
        for (int i = n - 2; i >= 0; --i) {
            backMin[i] = min(backMin[i + 1], A[i]);
        }
        for (int i = 0; i < n - 1; ++i) {
            curMax = max(curMax, A[i]);
            if (curMax <= backMin[i + 1]) return i + 1;
        }
        return 0;
    }
};
```
