### 54\. [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:
```
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
```
Example 2:
```
Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
```

#### Solution 1

Because we need to traverse all the elements, there is no trick we can play. Let's just
push every element in the spiral order. When traveling in the spiral order, one thing we
need to store is the first and last elements along an edge. For example, when we travel
along the second row, we need to start from the second element and stop at the second to
last element. Thus, we maintain 4 indices for the boundaries -- top, right, bottom, left.
Travel the 4 edges in order and push back the values between the 2 boundaries
in the other direction to the result.

C++

```
vector<int> spiralOrder(vector<vector<int>>& matrix) {
	if (matrix.size() < 1 || matrix[0].size() < 1) return {};
	int top = 0, bottom = matrix.size()-1, left = 0, right = matrix[0].size()-1;
	vector<int> res;
	while (true) {
		for (int i = left; i <= right; i++ ) res.push_back(matrix[top][i]); // top
		if (++top > bottom) break;
		for (int i = top; i <= bottom; i++) res.push_back(matrix[i][right]);  // right
		if (--right < left) break;
		for (int i = right; i >= left; i--) res.push_back(matrix[bottom][i]); // bottom
		if (--bottom < top) break;
		for (int i = bottom; i >= top; i--) res.push_back(matrix[i][left]); // left
		if (++left > right) break;
	} 
	return res;
}
```

Python

```
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return []
        
        up, down, left, right = 0, len(matrix) - 1, 0, len(matrix[0]) - 1
        res = []
        while True:
            for j in range(left, right + 1):
                res.append(matrix[up][j])
            up += 1
            if up > down:
                break
            
            for i in range(up, down + 1):
                res.append(matrix[i][right])
            right -= 1
            if right < left:
                break
                
            for j in range(right, left - 1, -1):
                res.append(matrix[down][j])
            down -= 1
            if down < up:
                break
            
            for i in range(down, up - 1, -1):
                res.append(matrix[i][left])
            left += 1
            if left > right:
                break
        return res
```
