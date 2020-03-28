### 240\. [Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/)

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:
```
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
```
Given target = 5, return true.

Given target = 20, return false.

#### Solution 1

If we look at the top right corner of the matrix, we observe that all the 
elements are smaller than their right neighbors and also smaller than their 
below neighbors. Thus, if the current element is smaller than the target, 
the target must be on the left and if it is larger than target, the target 
must be below it.

Time: O(m + n) 

Space: O(1)

C++

```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() or matrix[0].empty()) return false;
        int i = 0, j = matrix[0].size() - 1;
        while (i < matrix.size() and j >= 0) {
            int cur = matrix[i][j];
            if (cur == target) return true;
            else if (cur > target) --j;
            else ++i;
        }
        return false;
    }
};
```

Python

```
class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not matrix or not matrix[0]:
            return False
        i = 0
        j = len(matrix[0]) - 1
        while i < len(matrix) and j >= 0:
            if matrix[i][j] == target:
                return True
            if matrix[i][j] < target:
                i += 1
            else:
                j -= 1
        return False
```
