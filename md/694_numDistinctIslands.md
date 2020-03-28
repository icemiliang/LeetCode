### 694\. [Number of Distinct Islands](https://leetcode.com/problems/number-of-distinct-islands/)

Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Example 1:
```
11000
11000
00011
00011
```
Given the above grid map, return 1.

Example 2:
```
11011
10000
00001
11011
```
Given the above grid map, return 3.

Notice that:
```
11
1
```
and
```
 1
11
```
are considered different island shapes, because we do not consider reflection / rotation.
Note: The length of each dimension in the given grid does not exceed 50.

#### Solution 1

C++

```
class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if (grid.empty() or grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        unordered_set<string> shapes;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    string path;
                    dfs(i, j, path, grid);
                    shapes.insert(path);
                }
            }
        }
        return shapes.size();
    }
    
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    void dfs(int i, int j, string& path, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        grid[i][j] = 0;
        for (int k = 0; k < 4; ++k) {
            path.push_back(' ');
            int x = i + dirs[k][0];
            int y = j + dirs[k][1];
            if (x < 0 or x >= m or y < 0 or y >= n or grid[x][y] == 0) continue;
            path.push_back('1' + k); // encode direction into the string
            dfs(x, y, path, grid);
        }
    }
};
```
