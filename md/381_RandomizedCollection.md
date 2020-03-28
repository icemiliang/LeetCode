### 381\. [Insert Delete GetRandom O(1) - Duplicates allowed](https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/)

Design a data structure that supports all following operations in average O(1) time.

Note: Duplicate elements are allowed.
insert(val): Inserts an item val to the collection.
remove(val): Removes an item val from the collection if present.
getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.
Example:
```
// Init an empty collection.
RandomizedCollection collection = new RandomizedCollection();

// Inserts 1 to the collection. Returns true as the collection did not contain 1.
collection.insert(1);

// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
collection.insert(1);

// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
collection.insert(2);

// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
collection.getRandom();

// Removes 1 from the collection, returns true. Collection now contains [1,2].
collection.remove(1);

// getRandom should return 1 and 2 both equally likely.
collection.getRandom();
```

#### Solution 1

C++

```
class RandomizedCollection {
    vector<pair<int, int>> _v; // {val, idx in map array}
    unordered_map<int, vector<int>> _m; // {val -> {idx in array}}
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool find = _m.find(val) != _m.end();
        _m[val].push_back(_v.size());
        _v.push_back({val, _m[val].size() - 1});
        return !find;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        bool find = _m.find(val) != _m.end();
        if (find) {
            auto t = _v.back();
            int pos = _m[val].back(); // idx in array
            _v[pos] = t; // put last pair to removed pair
            _m[t.first][t.second] = pos; // new idx of the originally last pair
            _v.pop_back();
            _m[val].pop_back();
            if (_m[val].empty()) _m.erase(val);
        }
        return find;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return _v[rand() % _v.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
```
