### 404\. [Sum of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves/)

Find the sum of all left leaves in a given binary tree.

Example:
```
    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
```

 Solution 1

We need a variable to keep the current sum and it cannot be the return variable,
because we need to recurse in both the current left and right children. 
Thus, we create a helper that takes the sum as the argument.

#### Solution 1

Traverse the tree and add up all left leaves.

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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        dfs(root, sum);
        return sum;
    }
    
    void dfs(TreeNode* root, int& sum) {
        if (root->left) {
            if (!root->left->left and !root->left->right) sum += root->left->val;
            else dfs(root->left, sum);
        }
        if (root->right) {
            dfs(root->right, sum);
        }
    }
};
```

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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        queue<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty()) {
            TreeNode* t = todo.front(); todo.pop();
            if (t->left) {
                if (!t->left->left and !t->left->right) sum += t->left->val;
                else todo.push(t->left);
            }
            if (t->right) todo.push(t->right);
        }
        return sum;
    }
};
```
