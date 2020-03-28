### 74\. [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)

Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Example 1:
```
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
```
Example 2:
```
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
```


#### Solution 1

Because each column is sorted and each row is sorted, we can use binary search.
First use binary search to find the row index. The row index is the last element
that is smaller than target (if not equal). Thus, when we exits the while loop,
we need to substract the top or bottom index by 1. Then, we do a normal binary
search on that row to search for target.

C++

```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() or matrix[0].empty()) return false;
        if (target < matrix[0][0]) return false;
        int top = 0, bottom = matrix.size();
        while (top < bottom) {
          int mid = top + (bottom - top) / 2;
          if (matrix[mid][0] == target) return true;
          if (matrix[mid][0] < target) top = mid + 1;
          else bottom = mid;
        }
        int i = top - 1;
        int left = 0, right = matrix[i].size();
        while (left < right) {
          int mid = left + (right - left) / 2;
          if (matrix[i][mid] == target) return true;
          if (matrix[i][mid] < target) left = mid + 1;
          else right = mid;
        }
        return false;
    }
};
```

Python

```
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False
        if target < matrix[0][0]:
            return False
        top = 0
        bottom = len(matrix)
        while top < bottom:
            mid = top + (bottom - top) // 2
            if matrix[mid][0] == target:
                return True
            if matrix[mid][0] < target:
                top = mid + 1
            else:
                bottom = mid
    
        i = top - 1
        left = 0
        right = len(matrix[i])
        while left < right:
            mid = left + (right - left) // 2
            if matrix[i][mid] == target:
                return True
            if matrix[i][mid] < target:
                left = mid + 1
            else:
                right = mid
        return False
```
