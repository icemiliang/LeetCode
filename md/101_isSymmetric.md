### 101\. [Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)

Given a binary tree, check whether it is a mirror of itself
(ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
```
    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
```

Note:
Bonus points if you could solve it both recursively and iteratively.


#### Solution 1

Similar to [100. Same Tree](https://leetcode.com/problems/same-tree/). We create a helper to check
if two nodes have the same value. The difference to 100 is that each time we continue on the left 
of the left and the right of the right. We start from the root's left and right childen. If the 
tree is symmetric, then the left of the left should equal the right of the right.

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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return dfs(root->left, root->right);
    }
    
    bool dfs(TreeNode* p, TreeNode* q) {
        if (!p and !q) return true;
        if (p and !q) return false;
        if (!p and q) return false;
        if (p->val != q->val) return false;
        return dfs(p->left, q->right) and dfs(p->right, q->left);
    }
};
```
Python

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def helper(left: TreeNode, right: TreeNode):
            if not left and not right:
                return True
            if (not left and right) or (left and not right) or (left.val != right.val):
                return False
            return helper(left.left, right.right) and helper(left.right, right.left)
        if not root:
            return True
        return helper(root.left, root.right)
```

#### Solution 2

We can use queues to implement BFS.

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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> qleft;
        queue<TreeNode*> qright;
        qleft.push(root->left);
        qright.push(root->right);
        while (!qleft.empty() and !qright.empty()) {
            TreeNode* left = qleft.front(); qleft.pop();
            TreeNode* right = qright.front(); qright.pop();
            if (!left and !right) continue;
            if ((!left and right) or (left and !right)) return false;
            if (left->val != right->val) return false;
            qleft.push(left->left);
            qright.push(right->right);
            qleft.push(right->left);
            qright.push(left->right);
        }
        return true;
    }
};
```
