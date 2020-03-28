### 892\. [Surface Area of 3D Shapes](https://leetcode.com/problems/surface-area-of-3d-shapes/)

On a N * N grid, we place some 1 * 1 * 1 cubes.

Each value v = grid\[i\]\[j\] represents a tower of v cubes placed on top of grid cell (i, j).

Return the total surface area of the resulting shapes.

Example 1:
```
Input: [[2]]
Output: 10
```

Example 2:
```
Input: [[1,2],[3,4]]
Output: 34
```

Example 3:
```
Input: [[1,0],[0,2]]
Output: 16
```

Example 4:
```
Input: [[1,1,1],[1,0,1],[1,1,1]]
Output: 32
```

Example 5:
```
Input: [[2,2,2],[2,1,2],[2,2,2]]
Output: 46
```

#### Solution 1

For each occupied grid cell, its area is 2 + 4 * height.
Thus for each occupied cell, we add the total area by the cell's area.
Then, we subtract the hidden area. The hidden area is the smaller height
between two adjacent cells.

C++

```
class Solution {
public:
	int surfaceArea(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		int res = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 0) continue;
				int area = 2 + 4 * grid[i][j];
				if (i != 0 && grid[i-1][j])                area -= min(grid[i-1][j],grid[i][j]); 
				if (i != grid.size()-1 && grid[i+1][j])    area -= min(grid[i+1][j],grid[i][j]); 
				if (j != 0 && grid[i][j-1])                area -= min(grid[i][j-1],grid[i][j]); 
				if (j != grid[0].size()-1 && grid[i][j+1]) area -= min(grid[i][j+1],grid[i][j]); 
				res += area;
			}
		}
		return res;
	}
};
```

We can also directly add the non-hidden area.
Examine the 4 directions separately. If the current cell has
no adjacent cell in a direction, then add its height for that direction.
If there is one and the current one is higher, than add the difference.

C++

```
class Solution {
public:
	int surfaceArea(vector<vector<int>>& grid) {
	    int area = 0;
	    if (grid.empty() or grid[0].empty()) return 0;
	    int m = grid.size(), n = grid[0].size();
	    for (int i = 0; i < m; i++) {
	        for (int j = 0; j < n; j++) {
	            if (!grid[i][j]) continue;
	            area += 2;
	            if (i == 0) area += grid[i][j]; // top
	            else area += max(0, grid[i][j]-grid[i-1][j]);
	            
	            if (i == m-1) area += grid[i][j]; // bottom
	            else area += max(0, grid[i][j]-grid[i+1][j]);
	            
	            if (j == 0) area += grid[i][j]; // left
	            else area += max(0, grid[i][j]-grid[i][j-1]);
	            
	            if (j == n-1) area += grid[i][j]; // right
	            else area += max(0, grid[i][j]-grid[i][j+1]);
	        }
	    }
	    return area;
	}
};
```
