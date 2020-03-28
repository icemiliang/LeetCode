### 113\. [Path Sum II](https://leetcode.com/problems/path-sum-ii/)

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]


#### Solution 1

More difficult than 112, this time we are asked to return the path that 
sums up to the target. We need to remember the current path and if the 
path adds up to the target, we push the path into the result. Thus, we 
need to define a helper that takes in the current node, the current
path, current sum, and the collection of all valid paths. The algorithm is 
almost the same as 112, except that each time we push the current node's 
value into the current path and examine the left and right children and then pop out
the value from the current path.

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return {};
        vector<vector<int>> res;
        vector<int> row;
        dfs(root, sum, row, res);
        return res;
    }
    
    void dfs(TreeNode* root, int sum, vector<int>& row, vector<vector<int>>& res) {
        row.push_back(root->val);
        sum -= root->val;
        if (!root->left and !root->right and sum == 0) {
            res.push_back(row);
        }
        if (root->left) dfs(root->left, sum, row, res);
        if (root->right) dfs(root->right, sum, row, res);
        row.pop_back();
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
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        def dfs(node, sum, out, res):
            if not node.left and not node.right and sum == node.val:
                out.append(node.val)
                res.append(out)
            if node.left:
                dfs(node.left, sum - node.val, out + [node.val], res)
            if node.right:
                dfs(node.right, sum - node.val, out + [node.val], res)
        if not root:
            return []
        res = []
        out = []
        dfs(root, sum, out, res)
        return res
```
