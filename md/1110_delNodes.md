### 1110\. [Delete Nodes And Return Forest](https://leetcode.com/problems/delete-nodes-and-return-forest/)

Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest.  You may return the result in any order.

Example 1:

![alt text](screen-shot-2019-07-01-at-53836-pm.png)

```
Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]
```

Constraints:

* The number of nodes in the given tree is at most 1000.
* Each node has a distinct value between 1 and 1000.
* to_delete.length <= 1000
* to_delete contains distinct values between 1 and 1000.

#### Solution 1

If a node is root (has no parent) and isn't deleted,
will we add it to the result.

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> dict(to_delete.begin(), to_delete.end());
        dfs(root, res, dict, true);
        return res;
    }

    TreeNode* dfs(TreeNode* root, vector<TreeNode*>& res, unordered_set<int>& dict, bool is_root) {
        if (root == NULL) return NULL;
        bool deleted = dict.count(root->val);
        if (is_root and !deleted) res.push_back(root);
        root->left = dfs(root->left, res, dict, deleted);
        root->right = dfs(root->right, res, dict, deleted);
        return deleted ? NULL : root;
    }
};
```

#### Solution 2

Post-order traverse. 

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> dict(to_delete.begin(), to_delete.end());
        dfs(root, res, dict);
        if (root) res.push_back(root);
        return res;
    }
    void dfs (TreeNode* &root, vector<TreeNode*>& res, unordered_set<int>& dict) {
        if (!root) return; 
        dfs(root->left, res, dict);
        dfs(root->right, res, dict);
        if (dict.count(root->val)) {
            if (root->left)  res.push_back(root->left);
            if (root->right) res.push_back(root->right);
            root = NULL;
            delete root; // why
        }
    }
};
```
