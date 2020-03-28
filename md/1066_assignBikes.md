### 1066\. [Campus Bikes II](https://leetcode.com/problems/campus-bikes-ii/)

On a campus represented as a 2D grid, there are N workers and M bikes, with N <= M. Each worker and bike is a 2D coordinate on this grid.

We assign one unique bike to each worker so that the sum of the Manhattan distances between each worker and their assigned bike is minimized.

The Manhattan distance between two points p1 and p2 is Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.

Return the minimum possible sum of Manhattan distances between each worker and their assigned bike.

 

Example 1:

![alt text](1261_example_1_v2.png)

```
Input: workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]
Output: 6
Explanation: 
We assign bike 0 to worker 0, bike 1 to worker 1. The Manhattan distance of both assignments is 3, so the output is 6.
```

Example 2:

![alt text](1261_example_2_v2.png)

```
Input: workers = [[0,0],[1,1],[2,0]], bikes = [[1,0],[2,2],[2,1]]
Output: 4
Explanation: 
We first assign bike 0 to worker 0, then assign bike 1 to worker 1 or worker 2, bike 2 to worker 2 or worker 1. Both assignments lead to sum of the Manhattan distances as 4.
```

Note:

1. 0 <= workers[i][0], workers[i][1], bikes[i][0], bikes[i][1] < 1000
2. All worker and bike locations are distinct.
3. 1 <= workers.length <= bikes.length <= 10

#### Solution 1

Time: O(mn)
Space: O(m2^n)

C++

```
class Solution {
    vector<vector<int>> dp; // [worker id][bike taken]
    
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        dp = vector<vector<int>>(10, vector<int> (1 << 10 + 1, -1));
        return assignBike(0, 0, bikes, workers);
    }

    int assignBike(int wid, int taken, vector<vector<int> >&bikes, vector<vector<int> >&workers) {
        if (wid == workers.size()) return 0;
        if (dp[wid][taken] != -1) return dp[wid][taken];
        int res = INT_MAX;
        for(int i = 0; i < bikes.size(); ++i) {
        	// if ith bike already taken
            if(taken & (1 << i)) continue;
            int d = dist(workers[wid], bikes[i]);
            res = min(res, d + assignBike(wid + 1, taken | (1 << i), bikes, workers));
        }
        return dp[wid][taken] = res;
    }
    
    int dist(vector<int>& p1, vector<int>& p2) {
    	return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
};
```


#### Solution 2

Here is how I understand this solution:
```i``` means worker ```i```.
```taken``` is a binary state representation of all bikes. each bit in ```taken``` correspond to bike's status: assigned or not
```cost``` means current distance after assign first ```i``` workers using state ```taken```.
the approach here to use BFS to iterate all ```(i, taken)``` combination and use Priority queue to do greedy search by current distance
the most important part is to iterate all ```(i, taken)``` to ```(i+1, new_taken)``` until ```i``` reach ```n``` (all workers are assigned with bike)

C++

```
class Solution {
    int dist(vector<int>& w, vector<int>& b) {
        return abs(w[0] - b[0]) + abs(w[1] - b[1]);
    }
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size(), mask = 1023;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> todo;
        unordered_set<int> visited;
        todo.push({0, 0});
        while (!todo.empty()) {
            auto t = todo.top(); todo.pop();
            int cost = t.first;
            int taken = t.second;
            if (visited.count(taken)) continue;
            visited.insert(taken);
            int i = taken >> 10;    // get the next unmatched worker id
            cout << taken << " " << i;
            taken &= mask;    // get the matching state of bikes
             cout << " " << taken << endl;
            if (i == n) return cost;
            for (int j = 0; j < m; ++j)
                if ((taken & (1 << j)) continue;
                todo.push({cost + dist(workers[i], bikes[j]), taken | (1 << j) | (i + 1 << 10)});
        }
        return 0;
    }
};
```
