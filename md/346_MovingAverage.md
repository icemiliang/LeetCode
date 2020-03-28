### 346\. [Moving Average from Data Stream](https://leetcode.com/problems/moving-average-from-data-stream/)

Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Example:
```
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
```

#### Solution 1

C++

```
class MovingAverage {
    int cap = 0;
    int cnt = 0;
    int sum = 0;
    queue<int> todo;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        cap = size;
    }
    
    double next(int val) {
        ++cnt;
        sum += val;
        todo.push(val);
        if (cnt > cap) {
            --cnt;
            sum -= todo.front();
            todo.pop();
        }
        return double(sum) / cnt;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
```
