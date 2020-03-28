### 356\. [Line Reflection](https://leetcode.com/problems/line-reflection/)

Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.

Example 1:
```
Input: [[1,1],[-1,1]]
Output: true
```

Example 2:
```
Input: [[1,1],[-1,-1]]
Output: false
```

Follow up:
Could you do better than O(n^2) ?

#### Solution 1

Find mid point. Mid is mean of max and min. 
For each x, find its image.
If no image, return false.

C++

```
class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        unordered_map<int, set<int>> m; // x -> y
        int mx = INT_MIN, mn = INT_MAX;
        for (const auto& a : points) {
            mx = max(mx, a[0]);
            mn = min(mn, a[0]);
            m[a[0]].insert(a[1]);
        }
        double mid = (double)(mx + mn);
        for (const auto& a : points) {
            int t = mid - a[0];
            if (!m.count(t) or !m[t].count(a[1])) {
                return false;
            }
        }
        return true;
    }
}; 
```

#### Solution 2

Mid is mean.
This solution does not count ```[[1,1],[-1,1],[-1,1]]``` as true.

C++

```
class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        if (points.empty()) return true;
        set<vector<int>> pts;
        double y = 0;
        for (auto& a : points) {
            pts.insert({a[0], a[1]});
            y += a[0];
        }
        y /= points.size();
        for (auto& a : pts) {
            if (!pts.count({y * 2 - a[0], a[]})) {
                return false;
            }
        }
        return true;
    }
}; 
```
