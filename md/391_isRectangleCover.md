### 391\. [Perfect Rectangle](https://leetcode.com/problems/perfect-rectangle/)

Given N axis-aligned rectangles where N > 0, determine if they all together form an exact cover of a rectangular region.

Each rectangle is represented as a bottom-left point and a top-right point. For example, a unit square is represented as [1,1,2,2]. (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)).

Example 1:
![alt text](rectangle_perfect.gif)
```
rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [3,2,4,4],
  [1,3,2,4],
  [2,3,3,4]
]

Return true. All 5 rectangles together form an exact cover of a rectangular region.
``` 

Example 2:
![alt text](rectangle_separated.gif)
```
rectangles = [
  [1,1,2,3],
  [1,3,2,4],
  [3,1,4,2],
  [3,2,4,4]
]

Return false. Because there is a gap between the two rectangular regions.
```

Example 3:
![alt text](rectangle_hole.gif)
```
rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [3,2,4,4]
]

Return false. Because there is a gap in the top center.
```

Example 4:
![alt text](rectangle_intersect.gif)
```
rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [2,2,4,4]
]

Return false. Because two of the rectangles overlap with each other.
```

#### Solution 1

The idea is the area of the big rectangle should equal the sum of the areas of all small rectangles

C++

```
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        set<pair<int, int>> corners;
        int area = 0;
        for (const auto& rect : rectangles) {
            int x1 = rect[0], y1 = rect[1], x3 = rect[2], y3 = rect[3];
            pair<int, int> c1{x1, y1};
            pair<int, int> c2{x3, y1};
            pair<int, int> c3{x3, y3};
            pair<int, int> c4{x1, y3};
            for (const auto& c : {c1, c2, c3, c4}) {    
                // set.insert() returns {pointer, success}
                const auto& t = corners.insert(c); 
                if (!t.second) corners.erase(t.first); // remove shared corners
                // below is slower
                // if (corners.count(c)) corners.erase(c);
                // else corners.insert(c);
            }
            area += (x3 - x1) * (y3 - y1);
        }
        if (corners.size() != 4) return false; // four distinct, outer corners should be left
        const auto& c1 = *corners.begin();
        const auto& c3 = *corners.rbegin();  
        return area == (c3.first - c1.first) * (c3.second - c1.second);
    }
};
```
