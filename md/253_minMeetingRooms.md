### 253\. [Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/)

Given an array of meeting time intervals consisting of start and end times ```[[s1,e1],[s2,e2],...]``` \(si < ei\), find the minimum number of conference rooms required.

Example 1:
```
Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
```
Example 2:
```
Input: [[7,10],[2,4]]
Output: 1
```
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

#### Solution 1

Priority queue storing ending time of each room.

C++

```
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> rooms; // end time for each room
        // if the room that ends the earliest cannot accomadate, start a new room
        for (auto& interval : intervals) {
            if (!rooms.empty() and rooms.top() <= interval[0]) rooms.pop();
            rooms.push(interval[1]);
        }
        return rooms.size();
    }
};
```

```
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> endTimes;
        endTimes.push(intervals[0][1]);
        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= endTimes.top()) endTimes.pop();
            endTimes.push(intervals[i][1]);
        }
        return endTimes.size();
    }
};
```
