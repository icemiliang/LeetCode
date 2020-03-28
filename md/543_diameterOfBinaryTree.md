### 543\. [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
```
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
```

Note: The length of path between two nodes is represented by the number of edges between them.


#### Solution 1

DFS. Return both length and current result.

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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        int len1 = dfs(root->left, res);
        int len2 = dfs(root->right, res);
        return max(len1 + len2 + 1, res) - 1;
    }
    
    int dfs(TreeNode* root, int& res) {
        if (!root) return 0;
        int len1 = dfs(root->left, res);
        int len2 = dfs(root->right, res);
        res = max(res, len1 + len2 + 1);
        return max(len1, len2) + 1;
    }
};
```
