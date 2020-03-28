### 347\. [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)

Given a non-empty array of integers, return the k most frequent elements.

Example 1:
```
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
```
Example 2:
```
Input: nums = [1], k = 1
Output: [1]
```
Note:

* You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
* Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

#### Solution 1

hashmap + priority queue

1. Build a hashmap of unique elements and their frequencies.
2. Push the hashmap into a priority queue.
3. Pop the top k pairs.

```
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for (auto num : nums) m[num]++;
        priority_queue<pair<int,int>> q;
        vector<int> res;
        for (auto it : m) q.push({it.second,it.first});
        for (int i = 0; i < k; i++) {
            res.push_back(q.top().second); q.pop();
        }
        return res;
    }
};
```

#### Solution 2

Implement compare funtion myself.

```
class Solution {
public:   
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for (int num : nums) m[num]++;
        auto cmp = [](pair<int,int> p1, pair<int,int> p2) { return p1.first < p2.first; };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> q(cmp);
        for (auto it : m) q.push({it.second, it.first});
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(q.top().second); q.pop();
        }
        return res;
    }
};
```

#### Solution 3

hashmap + bucket

1. Build a hashmap of unique elements and their frequencies.
2. Build a bunch of buckets accoding to frequency. The ith bucket
   contains the keys that occurs i times.
3. Pop the elements from the 0th bucket for k times.

```
class Solution {
public:   
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for (auto num : nums) m[num]++;
        vector<int> res;
        vector<vector<int>> buckets(nums.size()+1);
        for (auto it : m) buckets[it.second].push_back(it.first);
        for (int i = buckets.size()-1; i >=0; i--) {
            for (int j = 0; j < buckets[i].size(); j++) {
                res.push_back(buckets[i][j]);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};
```

#### Solution 4

Selection sort

C++

```
class Solution {
    typedef pair<int, int> pii;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        if (!nums.size()) return res;
        unordered_map<int, int> cnt;
        for (auto num : nums) cnt[num]++;
        vector<pii> num_with_cnt;
        for (auto kv : cnt) {
            num_with_cnt.push_back({kv.first, kv.second});
        }
        kselection(num_with_cnt, 0, num_with_cnt.size()-1, k);
        for (int i = 0; i < k && i < num_with_cnt.size(); ++i) {
            res.push_back(num_with_cnt[i].first);
        }
        return res;
    }

    void kselection(vector<pii>& data, int start, int end, int k) {

        if (start >= end) return;
        auto pv = data[end];
        int i = start;
        int j = start;
        while (i < end) {
            if (data[i].second > pv.second) {
                swap(data[i++], data[j++]);
            } else {
                ++i;
            }
        }
        swap(data[j], data[end]);
        int num = j - start + 1;
        if (num == k) return;
        else if (num < k) {
            kselection(data, j + 1, end, k - num);
        } else {
            kselection(data, start, j - 1, k);
        }
    }
};
```
