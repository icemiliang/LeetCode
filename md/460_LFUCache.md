### 460\. [LFU Cache](https://leetcode.com/problems/lfu-cache/)

Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

Note that the number of times an item is used is the number of calls to the get and put functions for that item since it was inserted. This number is set to zero when the item is removed.

Follow up:
Could you do both operations in O(1) time complexity?

Example:
```
LFUCache cache = new LFUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.get(3);       // returns 3.
cache.put(4, 4);    // evicts key 1.
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
```

#### Solution 1

C++

```
class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (m.count(key) == 0) return -1;
        freq[m[key].second].erase(iter[key]);
        m[key].second++;
        freq[m[key].second].push_back(key);
        iter[key] = freq[m[key].second].end()--;
        if (freq[minFreq].size() == 0) minFreq++;
        return m[key].first;
    }
    
    void put(int key, int value) {
        if (cap <= 0) return;
        if (get(key) != -1) {
            m[key].first = value;
            return;
        }
        if (m.size() >= cap) {
            m.erase(freq[minFreq].front());
            iter.erase(freq[minFreq].front());
            freq[minFreq].pop_front();
        }
        m[key] = {value, 1};
        freq[1].push_back(key);
        iter[key] = freq[1].end()--;
        minFreq = 1;
    }

private:
    int cap, minFreq;
    unordered_map<int, pair<int, int>> m;
    unordered_map<int, list<int>> freq;
    unordered_map<int, list<int>::iterator> iter;
};
```

#### Solution 2

C++

```
class LFUCache {
    
    struct Node{
        int key;
        int val;
        int freq;
        Node(int k, int v, int f) { key = f; val = v; freq = f; };
    };
    
    int cap, minFreq;
    unordered_map<int, list<pair<pair<int, int>, int>>> freq; // freq->{((key, value), freq)}
    unordered_map<int, list<pair<pair<int, int>, int>>::iterator> iter; // key->((key, value), freq)
public:
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (iter.count(key) == 0) return -1;
        auto t = iter[key];
        int f = t->second;
        int value = t->first.second;
        freq[f].erase(iter[key]);
        f++;
        freq[f].push_back({{key, value}, f});
        iter[key] = --freq[f].end();
        if (freq[minFreq].size() == 0) minFreq++;
        return iter[key]->first.second;
    }
    
    void put(int key, int value) {
        if (cap <= 0) return;
        if (iter.count(key)) {
            auto t = iter[key];
            int f = t->second;
            freq[f].erase(t);
            f++;
            freq[f].push_back({{key, value}, f});
            iter[key] = --freq[f].end();
            if (freq[minFreq].size() == 0) minFreq++;
        }
        else {
            if (iter.size() >= cap) {
                int k = freq[minFreq].front().first.first;
                freq[minFreq].pop_front();
                iter.erase(k);
            }
            freq[1].push_back({{key, value}, 1});
            iter[key] = --freq[1].end();
            minFreq = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
