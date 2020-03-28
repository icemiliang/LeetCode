### 378\. [Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)

Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:
```
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
```

Note:
You may assume k is always valid, 1 ≤ k ≤ n^2.


#### Solution 1

C++

```
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> topK;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                topK.push(matrix[i][j]);
                if (topK.size() > k) topK.pop();
            }
        }
        return topK.top();
    }
};
```


#### Solution 2

C++

```
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix.back().back();
        while (left < right) {
            int mid = left + (right - left) / 2, count = 0;
            for (int i = 0; i < matrix.size(); i++) {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if (count < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
```
