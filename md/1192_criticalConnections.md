### 1192\. [Critical Connections in a Network](https://leetcode.com/problems/critical-connections-in-a-network/)

There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a network where connections[i] = [a, b] represents a connection between servers a and b. Any server can reach any other server directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some server unable to reach some other server.

Return all critical connections in the network in any order.
 

Example 1:
```
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
```

Constraints:

* 1 <= n <= 10^5
* n-1 <= connections.length <= 10^5
* connections[i][0] != connections[i][1]
* There are no repeated connections.

#### Solution 1

C++

```
题意：给一个无向连通图，求所有割边。
割边定义：删除这个边，连通图就不再联通，即被划分为两个独立部分。

思路：模板题，虽然我ACM出身，但是我没有怎么学习过图论题。
所以找好几个模板，都有问题，调了一个小时也没通过测试样例（实际上不应该找模板的，直接自己推理可能也做出来了）。

赛后，花了10分钟了解了一下 Tarjan 算法，然后五分钟就把这道题过了。

Tarjan 思想：
对于一个连通图，递归可以访问到所有顶点和边。

 ------------
|            |
1 --- 2 ---- 3
      |
	  |
      |
	  4 --- 5
	  |     |
       ---- 6
而对于割边，例如2-4，递归的时候，2-4递归的所有顶点都大于2。
而对于非割边，比如5-6，递归的时候，6可以找到更小的4。

总结一下就是，这个边递归找的最小编号都比自己大，那这个边就是割边，否则不是割边。

所以我们需要做的就是递归寻找每个顶点能够到达的最小编号，然后比大小即可。

PS：大家忽略树的数据结构，这种储存是邻接表，用于储存稀疏矩阵，实际上和Vector<vector<int>>等价的。

代码

const int MAXN=100010;
const int MAXM=100010;

class Solution {
    //树的数组形式储存
    int Head[MAXN], Next[MAXM*2], To[MAXM*2]; 
    int n,tot;
    
    //dfn 储存每个定点的唯一编号
    //low 储存当前定点能到达的最小编号
    int dfn[MAXN],low[MAXN];
    
    int numIndex,numCutedge; //答案
    struct Edge{
        int u,v;
    }cutedge[MAXM];

    void Tarjan(int u,int pre = -1) {
        if(dfn[u] != -1) return;
        dfn[u] = low[u] = ++numIndex;//分配唯一编号
        
        for (int i = Head[u]; i != -1; i = Next[i]) {
            int v=To[i];
            if(v == pre)continue;
            Tarjan(v, u);
            
            low[u] = min(low[u], low[v]);//如有有更小编号，更新
            if (low[v] > dfn[u]) {
                cutedge[numCutedge++] = {u, v}; //找到一个答案
            } 
        }
    }
    
    void solve(){
        memset(dfn,-1,sizeof(dfn));
        memset(low,-1,sizeof(low));
        numCutedge = 0;
        numIndex = 0;
        Tarjan(0); //由于是连通图，随便找个定点开始搜就行了
    }
    void Outit(vector<vector<int>>& ans){
        for (int i = 0; i < numCutedge; i++){
            ans.push_back({cutedge[i].u,cutedge[i].v});
        }
    }
    void add_eage(int x, int y){
        tot++;
        Next[tot] = Head[x];
        Head[x] = tot;
        To[tot] = y;
    }
    void ReadInfo(int n, vector<vector<int>>& conn){
        memset(Head, -1, sizeof(Head));
        tot = 0;
        this->n = n;
        for(auto&v: conn){
            int x = v[0];
            int y = v[1];
            add_eage(x,y); 
            add_eage(y,x);
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
        ReadInfo(n, conn);
        solve();
        
        vector<vector<int>> ans;
        Outit(ans);
        return ans;
    }
};
```

A simplified version, run time longer

The main idea is that there is a bridge,
then when using dfs, after crossing the bridge,
cannot go back thus all the nodes on one side of
the bridge will have larger index

```
class Solution {
    // smallest index the current node can reach
    vector<int> dfn, low;
    vector<vector<int>> graph, bridges;
    
    void dfs(int idx, int u, int pre) {
        if (dfn[u] != -1) return;
        dfn[u] = low[u] = ++idx; // new traverse index

        for (int v : graph[u]) {
            if (v == pre) continue;
            dfs(idx, v, u);
            low[u] = min(low[u], low[v]);
            
            if (low[v] > dfn[u]) {
                // if max index the current node can reach 
                // is smaller than its own index 
                // then this is a cricical connection
                bridges.push_back({u, v});
            } 
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph.resize(n);
        for(auto& e : connections){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        dfn.resize(n, -1);
        low.resize(n, -1);
        dfs(0, 0, -1);
        return bridges;
    }
};
```


#### Solution 2

Bridge finding

[https://www.geeksforgeeks.org/bridge-in-a-graph/](https://www.geeksforgeeks.org/bridge-in-a-graph/)

C++ 

```
// A C++ program to find bridges in a given undirected graph 
#include<iostream> 
#include <list> 
#define NIL -1 
using namespace std; 
  
// A class that represents an undirected graph 
class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;    // A dynamic array of adjacency lists 
    void bridgeUtil(int v, bool visited[], int disc[], int low[], 
                    int parent[]); 
public: 
    Graph(int V);   // Constructor 
    void addEdge(int v, int w);   // to add an edge to graph 
    void bridge();    // prints all bridges 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v);  // Note: the graph is undirected 
} 
  
// A recursive function that finds and prints bridges using 
// DFS traversal 
// u --> The vertex to be visited next 
// visited[] --> keeps tract of visited vertices 
// disc[] --> Stores discovery times of visited vertices 
// parent[] --> Stores parent vertices in DFS tree 
void Graph::bridgeUtil(int u, bool visited[], int disc[],  
                                  int low[], int parent[]) 
{ 
    // A static variable is used for simplicity, we can  
    // avoid use of static variable by passing a pointer. 
    static int time = 0; 
  
    // Mark the current node as visited 
    visited[u] = true; 
  
    // Initialize discovery time and low value 
    disc[u] = low[u] = ++time; 
  
    // Go through all vertices aadjacent to this 
    list<int>::iterator i; 
    for (i = adj[u].begin(); i != adj[u].end(); ++i) 
    { 
        int v = *i;  // v is current adjacent of u 
  
        // If v is not visited yet, then recur for it 
        if (!visited[v]) 
        { 
            parent[v] = u; 
            bridgeUtil(v, visited, disc, low, parent); 
  
            // Check if the subtree rooted with v has a  
            // connection to one of the ancestors of u 
            low[u]  = min(low[u], low[v]); 
  
            // If the lowest vertex reachable from subtree  
            // under v is  below u in DFS tree, then u-v  
            // is a bridge 
            if (low[v] > disc[u]) 
              cout << u <<" " << v << endl; 
        } 
  
        // Update low value of u for parent function calls. 
        else if (v != parent[u]) 
            low[u]  = min(low[u], disc[v]); 
    } 
} 
  
// DFS based function to find all bridges. It uses recursive  
// function bridgeUtil() 
void Graph::bridge() 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    int *disc = new int[V]; 
    int *low = new int[V]; 
    int *parent = new int[V]; 
  
    // Initialize parent and visited arrays 
    for (int i = 0; i < V; i++) 
    { 
        parent[i] = NIL; 
        visited[i] = false; 
    } 
  
    // Call the recursive helper function to find Bridges 
    // in DFS tree rooted with vertex 'i' 
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            bridgeUtil(i, visited, disc, low, parent); 
} 
  
// Driver program to test above function 
int main() 
{ 
    // Create graphs given in above diagrams 
    cout << "\nBridges in first graph \n"; 
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.bridge(); 
  
    cout << "\nBridges in second graph \n"; 
    Graph g2(4); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.addEdge(2, 3); 
    g2.bridge(); 
  
    cout << "\nBridges in third graph \n"; 
    Graph g3(7); 
    g3.addEdge(0, 1); 
    g3.addEdge(1, 2); 
    g3.addEdge(2, 0); 
    g3.addEdge(1, 3); 
    g3.addEdge(1, 4); 
    g3.addEdge(1, 6); 
    g3.addEdge(3, 5); 
    g3.addEdge(4, 5); 
    g3.bridge(); 
  
    return 0; 
} 
```

#### Solution 3

```
class Solution {
public:
    map< int ,vector< int > > graph ;
    int time_stamp = 1 ;  
    struct Vetex {
        int index ;  // time_stamp 
        int lowlink ; // The earliest point that can be reached by a non-father node
    };
    vector< Vetex > check ;
    vector< vector<int> > ans ; 
    void dfs( int v , int parent ) {

        check[v].index = time_stamp ; 
        check[v].lowlink = time_stamp ;
        time_stamp ++ ;

        for( auto &w : graph[v] ){
            if ( w == parent ) continue ; 
            if ( check[w].index == 0 ){ // not visited
                dfs( w , v ) ; 
                // calc The earliest point that can be reached by a non-father node
                check[v].lowlink = min( check[v].lowlink , check[w].lowlink ) ; 
                if ( check[w].lowlink > check[v].index ) // this must be a bridge 
                    ans.push_back( {v,w } ) ; 
            }  else {
                check[v].lowlink = min( check[v].lowlink , check[w].index ) ; 
            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        check.resize( n+1 ) ; 
        // construct graph 
        for( auto &edge : connections ) {
            graph[edge[0]].push_back( edge[1] ) ; 
            graph[edge[1]].push_back( edge[0] ) ; 
        }
        for( int i=0 ; i< n ; i++ ) 
            if ( check[i].index == 0 ) // not visited 
                dfs( i , -1 ) ; 
        return ans ; 
    }
};
```

#### Solution 4

C++

```
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n, false);
        vector<int> disc(n, 0), low(n, 0), parent(n, -1);
        vector<vector<int>> graph(n, vector<int>());
        vector<vector<int>> res;
        for (auto& p : connections) {
            graph[p.front()].push_back(p.back());
            graph[p.back()].push_back(p.front());
        }
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            dfs(i, visited, disc, low, parent, graph, res);
        }
        return res;
    }

    void dfs(int u, vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<vector<int>>& graph, vector<vector<int>>& res) {
        static int time = 0;
        visited[u] = true;
        disc[u] = low[u] = ++time;
        for (int v : graph[u]) {
            if (!visited[v]) {
                parent[v] = u;
                dfs(v, visited, disc, low, parent, graph, res);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    res.push_back({u, v});
                }

            } else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
};
```
