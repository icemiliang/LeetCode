### 787\. [Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)
Medium

There are n cities connected by m flights. Each fight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
```
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
Explanation: 
The graph looks like this:
```
![alt text](fig_787.png "fig_787")
```
The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
```
Example 2:
```
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500
Explanation: 
The graph looks like this:
```
![alt text](fig_787.png "fig_787")
```
The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
```
Note:

    The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
    The size of flights will be in range [0, n * (n - 1) / 2].
    The format of each flight will be (src, dst, price).
    The price of each flight will be in the range [1, 10000].
    k is in the range of [0, n - 1].
    There will not be any duplicated flights or self cycles.

#### Solution 1

BFS

C++


```
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int res = 1e9, cnt = 0;
        unordered_map<int, vector<pair<int, int>>> prices; // {src, {des, price}};
        // unordered_set<int> visited;
        queue<pair<int, int>> todo; // {dst, total price}
        todo.push({src, 0});
        for (auto& flight : flights) {
            prices[flight[0]].push_back({flight[1], flight[2]});
        }
        while (!todo.empty()) {
            for (int i = todo.size(); i > 0; --i) {
                auto t = todo.front(); todo.pop();
                if (t.first == dst) res = min(res, t.second);
                // if (!visited.count(t.first)) {
                    for (auto& price : prices[t.first]) {
                        if (t.second + price.second > res) continue;
                        todo.push({price.first, t.second + price.second});
                    }    
                // }
                // visited.insert(t.first);
            }
            if (cnt++ > K) break;
        }
        return res == 1e9 ? -1 : res;
    }
};
```

#### Solution 2

DFS

C++

```
int findCheapestPrice(int n, vector<vector<int>>& flights, int s, int d, int K) {
       unordered_map<int, vector<pair<int,int>>> g;
       for (const auto& e : flights)
            g[e[0]].emplace_back(e[1], e[2]);        
        int ans = 1e9;
        vector<int> visited(n,0);
        dfs(s, d, K + 1, 0, visited, ans, g);
        return ans == 1e9 ? - 1 : ans;
    }
    
    void dfs(int s, int d, int k, int cost, vector<int>& visited, int& ans, unordered_map<int, vector<pair<int,int>>>& g ) {
        if (s == d) { ans = cost; return; }
        if (k == 0) return; 
        visited[s]=1;
        for (const auto& x : g[s]) {
          if (visited[x.first]==0){
              if (cost + x.second > ans) continue; // IMPORTANT!!! prunning 
     
              dfs(x.first, d, k - 1, cost + x.second, visited, ans, g); 
             
          }
        }
         visited[s] = 0;
  }
```

#### Solution 3

Bellman-ford (DP)

C++

2D DP

```
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> dp(K + 2, vector<int>(n, 1e9));
        dp[0][src] = 0;
        for (int i = 1; i <= K + 1; i++) {
            dp[i][src] = 0;
            for (auto& flight : flights) {
                dp[i][flight[1]] = min(dp[i][flight[1]], dp[i - 1][flight[0]] + flight[2]);
            }
        }
        return dp[K + 1][dst] == 1e9 ? -1 : dp[K + 1][dst];
    }
};
```

1D DP Only the previous step is needed.

```
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> dp(n, 1e9);
        dp[src] = 0;
        for (int i = 1; i <= K + 1; i++) {
            vector<int> tmp = dp;
            for (auto& flight : flights) {
                dp[flight[1]] = min(dp[flight[1]], tmp[flight[0]] + flight[2]);
            }
        }
        return dp[dst] == 1e9 ? -1 : dp[dst];
    }
};
```