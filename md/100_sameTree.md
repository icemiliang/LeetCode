### 100\. [Same Tree](https://leetcode.com/problems/same-tree/)

Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false


#### Solution 1

Using DFS to loop over the trees.

For each node:
(1) if both null, then we reach the childen of the leaves, return true.
(2) if one is null and the other is not, return false. 
(3) if values of the nodes don't equal, return false.
Then, check the left and right children.

C++

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p and !q) return true;
        if (!p and q) return false;
        if (p and !q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
};
```


#### Solution 2

BFS

C++

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> todoP; todoP.push(p);
        queue<TreeNode*> todoQ; todoQ.push(q);
        while (!todoP.empty() and !todoQ.empty()) {
            auto p = todoP.front(); todoP.pop();
            auto q = todoQ.front(); todoQ.pop();
            if (!p and !q) continue;
            if (p and !q) return false;
            if (!p and q) return false;
            if (p->val != q->val) return false;
            todoP.push(p->left);
            todoP.push(p->right);
            todoQ.push(q->left);
            todoQ.push(q->right);
        }
        return true;
    }
};
```
