### 380\. [Insert Delete GetRandom O(1)](https://leetcode.com/problems/insert-delete-getrandom-o1/)

Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();


#### Solution 1

The catch of the problem is to return a true random value in O(1) time.

Using a vector to store the values dose not support remove in O(1).
Using a hashmap to store the values does not support getRandom in O(1).
Using a linked list does not support either remove or getRandom in O(1).

The solution is to use a vector to store the imcoming values in order,
and then use a hashmap to store the index. When removing a value,
use the hashmap to locate the value, copy the last value of the vector
to the target position and remove the last. Also update the hashmap of 
the originally last value.

```
class RandomizedSet {
    vector<int> _v;
    unordered_map<int, int> _m;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (_m.find(val) != _m.end()) return false;
        _m[val] = _v.size();
        _v.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (_m.find(val) == _m.end()) return false;
        int pos = _m[val];
        _v[pos] = _v.back();
        _m[_v[pos]] = pos;
        _m.erase(val);
        _v.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return _v[rand() % _v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
```
