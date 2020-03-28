### 199\. [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:
```
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> todo;
        todo.push(root);
        vector<int> res;
        while (!todo.empty()) {
            res.push_back(todo.back()->val);
            for (int i = todo.size() - 1; i >= 0; i--) {
                TreeNode* t = todo.front(); todo.pop();
                if (t->left) todo.push(t->left);
                if (t->right) todo.push(t->right);    
            }
        }
        return res;
    }
};
```

Or push the right child first. Then push the top element into the array.

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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> todo;
        todo.push(root);
        vector<int> res;
        while (!todo.empty()) {
            res.push_back(todo.front()->val);
            for (int i = todo.size() - 1; i >= 0; i--) {
                auto t = todo.front(); todo.pop();
                if (t->right) todo.push(t->right);
                if (t->left) todo.push(t->left);
            }
        }
        return res;
    }
};
```


