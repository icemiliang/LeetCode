### 56\. [Merge Intervals](https://leetcode.com/problems/merge-intervals/)

Given a collection of intervals, merge all overlapping intervals.

Example 1:
```
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
```

Example 2:
```
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
```

NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.


#### Solution 1

The essential idea of the merge is that if the start time is bigger than another start time but smaller 
than the other end time, then we can merge and the new end time is whichever end time is the bigger.
In order quickly find such cases, we sort the intervals according to the start time. Then, we can
scan the array from the begining to the end. If the previous end time is smaller than the current 
start time, then just keep the current interval; if not, we change the previous end time to the 
bigger one between the previous end time and the current end time.

C++

```
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty() or intervals[0].empty()) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res = {intervals[0]};
        for (int i = 1; i < intervals.size(); i++) {
            if (res.back()[1] < intervals[i][0]) {
                res.push_back(intervals[i]);
            }
            else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }    
        }
        return res;
    }
};
```

Python

```
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) == 0 or len(intervals[0]) == 0:
            return intervals
        intervals.sort()
        res = [intervals[0]]

        for i in range(1, len(intervals)):
            if res[len(res) - 1][1] < intervals[i][0]:
                res.append(intervals[i])
            else:
                res[len(res) - 1][1] = max(res[len(res) - 1][1], intervals[i][1])
        return res
```
