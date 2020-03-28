#### 146\. [LRU Cache](https://leetcode.com/problems/lru-cache)

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:
```
LRUCache cache = new LRUCache( 2 );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
```

#### Solution 1

The challenge of this problem is to do both put and get in O(1) time complexity.
We can maintain a list to store the values according to their last usage. 
To find the values in O(1), we can then use a hashmap to link the keys to
the list nodes.

Thus, we define a linked list of a pair of key and value. The reason that we need
to store both the key and the value in the list is that we also need to quickly find 
the corresponding position in the hash map by using the linked list in order to delete
the least frequently used values. After defining the linked list, we define a hash map 
from key to the linked list iterator. Now, implementing the get and put functions become
straightforward. 

To get the value given key, first we check if the hashmap has the key or not. If it does
not, simply return -1 as required. It it finds the key, we can just use the linked list
iterator to return the value, but before that, we need to move the node to the front
of the list. We use a STL list function called 'splice' to do this.

To put in a value, still, we first check if the hashmap has the key. If it does have 
the key, then because we need to update it according to the new provided value, we first
delete the node from the list. We do not need to delete the list iterator from the hashmap
because later we will just asign a new one. We push a new node with the key and value to 
the front of the list and update the iterator of the key in the hashmap with the front
one of the list. Then, if the size of the hashmap is longer than the capacity, then we
delete the last node in the list which is the least recently used value. Don't forget 
to delete the corresponding iterator in the hashmap.

C++ 

```
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) return -1;
        l.splice(l.begin(), l, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()) l.erase(it->second);
        l.push_front({key, value});
        m[key] = l.begin();
        if (m.size() > cap) {
            int k = l.rbegin()->first;
            l.pop_back();
            m.erase(k);
        }
    }
private:
    int cap;
    list<pair<int, int>> l; // {key, value} O(1) for removing elements; order is recency    
    unordered_map<int, list<pair<int, int>>::iterator> m; // {key, list::iterator} O(1) for indexing
};
```

Python

```
class Node(object):

    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None

class LRUCache(object):

    def __init__(self, capacity):
        self.dict = {}
        self.cap = capacity
        self.dummy_head = Node(0, 0)
        self.dummy_tail = Node(0, 0)
        self.dummy_head.next = self.dummy_tail
        self.dummy_tail.prev = self.dummy_head

    def get(self, key):
        if key not in self.dict:
            return -1
        node = self.dict[key]
        self._remove(node)
        self._add(node)
        return node.val

    def put(self, key, value):
        if key in self.dict:
            self._remove(self.dict[key])
        node = Node(key, value)
        self._add(node)
        self.dict[key] = node
        if len(self.dict) > self.cap:
            head = self.dummy_head.next
            self._remove(head)
            del self.dict[head.key]

    def _remove(self, node):
        prev = node.prev
        next = node.next
        prev.next = next
        next.prev = prev

    def _add(self, node):
        tail = self.dummy_tail.prev
        tail.next = node
        node.prev = tail
        self.dummy_tail.prev = node
        node.next = self.dummy_tail
```
