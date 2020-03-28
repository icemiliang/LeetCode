###	994\. [Rotting Oranges](https://leetcode.com/problems/rotting-oranges/)

In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 

Example 1:

![alt text](oranges.png)
```
Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
```

Example 2:
```
Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
```

Example 3:
```
Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
```

***Note***:

1. ```1 <= grid.length <= 10```
2. ```1 <= grid[0].length <= 10```
3. ```grid[i][j]``` is only 0, 1, or 2.


#### Solution 1

BFS. Push every rotten orange pos to a queue. Record how many fresh oranges.
Keep a visited array. Pop all rotten oranges and check if they affect any
unvisited fresh oranges and 1 to result if so.

C++

```
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() or grid[0].empty()) return -1;
        int numFresh = 0;
        queue<pair<int, int>> todo;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 2) todo.push({i, j});
                else if (grid[i][j] == 1) ++numFresh;
            }
        }
        
        int res = 0;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!todo.empty()) {
            bool spread = false;
            for (int k = todo.size() - 1; k >= 0; --k) {
                auto t = todo.front(); todo.pop();
                int i = t.first;
                int j = t.second;
                
                for(auto& dir : dirs) {
                    int x = i + dir.first;
                    int y = j + dir.second;
                    if (x < 0 or x >= grid.size()) continue;
                    if (y < 0 or y >= grid[i].size()) continue;
                    if (grid[x][y] != 1) continue;
                    grid[x][y] = 2;
                    todo.push({x, y});
                    --numFresh;
                    spread = true;
                }
            }
            res += spread;
        }
        return numFresh == 0 ? res : -1;
    }
};
```


#### Solution 2

Use the original array to record number of days and visited. Similar to [934. Shortest Bridge](934_shortestBridge.md).

C++

```
class Solution {
public:
	int rot(vector<vector<int>>& grid, int i, int j, int d) {
		if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] != 1) return 0;
		grid[i][j] = d + 3;
		return 1;
	}
	int orangesRotting(vector<vector<int>>& grid, int d = 0, int fresh = 0) {
		for (auto i = 0; i < grid.size(); ++i) 
	    	fresh += count_if(begin(grid[i]), end(grid[i]), [](int j) { return j == 1; });
	  	for (auto old_fresh = fresh; fresh > 0; ++d) {
	    	for (auto i = 0; i < grid.size(); ++i)
	      		for (auto j = 0; j < grid[i].size(); ++j)
	        		if (grid[i][j] == d + 2)
	        fresh -= rot(grid, i + 1, j, d) + rot(grid, i - 1, j, d) + rot(grid, i, j + 1, d) + rot(grid, i, j - 1, d);
	    	if (fresh == exchange(old_fresh, fresh)) 
	    		return -1;
	  	}
	  	return d;
	}
};
```
