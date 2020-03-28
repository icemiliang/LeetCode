### 692\. [Top K Frequent Words](https://leetcode.com/problems/top-k-frequent-words/)

Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
```
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
```

Example 2:
```
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
```
Note:
1. You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
2. Input words contain only lowercase letters.

Follow up:
1. Try to solve it in O(n log k) time and O(n) extra space.


#### Solution 1

Min heap, keep a min heap of size k so that the least frequent word 
will be popped out if size > k. We also need a comparator based on
both frequency and alphabetical order.

C++

```
class Solution {
    typedef pair<string, int> pis;
    struct compare {
        bool operator() (const pis& p1, const pis& p2) const { 
            return p1.second > p2.second or (p1.second == p2.second and p1.first < p2.first); 
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (string& w : words) {
            freq[w]++;
        }
        priority_queue<pis, vector<pis>, compare> todo;
        for (auto& t : freq) {
            todo.push({t.first, t.second});
            if (todo.size() > k) todo.pop();
        }
        
        vector<string> res(k);
        for (int i = k - 1; i >= 0; i--) {
            res[i] = todo.top().first;
            todo.pop();
        }
        
        return res;
    }
};
```

#### Solution 2

Bucket sort. Bucket index is frequency. Size must be smaller than size of words.

C++

```
class Solution {
    typedef pair<string, int> psi;
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (auto& w : words) freq[w]++;
        
        vector<set<string>> bucket(words.size());
        for (auto& t : freq) {
            bucket[t.second].insert(t.first);
        }
        
        vector<string> res;
        int cnt = 0;
        for (int i = bucket.size() - 1; i >= 0; i--) {
            for (auto& t : bucket[i]) {
                res.push_back(t);
                if (++cnt >= k) return res;
            }
        }
        return res;
    }
};
```
