### 939\. [Minimum Area Rectangle](https://leetcode.com/problems/minimum-area-rectangle/)

Given a set of points in the xy-plane, determine the minimum area of a rectangle formed from these points, with sides parallel to the x and y axes.

If there isn't any rectangle, return 0.

Example 1:
```
Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
Output: 4
```

Example 2:
```
Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
Output: 2
```

Note:

1. 1 <= points.length <= 500
2. 0 <= points[i][0] <= 40000
3. 0 <= points[i][1] <= 40000
4. All points are distinct.

#### Solution 1

For each x, store its y. If two x, each having at least 2 y's and two of are the same, compute the area.

C++

```
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, set<int>> index; // x -> {y}
        for (auto& point : points) {
            index[point[0]].insert(point[1]);
        }
        
        int area = INT_MAX;
        for (int i = 0; i < points.size() - 1; i++) {
            for (int j = i + 1; j < points.size(); j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                if (x1 != x2 and y1 != y2) {
                	// same x needs at least two ys to form a rectangular
                    if (index[x1].size() > 1 and index[x2].size() > 1) {
                        if (index[x1].count(y2) and index[x2].count(y1)) {
                            area = min(area, abs((x1 - x2) * (y1 - y2)));
                        }
                    }
                }
            }
        }
        return area == INT_MAX ? 0 : area;
    }
};
```

#### Solution 2

Instead of looping the x's of the input, we can loop the hashmap.

C++

```
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, set<int>> index; // x -> {y}
        for (auto& point : points) {
            index[point[0]].insert(point[1]);
        }
        int res = INT_MAX;
        for (auto i = index.begin(); i != index.end(); i++) {
            for (auto j = next(i); j != index.end(); j++) {
            	// same x needs at least two ys to form a rectangular
                if (i->second.size() < 2 or j->second.size() < 2) continue;
                vector<int> y;
                set_intersection(i->second.begin(), i->second.end(), j->second.begin(), j->second.end(), back_inserter(y));
                for (int k = 1; k < y.size(); k++) {
                    res = min(res, abs((i->first - j->first) * (y[k] - y[k - 1])));
                }
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
```
