### 170\. [Two Sum III - Data structure design](https://leetcode.com/problems/two-sum-iii-data-structure-design/)

Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

Example 1:
```
add(1); add(3); add(5);
find(4) -> true
find(7) -> false
```

Example 2:
```
add(3); add(1); add(2);
find(3) -> true
find(6) -> false
```

#### Solution 1

Hash map

C++

```
class TwoSum {
    unordered_map<int, int> m;
public:
    // Initialize your data structure here.
    TwoSum() {
        
    }
    
    // Add the number to an internal data structure..
    void add(int number) {
        ++m[number];
    }
    
    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        for (auto& a : m) {
            int t = value - a.first;
            // either two elements of the same value or different values
            if ((t != a.first and m.count(t)) or (t == a.first and a.second > 1)) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
```


#### Solution 2

Multi-set

c++

```
class TwoSum {
public:
    void add(int number) {
        s.insert(number);
    }
    bool find(int value) {
        for (auto a : s) {
            int cnt = a == value - a ? 1 : 0;
            if (s.count(value - a) > cnt) {
                return true;
            }
        }
        return false;
    }
private:
    unordered_multiset<int> s;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
```
