### 103\. [Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
```
    3
   / \
  9  20
    /  \
   15   7
```

return its zigzag level order traversal as:
```
[
  [3],
  [20,9],
  [15,7]
]
```

#### Solution 1

BFS 102 + reverse odd rows

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> todo;
        todo.push(root);
        vector<vector<int>> res;
        while (!todo.empty()) {
            vector<int> row;
            for (int i = todo.size() - 1; i >= 0; i--) {
                auto t = todo.front(); todo.pop();
                row.push_back(t->val);
                if (t->left) todo.push(t->left);
                if (t->right) todo.push(t->right);
            }
            res.push_back(row);
        }
        for (int i = 1; i < res.size(); i += 2) {
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
};
```
