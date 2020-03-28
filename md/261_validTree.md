### 261\. [Graph Valid Tree](https://leetcode.com/problems/graph-valid-tree/)

Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example 1:
```
Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true
```
Example 2:
```
Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false
```
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.


#### Solution 1 

https://leetcode.com/problems/graph-valid-tree/discuss/69019/Simple-and-clean-c%2B%2B-solution-with-detailed-explanation.

1. Search for cycle
2. Search for isolated node # of edges = # of vertices - 1

Because the deepest root will not have a parent, its parent should be the same
as its own value.

C++

```
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> parent(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
        // 1. check cycles
        for (auto& e : edges) {
            int v1 = e[0];
            int v2 = e[1];
            // trace the root node (the deepest parent node)
            while (v1 != parent[v1]) v1 = parent[v1];
            while (v2 != parent[v2]) v2 = parent[v2];
            if (v1 == v2) return false;
            parent[v2] = v1;
        }
        // 2. check isolated components
        return edges.size() == n - 1;
    }
};
```
