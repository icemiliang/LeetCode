### 341\. [Flatten Nested List Iterator](https://leetcode.com/problems/flatten-nested-list-iterator/)

Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
```
Input: [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,1,2,1,1].
```
Example 2:
```
Input: [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,4,6].
```

#### Solution 1

Put all the numbers in a queue.

C++

```
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    queue<int> todo;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        parse(nestedList);
    }

    int next() {
        int t = todo.front(); todo.pop();
        return t;
    }

    bool hasNext() {
        return !todo.empty();
    }
    
    void parse(vector<NestedInteger> &nestedList) {
        for (auto& list : nestedList) {
            if (list.isInteger()) todo.push(list.getInteger());
            else parse(list.getList());
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
```



#### Solution 2

Use a stack to store lists. Push list in reverse order.
When calling hasNext, make sure the top element is an integer,
by iteratively flatten the top list (in reverse order).

C++

```
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    stack<NestedInteger> todo;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; --i) {
            todo.push(nestedList[i]);
        }
    }

    int next() {
        auto t = todo.top(); todo.pop();
        return t.getInteger();
    }

    bool hasNext() {
        while (!todo.empty()) {
            auto t = todo.top(); 
            if (t.isInteger()) return true;
            todo.pop();
            auto lists = t.getList();
            for (int i = lists.size() - 1; i >= 0; --i) {
                todo.push(lists[i]);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
```
