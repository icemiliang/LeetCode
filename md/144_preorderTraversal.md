### 144\. [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/)

Given a binary tree, return the preorder traversal of its nodes' values.

Example:
```
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
```

Follow up: Recursive solution is trivial, could you do it iteratively?

#### Solution 1

There are three basic tree treversal algorithms -- inorder, preorder, and postorder. Each has
a BFS version and a DFS version. Preorder follows the "mid, left, right" rule. This fits the 
mechanism of stacks. Each time we take the top of the stack. Put it in the result. Put the
right and left children into the stack. Next time, we will take the left first and put it
into the result and so on and so forth. At the begining, put the root into the stack.

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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty()) {
            auto t = todo.top(); todo.pop();
            res.push_back(t->val);
            if (t->right) todo.push(t->right);
            if (t->left) todo.push(t->left);
        }
        return res;
    }
};
```

#### Solution 2

We can also use DFS to solve it. Define a helper function that pushes 
the value to the array as we go to left and then right.

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root) dfs(root, res);
        return res;
    }
    
    void dfs(TreeNode* root, vector<int>& res) {
        res.push_back(root->val);
        if (root->left) dfs(root->left, res);
        if (root->right) dfs(root->right, res);
    }
};
```
