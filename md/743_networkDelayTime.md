### 743\. [Network Delay Time](https://leetcode.com/problems/network-delay-time/)

There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

Example 1:

![alt text](931_example_1.png)
```
Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2
```

Note:

1. N will be in the range [1, 100].
2. K will be in the range [1, N].
3. The length of times will be in the range [1, 6000].
4. All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.

#### Solution 1

Speed-up version of Dijkstra

C++

```
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        typedef pair<int, int> pii;
        const int INF = 1e9;
        vector<vector<pii>> graph(N + 1);
        for (const auto& e : times) {
            graph[e[0]].push_back({e[1], e[2]});
        }
        
        vector<int> dist(N + 1, INF);
        vector<bool> visited(N + 1, false);
        priority_queue<pii, vector<pii>, greater<pii>> todo;
        dist[K] = 0;
        todo.push({0, K});
        
        while (!todo.empty()) {
            auto t = todo.top(); todo.pop();
            int u = t.second;
            if (visited[u]) continue;
            for (const auto& to : graph[u]) {
                int v = to.first;
                int w = to.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    todo.push({dist[v], v});
                }
            }
            visited[u] = true;
        }
        
        int delay = 0;
        for (int i = 1; i <= N; i++) {
            delay = max(delay, dist[i]);
        }
        return delay == INF ? -1 : delay;
    }
};
```
