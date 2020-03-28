### 871\. [Minimum Number of Refueling Stops](https://leetcode.com/problems/minimum-number-of-refueling-stops/)

A car travels from a starting position to a destination which is target miles east of the starting position.

Along the way, there are gas stations.  Each station[i] represents a gas station that is station[i][0] miles east of the starting position, and has station[i][1] liters of gas.

The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it.  It uses 1 liter of gas per 1 mile that it drives.

When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.

What is the least number of refueling stops the car must make in order to reach its destination?  If it cannot reach the destination, return -1.

Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there.  If the car reaches the destination with 0 fuel left, it is still considered to have arrived.

 

Example 1:
```
Input: target = 1, startFuel = 1, stations = []
Output: 0
Explanation: We can reach the target without refueling.
```
Example 2:
```
Input: target = 100, startFuel = 1, stations = [[10,100]]
Output: -1
Explanation: We can't reach the target (or even the first gas station).
```
Example 3:
```
Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
Output: 2
Explanation: 
We start with 10 liters of fuel.
We drive to position 10, expending 10 liters of fuel.  We refuel from 0 liters to 60 liters of gas.
Then, we drive from position 10 to position 60 (expending 50 liters of fuel),
and refuel from 10 liters to 50 liters of gas.  We then drive to and reach the target.
We made 2 refueling stops along the way, so we return 2.
```

Note:

1. 1 <= target, startFuel, stations[i][1] <= 10^9
2. 0 <= stations.length <= 500
3. 0 < stations[0][0] < stations[1][0] < ... < stations[stations.length-1][0] < target

#### Solution 1

DP

C++

```
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    	int n = stations.size();
    	vector<long> dp(n + 1, startFuel); // furthest distance with i times of refueling
    	for (int k = 0; k < n; ++k) {
    		for (int i = k; i >= 0 and dp[i] >= stations[k][0]; --i) {
    			dp[i + 1] = max(dp[i + 1], dp[i] + stations[k][1]);
    		}
    	}

    	for (int i = 0; i < dp.size(); i++) {
    		if (dp[i] >= target) return i;
    	}
    	return -1;
    }
};
```

#### Solution 2

Max heap

Store fuel information in a priority queue. If we run out of fuel, refuel at
the seen station with the most fuel. If no station left, return -1.

C++

```
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int k = 0;
        int res = 0; // time of refuel
        priority_queue<int> todo; // fuel at seen but unused stations
        // refuel as long as curFuel smaller than target
        for (int curFuel = startFuel; curFuel < target; ++res) {
            while (k < stations.size() and stations[k][0] <= curFuel) {
                todo.push(stations[k++][1]);
            }
            
            // no fuel left
            if (todo.empty()) return -1;
            
            // refuel
            curFuel += todo.top(); todo.pop();
        }
        return res;
    }
};
```
