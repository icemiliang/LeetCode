### 270\. [Closest Binary Search Tree Value](https://leetcode.com/problems/closest-binary-search-tree-value/)

Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:

* Given target value is a floating point.
* You are guaranteed to have only one unique value in the BST that is closest to the target.
Example:
```
Input: root = [4,2,5,1,3], target = 3.714286

    4
   / \
  2   5
 / \
1   3

Output: 4
```

#### Solution 1

time: O(logn)
space: O(1)

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
    int closestValue(TreeNode* root, double target) {
    	if (!root) return 0;
        int res = root->val;
        while (root) {
        	if (abs(res - target) >= abs(root->val - target)) {
        		res = root->val;
        	}
        	root = target < root->val ? root->left : root->right;
        }
        return res;
    }
};
```
