### 57\. [Insert Interval](https://leetcode.com/problems/insert-interval/)

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
```
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
```
Example 2:
```
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
```
*NOTE*: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

#### Solution 1

Linear search

C++

```
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return vector<vector<int>> ({newInterval});
        vector<vector<int>> res;
        int index = 0;
        while (index < intervals.size() and intervals[index][1] < newInterval[0]) {
            res.push_back(intervals[index++]);
        }
        
        while(index < intervals.size() && intervals[index][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[index][0]);
            newInterval[1] = max(newInterval[1], intervals[index][1]);
            ++index;
        }
        
        res.push_back(newInterval);
        while (index < intervals.size()) {
            res.push_back(intervals[index++]);
        }
        return res;
    }
};
```


#### Solution 2

My own slow solution using binary search

C++

```
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        
        // push previous intervals
        int last = 0;
        while (last < intervals.size() and intervals[last][0] < newInterval[0]) {
            res.push_back(intervals[last++]);
        }
        
        // insert new interval
        if (res.empty() or newInterval[0] > res.back()[1]) {
            res.push_back(newInterval);
        }
        else res.back()[1] = newInterval[1];
        
        // find next interval
        int lo = last, hi = intervals.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (intervals[mid][0] < res.back()[1]) lo = mid + 1;
            else hi = mid;
        }
        
        // if no intervals left
        if (hi == intervals.size()) {
            if (hi != 0) res.back()[1] = max(res.back()[1], intervals.back()[1]);
            return res;
        }
        
        // if end == next start
        if (intervals[hi][0] == res.back()[1]) {
            res.back()[1] = intervals[hi][1];
            ++hi;
        }
        // if end < next start and end < previous end
        else if (hi > 0 and intervals[hi - 1][1] > res.back()[1]) {
            res.back()[1] = intervals[hi - 1][1];
        }
        
        // push the rest of the intervals
        while (hi < intervals.size()) {
            res.push_back(intervals[hi++]);
        }
        return res;
    }
};
```

Another way of doing it though it modifies the input.

```
class Solution {
public:
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0) return {newInterval};
        auto compare = [] (const vector<int>&intv1, const vector<int>&intv2)
                          { return intv1[1] < intv2[0]; };
        auto range = equal_range(intervals.begin(), intervals.end(), newInterval, compare);
        auto itr1 = range.first, itr2 = range.second;
        if (itr1 == itr2) {
            intervals.insert(itr1, newInterval);
        } else {
            itr2--;
            *(itr2->begin()+0) = min(newInterval[0], *(itr1->begin()+0));
            *(itr2->begin()+1) = max(newInterval[1], *(itr2->begin()+1));
            intervals.erase(itr1, itr2);
        }
        return intervals;
}
};
```
