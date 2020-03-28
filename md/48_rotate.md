### 48\. [Rotate Image](https://leetcode.com/problems/rotate-image/)

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:
```
Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
```
Example 2:
```
Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
```


#### Solution 1

C++

We can directly swap elements according to the definition of rotation. 
We swap 4 elements at a time and repeat for 1/4 of the matrix.
```
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty() or matrix[0].empty()) return;
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - i - 1; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = tmp;
            }
        }
    }
};
```

#### Solution 2

C++

Clock-wise rotate is equivalent to transpose + mirror in the row direction.

```
class Solution {
public:
	void rotate2(vector<vector<int>>& matrix) {
		int n = matrix.size();
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				swap(matrix[i][j],matrix[j][i]);
			}
		}
		for (int i = 0; i < n; i++) {
			reverse(matrix[i].begin(),matrix[i].end());
		}
	}
};
```
