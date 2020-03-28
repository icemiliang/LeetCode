### 332\. [Reconstruct Itinerary](https://leetcode.com/problems/reconstruct-itinerary/)

Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:
```
Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
```

Example 2:
```
Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.
```

#### Solution 1

DFS but push node to result at the end. Reverse the resulting array at the end.

C++

```
class Solution {
    unordered_map<string, multiset<string>> graph;
    vector<string> route;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets, string src = "JFK") {
        for (auto& ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }
        dfs(src);
        reverse(route.begin(), route.end());
        return route;
    }
    
    void dfs(string& src) {
        while (graph[src].size()) {
            string next = *(graph[src].begin());
            graph[src].erase(graph[src].begin());
            dfs(next);
        }
        route.push_back(src);
    }
};
```
