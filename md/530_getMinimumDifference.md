### 530\. [Minimum Absolute Difference in BST](https://leetcode.com/problems/minimum-absolute-difference-in-bst/)

Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:
```
Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
```

Note: There are at least two nodes in this BST.

#### Solution 1

Inorder traversal and compare with prevous 

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
    int getMinimumDifference(TreeNode* root) {
        if (!root) return -1;
        int minDiff = INT_MAX;
        int prev = -1;
        dfs(root, prev, minDiff);
        return minDiff;
    }
    
    void dfs(TreeNode* root, int& prev, int& minDiff) {
        if (root->left) dfs(root->left, prev, minDiff);
        if (prev >= 0) minDiff = min(minDiff, root->val - prev);
        prev = root->val;
        if (root->right) dfs(root->right, prev, minDiff);
    }
};
```
