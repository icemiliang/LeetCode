### 624\. [Maximum Distance in Arrays](https://leetcode.com/problems/maximum-distance-in-arrays/)

Given m arrays, and each array is sorted in ascending order. Now you can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference ```|a-b|```. Your task is to find the maximum distance.

Example 1:
```
Input: 
[[1,2,3],
 [4,5],
 [1,2,3]]
Output: 4
Explanation: 
One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
```
Note:
1. Each given array will have at least 1 number. There will be at least two non-empty arrays.
2. The total number of the integers in all the m arrays will be in the range of [2, 10000].
3. The integers in the m arrays will be in the range of [-10000, 10000].

#### Solution 1

Compute the max diff before updating the min and max to avoid using min and max
from the same array.

C++

```
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxDif = 0, curMin = INT_MAX, curMax = INT_MIN;
        for (auto& a : arrays) {
            maxDif = max(maxDif, max(a.back() - curMin, curMax - a.front()));
            curMin = min(curMin, a.front());
            curMax = max(curMax, a.back());
        }
        return maxDif;
    }
};


```

#### Solution 2

C++

```
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mn1 = INT_MAX, mx1 = INT_MIN;
        int mn2 = INT_MAX, mx2 = INT_MIN;
        int mn1_idx = -1, mx1_idx = -1;
        int mn2_idx = -1, mx2_idx = -1;

        for (int k = 0; k < arrays.size(); ++k) {
            int mx = arrays[k].back();
            int mn = arrays[k].front();
            if (mx > mx1) {
                mx2 = mx1; mx2_idx = mx1_idx;
                mx1 = mx; mx1_idx = k;
            }
            else if (mx > mx2) {
                mx2 = mx; mx2_idx = k;
            }
            if (mn < mn1) {
                mn2 = mn1; mn2_idx = mn1_idx;
                mn1 = mn; mn1_idx = k;
            }
            else if (mn < mn2) {
                mn2 = mn; mn2_idx = k;
            }
        }
        if (mx1_idx != mn1_idx) return mx1 - mn1;
        int d1 = (mx1 - mn2) * abs(mx1_idx != mn2_idx);
        int d2 = (mx2 - mn1) * abs(mx2_idx != mn1_idx);
        return max(d1, d2);
    }
};
```
