### 296\. [Best Meeting Point](https://leetcode.com/problems/best-meeting-point/)

A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = \|p2.x - p1.x\| + \|p2.y - p1.y\|.

Example:
```
Input: 

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

Output: 6 

Explanation: Given three people living at (0,0), (0,4), and (2,2):
             The point (0,2) is an ideal meeting point, as the total travel distance 
             of 2+2+2=6 is minimal. So return 6.
```

#### Solution 1

C++

```
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> x;
        vector<int> y;
        for (int i = 0; i < grid.size(); i++)  {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }
        
        int center_x = x[x.size() / 2];
        sort(y.begin(), y.end());
        int center_y = y[y.size() / 2];
        
        int res = 0;
        for (int i = 0; i < x.size(); i++) {
            res += abs(x[i] - center_x);
            res += abs(y[i] - center_y);
        }
        return res;
    }
};
```
