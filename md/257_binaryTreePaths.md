### 257\. [Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths/)

Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:
```
Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
```

#### Solution 1

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root) dfs(root, "", res);
        return res;
    }
    
    void dfs(TreeNode* root, string row, vector<string>& res) {
        row += to_string(root->val);
        if (!root->left and !root->right) res.push_back(row);
        if (root->left) dfs(root->left, row + "->", res);
        if (root->right) dfs(root->right, row + "->", res);
    }
};
```
