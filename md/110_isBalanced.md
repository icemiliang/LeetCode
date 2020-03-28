### 110\. [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:
```
Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.
```

Example 2:
```
Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.
```

#### Solution 1

Use DFS to get the depth of each node and compare the depths of the two children
for each node.

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
	bool isBalanced(TreeNode* root) {
		if (!root) return true;
		if (abs(getDepth(root->left) - getDepth(root->right)) > 1) return false;
		return isBalanced1(root->left) and isBalanced1(root->right);
	}

	int getDepth(TreeNode* root) {
		if (!root) return 0;
		return 1+ max(getDepth(root->left),getDepth(root->right));
	}
};

```

#### Solution 2

DFS is slow for this problem because each node will be visited
during calculating the depth of each node. We can modify the
getDepth method so that it will return -1 if itself is not balanced.
In this way, the unbalance signal will be passed all the way to the top.

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
	bool isBalanced(TreeNode* root) {
		if (checkDepth(root) == -1) return false;
		return true;
	}

	int checkDepth(TreeNode* root) {
		if (!root) return 0;
		int left = checkDepth(root->left);
		if (left == -1) return -1;
		int right = checkDepth(root->right);
		if (right == -1) return -1;
		int diff = abs(left - right);
		if (diff > 1) return -1;
		return 1 + max(left,right);
	}
};
```
