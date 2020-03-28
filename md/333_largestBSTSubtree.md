### 333\. [Largest BST Subtree](https://leetcode.com/problems/largest-bst-subtree/)

Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.

Example:
```
Input: [10,5,15,1,8,null,7]

   10 
   / \ 
  5  15 
 / \   \ 
1   8   7

Output: 3
Explanation: The Largest BST Subtree in this case is the highlighted one.
             The return value is the subtree's size, which is 3.
```

Follow up:
Can you figure out ways to solve it with O(n) time complexity?

#### Solution 1

DFS.

The helper function returns the min value, max value, 
and the number of nodes of the substree starting from the current node.

C++

```
class Solution {
    struct Node {
        int mn;
        int mx;
        int h;
        Node(int n, int x, int h) { mn = n; mx = x; h = h; }
    };
public:
    int largestBSTSubtree(TreeNode* root) {
        Node* res = helper(root);
        return res->h;
    }
    Node* helper(TreeNode* node) {
        if (!node) return Node(INT_MAX, INT_MIN, 0);
        Node* left = helper(node->left), *right = helper(node->right);
        if (node->val > left && node->val < right->mn) {
            return {min(node->val, left[0]), max(node->val, right[1]), left[2] + right[2] + 1};
        } else {
            return Node(INT_MIN, INT_MAX, max(left[2], right[2]));
        }
    }
};
```

Return values through arguments

C++

```
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int res = 0, mn = INT_MIN, mx = INT_MAX;
        isValidBST(root, mn, mx, res);
        return res;
    }
    void isValidBST(TreeNode* root, int& mn, int& mx, int& res) {
        if (!root) return;
        int left_cnt = 0, right_cnt = 0, left_mn = INT_MIN;
        int right_mn = INT_MIN, left_mx = INT_MAX, right_mx = INT_MAX;
        isValidBST(root->left, left_mn, left_mx, left_cnt);
        isValidBST(root->right, right_mn, right_mx, right_cnt);
        if ((!root->left || root->val > left_mx) && (!root->right || root->val < right_mn)) {
            res = left_cnt + right_cnt + 1;
            mn = root->left ? left_mn : root->val;
            mx = root->right ? right_mx : root->val;
        } else {
            res = max(left_cnt, right_cnt);    
        }
    }
};
```