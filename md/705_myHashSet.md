### 705\. [Design HashSet](https://leetcode.com/problems/design-hashset/)

Design a HashSet without using any built-in hash table libraries.

To be specific, your design should include these functions:

* add(value): Insert a value into the HashSet. 
* contains(value) : Return whether the value exists in the HashSet or not.
* remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.

Example:
```
MyHashSet hashSet = new MyHashSet();
hashSet.add(1);         
hashSet.add(2);         
hashSet.contains(1);    // returns true
hashSet.contains(3);    // returns false (not found)
hashSet.add(2);          
hashSet.contains(2);    // returns true
hashSet.remove(2);          
hashSet.contains(2);    // returns false (already removed)
```

Note:

* All values will be in the range of [0, 1000000].
* The number of operations will be in the range of [1, 10000].
* Please do not use the built-in HashSet library.


#### Solution 1

A main idea of a set is to quickly tell if there is the query element in the set.
Since the value has a small range from 0 to 10,000,001, we can use the value
as the index of a boolean array and the value of the array to tell us if the 
query value is in the set.

```
class MyHashSet {
	bool s[1000001];
public:
	MyHashSet() {
		fill(&s[0], &s[1000001], false);
	}
	void add(int key) {
		s[key] = true;
	}
	void remove(int key) {
		s[key] = false;
	}
	bool contains(int key) {
		return s[key];
	}
};
```
