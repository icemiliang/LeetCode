### 102\. [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

#### Solution 1

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>>  res;
        queue<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty()) {
            vector<int> row;
            for (int i = todo.size() - 1; i >= 0; i--) {
                TreeNode* t = todo.front();
                todo.pop();
                row.push_back(t->val);
                if (t->left) todo.push(t->left);
                if (t->right) todo.push(t->right);
            }
            res.push_back(row);
        }
        return res;
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
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        res = []
        q = []
        q.append(root)
        while len(q) != 0:
            row = []
            for i in range(len(q), 0, -1):
                t = q[0]
                row.append(t.val)
                q.pop(0)
                if t.left:
                    q.append(t.left)
                if t.right:
                    q.append(t.right)
            res.append(row)
        return res
```

#### Solution 2

DFS

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res, 1);
        return res;
    }
    
    void dfs(TreeNode* root, vector<vector<int>>& res, int level) {
        if (!root) return;
        if (level > res.size()) res.push_back({root->val});
        else res[level - 1].push_back(root->val);
        if (root->left) dfs(root->left, res, level + 1);
        if (root->right) dfs(root->right, res, level + 1);
    }
};
```
