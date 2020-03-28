### 149\. [Max Points on a Line](https://leetcode.com/problems/max-points-on-a-line/)

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Example 1:
```
Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4
```

Example 2:
```
Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
Explanation:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6
```

NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.


#### Solution 1

Count the frequency of every slope starting from each point. 

Time: O(n^2)
Space: O(n)

C++

```
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int cnt = 1;
            map<pair<int, int>, int> counter;
            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int g = gcd(dx, dy);
                if (dx == 0 and dy == 0) ++cnt;
                else ++counter[{dx / g, dy / g}];
            }
            res = max(res, cnt);
            for (auto& a : counter) {
                res = max(res, a.second + cnt);
            }
        }
        return res;
    }
    
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
};
```

#### Solution 2

Use string to avoid map. Use unordered_map.

Time: O(n^2)
Space: O(n)

C++

```
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), res = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<string, int> freq; // use strings to replace slope pairs
            int cnt = 1;
            for (int j = i + 1; j < n; j++) {
            	int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int g = gcd(dx, dy);
                if (dx == 0 and dy == 0) ++cnt;
                else freq[to_string(dx / g) + '_' + to_string(dy / g)]++;
            }
            res = max(res, cnt);
            for (auto& p : freq) {
                res = max(res, p.second + cnt);
            }
        }
        return res;
    }
private:
    // int gcd(int a, int b) {
    //     while (b) {
    //         a = a % b;
    //         swap(a, b);
    //     }
    //     return a;
    // }
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
};
```

#### Solution 3

Time: O(n^3)
Space: O(1)

C++

```
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            int duplicate = 1;
            for (int j = i + 1; j < points.size(); ++j) {
                int cnt = 0;
                long long x1 = points[i][0], y1 = points[i][1];
                long long x2 = points[j][0], y2 = points[j][1];
                if (x1 == x2 and y1 == y2) {++duplicate; continue;}
                for (int k = 0; k < points.size(); ++k) {
                    int x3 = points[k][0], y3 = points[k][1];
                    if ((x1 - x3) * (y2 - y3) == (x2 - x3) * (y1 - y3)) {
                        ++cnt;
                    }
                }
                res = max(res, cnt);
            }
            res = max(res, duplicate);
        }
        return res;
    }
};
```

