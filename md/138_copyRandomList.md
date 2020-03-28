### 138\. [Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer)

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

Example 1:

![alt text](1470150906153-2yxeznm.png)

```
Input:
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

Explanation:
Node 1's value is 1, both of its next and random pointer points to Node 2.
Node 2's value is 2, its next pointer points to null and its random pointer points to itself.
```

Note:

1. You must return the copy of the given head as a reference to the cloned list.

#### Solution 1

Create a new head with the same value. Loop over the old list.
Each time create a new node with the same value and link it to 
the previous node in the new list. Also use a hashmap to record
the corresponding between the current nodes in the old and new lists.

Time: O(N)
Space: O(N)

C++

```
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        Node* cur = head;
        Node* dummy = new Node(-1, NULL, NULL);
        Node* newCur = dummy;
        
        unordered_map<Node*, Node*> m;
        while (cur) {
            newCur->next = new Node(cur->val, NULL, NULL);
            newCur = newCur->next;
            m[cur] = newCur;
            cur = cur->next;
        }
        cur = head;
        newCur = dummy->next;
        while (cur) {
            newCur->random = m[cur->random];
            cur = cur->next;
            newCur = newCur->next;
        }
        return dummy->next;
    }
};
```
#### Solution 2

This solution doesn't require a hashmap at all. The trick is that we make a copy of each node right after itself.
In this way, we can keep the newly created nodes inside the list. Then, we know that the random connection among
the original nodes are shifted by 1 step. The random node of each new node which is next to the original node,
is next to the original random node. Then, we can simply assign the random connection by 
cur->next->random = cur->random->next. At last, we use every the other node to form two lists and return the 
new list head.

Time: O(N)
Space: O(1)

C++

```
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        
        // duplicate
        for (Node* cur = head; cur != NULL; cur = cur->next->next) {
            Node* tmp = new Node(cur->val, NULL, NULL);
            tmp->next = cur->next;
            cur->next = tmp;
        }

        // connect random
        for (Node* cur = head; cur != NULL and cur->next != NULL; cur = cur->next->next) {
            if (cur->random != NULL) cur->next->random = cur->random->next;
        }
        
        // break
        Node* newHead = head->next;
        for (Node* cur = head; cur != NULL and cur->next != NULL; ) {
            Node* newCur = cur->next;
            cur->next = newCur->next;
            if (newCur->next != NULL) newCur->next = newCur->next->next;
        }
        return newHead;
    }
};
```
