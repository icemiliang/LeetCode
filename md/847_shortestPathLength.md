### 847\. [Shortest Path Visiting All Nodes](https://leetcode.com/problems/shortest-path-visiting-all-nodes/)

An undirected, connected graph of N nodes (labeled 0, 1, 2, ..., N-1) is given as graph.

graph.length = N, and j != i is in the list graph[i] exactly once, if and only if nodes i and j are connected.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.

 

Example 1:
```
Input: [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]
```
Example 2:
```
Input: [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]
```

Note:

1. 1 <= graph.length <= 12
2. 0 <= graph[i].length < graph.length

#### Solution 1

https://www.cnblogs.com/grandyang/p/11410007.html

BFS

C++

```
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(), target = 0, res = 0;
        unordered_set<string> visited;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            int mask = (1 << i);
            target |= mask;
            visited.insert(to_string(mask) + "-" + to_string(i));
            q.push({mask, i});
        }
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                auto cur = q.front(); q.pop();
                if (cur.first == target) return res;
                for (int next : graph[cur.second]) {
                    int path = cur.first | (1 << next);
                    string str = to_string(path) + "-" + to_string(next);
                    if (visited.count(str)) continue;
                    visited.insert(str);
                    q.push({path, next});
                }
            }
            ++res;
        }
        return -1;
    }
};
```

Another BFS solution which is much faster

```
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int N = graph.size();
        queue<pair<pair<int, int>, int>> todo; // (curr_node, visited_node, len)
        vector<vector<bool>> visited(N, vector<bool>(1 << N, false));
        for (int i = 0; i < N; i++) {
            visited[i][1 << i] = true;
            todo.push({{i, 1 << i}, 0});
        }
        int target = (1 << N) - 1;
        while (!todo.empty()) {
            auto ele = todo.front(); todo.pop();
            int curr_node = ele.first.first;
            int status = ele.first.second;
            int curr_len = ele.second;
            // cout << curr_node <<' '<<status<<' '<<curr_len<<endl;
            for (auto new_node: graph[curr_node]) {
                int new_status = status | (1 << new_node);
                if (new_status == target) return curr_len + 1;
                if (visited[new_node][new_status]) continue;
                // can't check after push TLE. Have to check before pusha
                visited[new_node][new_status] = true;
                todo.push({{new_node, new_status}, curr_len+1});
                
            }
        }
        return 0;
    }
};
```

#### Solution 2

DP

C++

```
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(), res = n * n;
        vector<vector<int>> dp(1 << n, vector<int>(n, n * n));
        for (int i = 0; i < n; ++i) dp[1 << i][i] = 0;
        for (int cur = 0; cur < (1 << n); ++cur) {
            bool repeat = true;
            while (repeat) {
                repeat = false;
                for (int i = 0; i < n; ++i) {
                    int dist = dp[cur][i];
                    for (int next : graph[i]) {
                        int path = cur | (1 << next);
                        if (dist + 1 < dp[path][next]) {
                            dp[path][next] = dist + 1;
                            if (path == cur) repeat = true;
                        }
                    }
                }
            }
        }
        for (int num : dp.back()) {
            res = min(res, num);
        }
        return res;
    }
};
```
