### 352\. [Data Stream as Disjoint Intervals](https://leetcode.com/problems/data-stream-as-disjoint-intervals/)

Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.

For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:
```
[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7]
```

Follow up:

What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?


#### Solution 1

Build an array of size 2n consisting n intervals next to each other.
For example, [0, 1, 4, 4] is two intervals [0, 1] and [4, 4].
Numbers at even indices are starts; numbers at odd indices are ends.

For addNum, add a start and an end.
For getIntervals, scan the array to push one start and one end to a new array of intervals.

Use binary search to add a start and an end. 

Complexity:
addNum: Time O(logn) Space O(1)
getIntervals: Time O(n) Space O(1)

C++

```
class SummaryRanges {
    vector<int> v;
public:
    /** Initialize your data structure here. */
    SummaryRanges() { }
    
    void addNum(int val) {
        if (v.empty()) {
            v = {val, val};
            return;
        }
        auto it = lower_bound(v.begin(), v.end(), val);
        if (it == v.begin()) {
            if (val + 1 < v[0]) {
                v.insert(v.begin(), val);
                v.insert(v.begin(), val);
            }
            else v[0] = val;
        }
        else if (it == v.end()) {
            if (val - 1 > v.back()) {
                v.push_back(val);
                v.push_back(val);
            }
            else v.back() = val;
        }
        else {
            if ((it - v.begin()) % 2 == 0) {
                auto p = prev(it);
                // connect two intervals
                if (*p + 1 == val and *it - 1 == val) {
                    int len = p - v.begin();
                    v.erase(v.begin() + len);
                    v.erase(v.begin() + len);
                }
                // extend previous interval
                else if (*p + 1 == val) *p = val;
                // extend next interval
                else if (*it - 1 == val) *it = val;
                // insert a new interval
                else if (*it != val){
                    int len = it - v.begin();
                    v.insert(v.begin() + len, val);
                    v.insert(v.begin() + len, val);
                }
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (int i = 0; i < v.size() - 1; i += 2) {
            res.push_back({v[i], v[i + 1]});
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
```


#### Solution 2

Directly build an interval array. Do binary search on the starts 
and then check different cases.

Complexity:
addNum: Time O(logn) Space O(1)
getIntervals: Time O(1) Space O(1)

C++

```
class SummaryRanges {
    // vector<int> v;
    vector<vector<int>> v;
public:
    /** Initialize your data structure here. */
    SummaryRanges() { }
    
    void addNum(int val) {
        if (v.empty()) { v = {{val, val}}; return; }
        
        int lo = 0, hi = v.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (v[mid][0] < val) lo = mid + 1;
            else hi = mid;
        }
        auto it = v.begin() + hi;
        
        if (it == v.begin()) {
            if (val + 1 < v[0][0]) {
                v.insert(v.begin(), {val, val});
            }
            else v[0][0] = val;
        }
        else if (it == v.end()) {
            if (val - 1 > v.back()[1]) {
                v.push_back({val, val});
            }
            else if (v.back()[1] + 1 == val) v.back()[1] = val;
        }
        else {
            auto p = prev(it);
            // connect two intervals
            if ((*p)[1] + 1 == val and (*it)[0] - 1 == val) {
                (*p)[1] = (*it)[1];
                v.erase(it);
            }
            // extend previous interval
            else if ((*p)[1] + 1 == val) (*p)[1] = val;
            // extend next interval
            else if ((*it)[0] - 1 == val) (*it)[0] = val;
            // insert a new interval
            else if ((*it)[0] > val and val > (*p)[1]){
                v.insert(it, {val, val});
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        return v;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
```

Use index instead of iterator

```
class SummaryRanges {
    // vector<int> v;
    vector<vector<int>> v;
public:
    /** Initialize your data structure here. */
    SummaryRanges() { }
    
    void addNum(int val) {
        if (v.empty()) { v = {{val, val}}; return; }
        
        int lo = 0, hi = v.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (v[mid][0] < val) lo = mid + 1;
            else hi = mid;
        }
        int it = hi;
        
        if (it == 0) {
            if (val + 1 < v[0][0]) {
                v.insert(v.begin(), {val, val});
            }
            else v[0][0] = val;
        }
        else if (it == v.size()) {
            if (val - 1 > v.back()[1]) {
                v.push_back({val, val});
            }
            else if (v.back()[1] + 1 == val) v.back()[1] = val;
        }
        else {
            // connect two intervals
            if (v[it - 1][1] + 1 == val and v[it][0] - 1 == val) {
                v[it - 1][1] = v[it][1];
                v.erase(v.begin() + it);
            }
            // extend previous interval
            else if (v[it - 1][1] + 1 == val) v[it - 1][1] = val;
            // extend next interval
            else if (v[it][0] - 1 == val) v[it][0] = val;
            // insert a new interval
            else if (v[it][0] > val and val > v[it - 1][1]){
                v.insert(v.begin() + it, {val, val});
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        return v;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
```
