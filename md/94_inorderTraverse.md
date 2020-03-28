### 94\. [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)

Given a binary tree, return the inorder traversal of its nodes' values.

Example:
```
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
```
Follow up: Recursive solution is trivial, could you do it iteratively?

#### Solution 1

We first try DFS. Inorder traversal follows the "left, mid, right" rule. Thus, we 
first examine the left node, then push the current value into the array, and 
finally examine the right node.

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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        dfs(root, res);
        return res;
    }
    
    void dfs(TreeNode* root, vector<int>& res) {
        if (root->left) dfs(root->left, res);
        res.push_back(root->val);
        if (root->right) dfs(root->right, res);
    }
};
```

#### Solution 2

Interative algorithm is a bit complicated because we cannot put any value into
the array whenever we see it. We need to temporarily store visited nodes until 
reaching the leaf. Then, we take out the lastly stored node, put it in the 
final array. Then, examine the right node.

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> todo;
        while (root or !todo.empty()) {
            while (root) {
                todo.push(root);
                root = root->left;
            }
            root = todo.top(); todo.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};
```

#### Solution 3

Morris traversal.

C++

```
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        while (root) {
            if (root -> left) {
                TreeNode* pre = root -> left;
                while (pre -> right && pre -> right != root) {
                    pre = pre -> right;
                }
                if (!pre -> right) {
                    pre -> right = root;
                    root = root -> left;
                } else {
                    pre -> right = NULL;
                    res.push_back(root -> val);
                    root = root -> right;
                }
            } else {
                res.push_back(root -> val);
                root = root -> right;
            }
        }
        return res;
    }
};
```