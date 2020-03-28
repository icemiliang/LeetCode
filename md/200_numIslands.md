### 200\. [Number of Islands](https://leetcode.com/problems/number-of-islands/)

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
```
Input:
11110
11010
11000
00000

Output: 1
```

Example 2:
```
Input:
11000
11000
00100
00011

Output: 3
```

#### Solution 1

DFS

C++

```
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() or grid[0].empty()) return 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int num = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '0' or visited[i][j]) continue;
                dfs(grid, visited, i, j);
                num++;
            }
        }
        return num;
    }
    
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        if (visited[x][y] or grid[x][y] == '0') return;
        visited[x][y] = true;
        if (x > 0) dfs(grid, visited, x - 1, y);
        if (x < grid.size() - 1) dfs(grid, visited, x + 1, y);
        if (y > 0) dfs(grid, visited, x, y - 1);
        if (y < grid[x].size() - 1) dfs(grid, visited, x, y + 1);
    }
};
```

Another way of writing the algorithm.

```
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() or grid[0].empty()) return 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int num = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '0' or visited[i][j]) continue;
                dfs(grid, visited, i, j);
                num++;
            }
        }
        return num;
    }
    
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        if (x < 0 or x >= grid.size() or y < 0 or y >= grid[0].size()) return;
        if (grid[x][y] == '0' or visited[x][y]) return;
        visited[x][y] = true;
        dfs(grid, visited, x - 1, y);
        dfs(grid, visited, x + 1, y);
        dfs(grid, visited, x, y - 1);
        dfs(grid, visited, x, y + 1);
    }
};
```

No visited array, wipe out all the 1's in grid. And reduce number of recursion.

```
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() or grid[0].empty()) return 0;
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '0') continue;
                dfs(grid, i, j);
                res++;
            }
        }
        return res;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        if (i > 0 and grid[i - 1][j] != '0') dfs(grid, i - 1, j); // left
        if (i < grid.size() - 1 and grid[i + 1][j] != '0') dfs(grid, i + 1, j); // right
        if (j > 0 and grid[i][j - 1] != '0') dfs(grid, i, j - 1); // up
        if (j < grid[i].size() - 1 and grid[i][j + 1] != '0') dfs(grid, i, j + 1); // down
    }
};
```

#### Solution 2

BFS

```
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0, offsets[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> todo;
                    todo.push({i, j});
                    while (!todo.empty()) {
                        pair<int, int> p = todo.front();
                        todo.pop();
                        for (int k = 0; k < 4; k++) {
                            int r = p.first + offsets[k], c = p.second + offsets[k + 1];
                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                                grid[r][c] = '0';
                                todo.push({r, c});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};
```