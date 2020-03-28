### 145\. [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/)

Given a binary tree, return the postorder traversal of its nodes' values.

Example:
```
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
```

Follow up: Recursive solution is trivial, could you do it iteratively?

#### Solution 1

Iteration. 

Newly visited node comes first.

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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty()) {
        	auto t = todo.top(); todo.pop();
        	res.insert(res.begin(), t->val);
        	if (t->left) todo.push(t->left);
            if (t->right) todo.push(t->right);
        }
        return res;
    }
};
```

Another iterative solution that pushes values in order

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
    vector<int> postorderTraversal(TreeNode* root) {
    	if (!root) return {};
    	vector<int> res;
    	stack<TreeNode*> todo;
    	todo.push(root);
    	TreeNode *last = root;
    	while (!todo.empty()) {
    		TreeNode* t = todo.top();
            // If t is a leaf or t's child is the last examined node. 
            // If the left child is the last, then 
            // the right must be null because if it is not it will be examined before its parent.
    		if ((!t->left and !t->right) or t->left == last or t->right == last) {
    			res.push_back(t->val);
    			todo.pop();
    			last = t;
    		}
    		else {
    			if (t->right) todo.push(t->right);
    			if (t->left) todo.push(t->left);
    		}
    	}
   		return res;
    }
};
```


#### Solution 2

Recursion

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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        dfs(root, res);
        return res;
    }
    
    void dfs(TreeNode* root, vector<int>& res) {
        if (root->left) dfs(root->left, res);
        if (root->right) dfs(root->right, res);
        res.push_back(root->val);
    }
};
```
