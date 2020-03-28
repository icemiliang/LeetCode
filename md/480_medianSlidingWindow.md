### 480\. [Sliding Window Median](https://leetcode.com/problems/sliding-window-median/)

Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples:
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Your job is to output the median array for each window in the original array.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
```
Window position                Median
---------------               -----
[1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6
```

Therefore, return the median sliding window as [1,-1,-1,3,5,6].

Note:
You may assume k is always valid, ie: k is always smaller than input array's size for non-empty array.

#### Solution 1

Small, large queues and a hashmap storing elements that should have been discarded but 
are not the tops so we keep their counts in hashmap and whenever they became the top
discard them. This is OK because each time we compute the median only from the tops.
As long as the tops are correct, the elements behind them do not affect the result.

C++

```
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> hash;                          // count numbers to be deleted
        priority_queue<int, vector<int>> small;                // heap on the bottom
        priority_queue<int, vector<int>, greater<int>> large;  // heap on the top
        
        int pos = 0;
        
        // Initialize the heaps
        while (pos < k)  { small.push(nums[pos++]); }
        for (int count = k/2; count > 0; --count) {
            large.push(small.top()); 
            small.pop();
        }
        
        vector<double> medians;
        while (true) {
            // Get median
            if (k % 2) medians.push_back(small.top());
            else medians.push_back( ((double)small.top() + large.top()) / 2 );
            
            if (pos == nums.size()) break;
            int out = nums[pos - k];
            int in = nums[pos++];
            int balance = 0; // keep small and large queues same size
            
            // move out
            if (out <= small.top())  { 
                --balance;  
                if (out == small.top()) small.pop(); 
                else ++hash[out]; 
            }
            else { 
                ++balance;  
                if (out == large.top()) large.pop(); 
                else ++hash[out]; 
            }
            
            // move in
            if (!small.empty() and in <= small.top()) { 
                ++balance; // small queue grows by 1
                small.push(in); 
            }
            else { 
                --balance; // large queue grows by 1
                large.push(in); 
            }
            
            // Rebalance small and large
            if (balance < 0) { 
                small.push(large.top()); 
                large.pop(); 
            }
            else if (balance > 0) { 
                large.push(small.top()); 
                small.pop(); 
            }
            
            // Discard out from small and large queues
            // these numbers could be out in previous steps 
            // but it does not change the result because 
            // each time we only look at the tops of small and large
            while (!small.empty() and hash[small.top()]) { 
                --hash[small.top()]; 
                small.pop(); 
            }
            while (!large.empty() and hash[large.top()]) { 
                --hash[large.top()]; 
                large.pop(); 
            }
        }
        
        return medians;
    }
};
```

#### Solution 2

Another solution using multiset.

C++

```
vector<double> medianSlidingWindow(vector<int>& nums, int k)
{
    int size = nums.size(), median_pos = k - k / 2 - 1;
    vector<double> res(size - k + 1);
    multiset<int> s(nums.begin(), nums.begin() + k);
    auto it = next(s.begin(), median_pos);

    for (auto i = k; i <= size; ++i)
    {
        res[i - k] = ((double)*it + (k % 2 != 0 ? *it : *next(it))) / 2;
        if (i < size)
        {
            // magic numbers (instead of enum) for brevity. INT_MAX means to retrace the iterator from the beginning.
            int repos_it = INT_MAX; 
            if (k > 2)
            {
                // if inserted or removed item equals to the current median, we need to retrace.
                // we do not know which exact element will be removed/inserted, and we cannot compare multiset iterators.
                // otherwise, we can keep or increment/decrement the current median iterator.
                if ((nums[i - k] < *it && nums[i] < *it) || (nums[i - k] > *it && nums[i] > *it)) repos_it = 0;
                else if (nums[i - k] < *it && nums[i] > *it) repos_it = 1; // advance forward.
                else if (nums[i - k] > *it && nums[i] < *it) repos_it = -1; // advance backward.
            }
            s.insert(nums[i]);
            s.erase(s.find(nums[i - k]));

            if (repos_it == INT_MAX) it = next(s.begin(), median_pos);
            else if (repos_it == 1) ++it;
            else if (repos_it == -1) --it;
        }
    }
    return res;
}
```

#### Solution 3

C++

```
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<double> ms(nums.begin(), nums.begin() + k);
        auto mid = next(ms.begin(), k /  2);
        for (int i = k; ; ++i) {
            res.push_back((*mid + *prev(mid,  1 - k % 2)) / 2);        
            if (i == nums.size()) return res;
            ms.insert(nums[i]);
            if (nums[i] < *mid) --mid;
            if (nums[i - k] <= *mid) ++mid;
            ms.erase(ms.lower_bound(nums[i - k]));
        }
    }
};
```
