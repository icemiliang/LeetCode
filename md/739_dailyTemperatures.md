### 739\. [Daily Temperatures](https://leetcode.com/problems/daily-temperatures/submissions/)

Given a list of daily temperatures T, return a list such that,
for each day in the input, tells you how many days you would 
have to wait until a warmer temperature. If there is no future
day for which this is possible, put 0 instead.

For example, given the list of temperatures 
```T = [73, 74, 75, 71, 69, 72, 76, 73]```, your output should
be ```[1, 1, 4, 2, 1, 1, 0, 0]```.

Note: The length of temperatures will be in the range [1, 30000].
Each temperature will be an integer in the range [30, 100].


#### Solution 1

Use a (descending) stack to store the current date to be returned.
Loop from the first day to the last. 
Push each day index into the stack.
If the current temp is bigger than temp[top of the stack],
then pop the top and put the diff [i-top] to the result. [top] day is done.

C++

```
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> todo; // {index}
        vector<int> res(T.size());
        for (int i = 0; i < T.size(); ++i) {
            while (!todo.empty() and T[todo.top()] < T[i]) {
                res[todo.top()] = i - todo.top();
                todo.pop();
            }
            todo.push(i);
        }
        return res;
    }
};
```

#### Solution 2

Start from the end and find the first bigger element to the right.
The shortcut is to use the previous solution to increment the index.

C++

```
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size());
        for (int i = T.size() - 1; i >= 0; --i) {
            int j = i + 1;
            while (j < T.size() and T[j] <= T[i]) {
                if (res[j] > 0) j = res[j] + j;
                else j = T.size();
            }
            // either j == size || T[j] > T[i]
            if (j < T.size()) res[i] = j - i;
        }
        return res;
    }
};
```
