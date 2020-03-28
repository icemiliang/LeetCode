### 475\. [Heaters](https://leetcode.com/problems/heaters/)

Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.

Note:

Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
As long as a house is in the heaters' warm radius range, it can be warmed.
All the heaters follow your radius standard and the warm radius will the same.
 

Example 1:
```
Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
```

Example 2:
```
Input: [1,2,3,4],[1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.
```

#### Solution 1

The idea is to find the maximum distance from a house and a heater. Thus, we can find 
for each house the minimum distance to a heater and then return the maximum of such
distances. If the heater array is sorted, then we only need to find which two heaters 
a house is in between and take the smaller distance. Just be careful when the house 
is on the left to all the heaters or on the right to all the heaters.

C++

```
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int res = 0, n = heaters.size();
        sort(heaters.begin(), heaters.end());
        for (int house : houses) {
            int left = 0, right = n;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (heaters[mid] < house) left = mid + 1;
                else right = mid;
            }
            int dist1 = (right == n) ? INT_MAX : heaters[right] - house;
            int dist2 = (right == 0) ? INT_MAX : house - heaters[right - 1];
            res = max(res, min(dist1, dist2));
        }
        return res;
    }
};
```

Python 

```
class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        res = 0
        n = len(heaters)
        heaters.sort()
        for house in houses:
            left = 0
            right = n
            while left < right:
                mid = left + (right - left) // 2
                if house > heaters[mid]:
                    left = mid + 1
                else:
                    right = mid
            dist1 = float('inf') if right == 0 else house - heaters[right - 1]
            dist2 = float('inf') if right == n else heaters[right] - house
            res = max(res, min(dist1, dist2))
        return res
```

#### Solution 2

There is another solution that sorts both arrays and use two pointers to
loop both arrays which we will cover later.
