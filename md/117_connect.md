### 117\. [Populating Next Right Pointers in Each Node II](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/)

Given a binary tree
```
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
```
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Example:

![alt text](117_sample.png?raw=true)

```
Input: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":null,"next":null,"right":{"$id":"6","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}

Output: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":null,"right":null,"val":7},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"6","left":null,"next":null,"right":{"$ref":"5"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"6"},"val":1}

Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B.
```

Note:

* You may only use constant extra space.
* Recursive approach is fine, implicit stack space does not count as extra space for this problem.

#### Solution 1

117 is almost the same with [116 Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/) except that the
tree may not be a perfect binary tree, but Solution 1 in 116 also works in this problem because when we
push the nodes into the stack, we always check if it has a left or a right node.

C++

```
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        queue<Node*> todo;
        todo.push(root);
        while (!todo.empty()) {
            for (int i = todo.size() - 1; i >= 0; i--) {
                Node* t = todo.front(); todo.pop();
                if (i > 0) t->next = todo.front();
                if (t->left) todo.push(t->left);
                if (t->right) todo.push(t->right);    
            }
        }
        return root;
    }
};
```

#### Solution 2

We can use the solution from [116 Populating Next Right Pointers in Each Node](116_connect.md),
except that we need to find the next node first. Also, recurse at the right child first,
otherwise the left child does not know about what is on the right.

C++

```
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        Node* p = root->next;
        while (p) {
            if (p->left) {
                p = p->left;
                break;
            }
            if (p->right) {
                p = p->right;
                break;
            }
            p = p->next;
        }
        if (root->right) root->right->next = p;
        if (root->left) root->left->next = root->right ? root->right : p;
        connect(root->right);
        connect(root->left);
        return root;
    }
};
```

#### Solution 3

https://www.cnblogs.com/grandyang/p/4290148.html

Consant space, not by recursion.

C++

```
// Non-recursion, constant space
class Solution {
public:
    Node* connect(Node* root) {
        Node *dummy = new Node(0, NULL, NULL, NULL), *cur = dummy, *head = root;
        while (root) {
            if (root->left) {
                cur->next = root->left;
                cur = cur->next;
            }
            if (root->right) {
                cur->next = root->right;
                cur = cur->next;
            }
            root = root->next;
            if (!root) {
                cur = dummy;
                root = dummy->next;
                dummy->next = NULL;
            }
        }
        return head;
    }
};
```
