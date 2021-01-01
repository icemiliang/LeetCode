### 1167\. [Minimum Cost to Connect Sticks](https://leetcode.com/problems/minimum-cost-to-connect-sticks/)

You have some sticks with positive integer lengths.

You can connect any two sticks of lengths X and Y into one stick by paying a cost of X + Y.  You perform this action until there is one stick remaining.

Return the minimum cost of connecting all the given sticks into one stick in this way.

Example 1:
```
Input: sticks = [2,4,3]
Output: 14
```

Example 2:
```
Input: sticks = [1,8,3,5]
Output: 30
```

Constraints:

* 1 <= sticks.length <= 10^4
* 1 <= sticks[i] <= 10^4

#### Solution 1

Priority queue

Time: O(nlogn)  
Space: O(n)

C++

```
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> todo(sticks.begin(), sticks.end());
        int res = 0;
        while (todo.size() > 1) {
            int t1 = todo.top(); todo.pop();
            int t2 = todo.top(); todo.pop();
            todo.push(t1 + t2);
            res += t1 + t2;
        }
        return res;
    }
};
```
