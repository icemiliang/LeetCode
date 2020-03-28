### 222\. [Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes/)

Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:
```
Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6
```

#### Solution 1

Go left and right. If lengths equal, # of nodes = 2^len - 1.
Recurse.

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
    int countNodes(TreeNode* root) {
        int len1 = 0, len2 = 0;
        TreeNode* left = root;
        TreeNode* right = root;
        while (left) {
            left = left->left;
            len1++;
        }
        while (right) {
            right = right->right;
            len2++;
        }
        if (len1 == len2) return pow(2, len1) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
```

#### Solution 2

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
    int countNodes(TreeNode* root) {
        int h = getHeight(root);
        if (h < 0) return 0;
        if (getHeight(root->right) == h - 1) {
            // return pow(2, h) + countNodes(root->right);
            return (1 << h) + countNodes(root->right);
        }
        // return pow(2, h - 1) + countNodes(root->left);
        return (1 << (h - 1)) + countNodes(root->left);
    }
    
    int getHeight(TreeNode* root) {
        return root ? getHeight(root->left) + 1 : -1;
    }
};
```

Another way 

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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int len = getLen(root);
        if (getLen(root->right) == len - 1) {
            return pow(2, len - 1) + countNodes(root->right);
        }
        return pow(2, len - 2) + countNodes(root->left);
    }
    
    int getLen(TreeNode* root) {
        int len = 0;
        while (root) { len++; root = root->left; }
        return len;
    }
};
```

#### Solution 3

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
    int countNodes(TreeNode* root) {
        int len = 0;
        dfs(root, len);
        return len;
    }
    
    void dfs(TreeNode* root, int& len) {
        if (!root) return;
        len++;
        int len1 = getLen(root->left);
        int len2 = getLen(root->right);
        if (len1 == len2) {
            len += pow(2, len1) - 1;
            dfs(root->right, len);
        }
        else {
            len += pow(2, len2) - 1;
            dfs(root->left, len);
        }
    }
    
    int getLen(TreeNode* root) {
        int len = 0;
        while (root) {
            len++;
            root = root->left;
        }
        return len;
    }
};
```
