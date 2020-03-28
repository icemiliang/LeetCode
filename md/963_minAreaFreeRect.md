### 963\. [Minimum Area Rectangle II](https://leetcode.com/problems/minimum-area-rectangle-ii/)

Given a set of points in the xy-plane, determine the minimum area of any rectangle formed from these points, with sides not necessarily parallel to the x and y axes.

If there isn't any rectangle, return 0.

Example 1:
![alt text](1a.png "1a.png")
```
Input: [[1,2],[2,1],[1,0],[0,1]]
Output: 2.00000
Explanation: The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1], with an area of 2.
```
Example 2:
![alt text](2.png "2.png")
```
Input: [[0,1],[2,1],[1,1],[1,0],[2,0]]
Output: 1.00000
Explanation: The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0], with an area of 1.
```
Example 3:
![alt text](3.png "3.png")
```
Input: [[0,3],[1,2],[3,1],[1,3],[2,1]]
Output: 0
Explanation: There is no possible rectangle to form from these points.
```
Example 4:
![alt text](4c.png "4c.png")
```
Input: [[3,1],[1,1],[0,1],[2,1],[3,3],[3,2],[0,2],[2,3]]
Output: 2.00000
Explanation: The minimum area rectangle occurs at [2,1],[2,3],[3,3],[3,1], with an area of 2.
```

Note:

1. ```1 <= points.length <= 50```
2. ```0 <= points[i][0] <= 40000```
3. ```0 <= points[i][1] <= 40000```
4. All points are distinct.
5. Answers within 10^-5 of the actual value will be accepted as correct.

#### Solution 1

https://leetcode.com/problems/minimum-area-rectangle-ii/discuss/210786/C%2B%2B-with-picture-find-diagonals-O(n-*-n)

C++

```
class Solution {
public:
    size_t d2(int x1, int y1, int x2, int y2) { 
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }
    
    double minAreaFreeRect(vector<vector<int>>& ps) {
        size_t res = 0;
        unordered_map<size_t, vector<vector<int>>> m;
        for (auto i = 0; i < ps.size(); ++i) {
            for (auto j = i + 1; j < ps.size(); ++j) {
                auto center = ((size_t)(ps[i][0] + ps[j][0]) << 16) + ps[i][1] + ps[j][1];
                m[center].push_back({ps[i][0], ps[i][1], ps[j][0], ps[j][1]});
            }
        }
            
        for (auto it = begin(m); it != end(m); ++it) {
            for (auto i = 0; i < it->second.size(); ++i) {
                for (auto j = i + 1; j < it->second.size(); ++j) {
                    auto &p1 = it->second[i], &p2 = it->second[j];
                    if ((p1[0] - p2[0]) * (p1[0] - p2[2]) + (p1[1] - p2[1]) * (p1[1] - p2[3]) == 0) {
                        auto area = d2(p1[0], p1[1], p2[0], p2[1]) * d2(p1[0], p1[1], p2[2], p2[3]);
                        if (res == 0 or res > area) res = area;
                    }
                }
            }
        }

        return sqrt(res);
    }
};
```

A different way to defining the hashmap

```
class Solution {
public:
    string getKey(int a, int b) {
        return to_string(a) + " " + to_string(b);
    }
    
    double minAreaFreeRect(vector<vector<int>>& points) {
        unordered_set<string> pts;
        for (auto& p : points) pts.insert(getKey(p[0], p[1]));
        double res = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                for (int k = j + 1; k < points.size(); k++) {
                    if (i == k) continue;
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[j][0], y2 = points[j][1];
                    int x3 = points[k][0], y3 = points[k][1];
                    if ((x1 - x2) * (x2 - x3) + (y1 - y2) * (y2 - y3) != 0) continue;
                    int x4 = -x2 + x1 + x3, y4 = -y2 + y1 + y3;
                    if (pts.count(getKey(x4, y4))) {
                        double w = pow(x2 - x1, 2) + pow(y2 - y1, 2);
                        double l = pow(x3 - x2, 2) + pow(y3 - y2, 2);
                        double area = w * l;
                        if (res == 0 or area < res) res = area;
                    }
                }
            }
        }
        return sqrt(res);
    }
};
```

Python 

```
def minAreaFreeRect(self, points):
    points = [complex(*z) for z in sorted(points)]
    seen = collections.defaultdict(list)
    for P, Q in itertools.combinations(points, 2):
        seen[Q - P].append((P + Q) / 2)

    ans = float("inf")
    for A, candidates in seen.iteritems():
        for P, Q in itertools.combinations(candidates, 2):
            if A.real * (P - Q).real == -A.imag * (P - Q).imag:
                ans = min(ans, abs(A) * abs(P - Q))
    return ans if ans < float("inf") else 0
```
