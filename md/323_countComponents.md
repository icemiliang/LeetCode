### 323\. [Number of Connected Components in an Undirected Graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/)

Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:
```
Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]

     0          3
     |          |
     1 --- 2    4 

Output: 2
```

Example 2:
```
Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]

     0           4
     |           |
     1 --- 2 --- 3

Output:  1
```

Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

#### Solution 1

DFS. Very similar to [200. Number of Islands](https://leetcode.com/problems/number-of-islands/).

C++

```
class Solution {
    vector<vector<int>> graph;
    vector<bool> visited;
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        int cnt = 0;
        visited.resize(n, false);
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            dfs(i);
            ++cnt;
        }
        return cnt;
    }
    
    void dfs(int i) {
        visited[i] = true;
        for (int j : graph[i]) {
            if (!visited[j]) dfs(j);
        }
    }
};
```

#### Solution 2

BFS.

C++

```

```
