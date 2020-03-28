### 230\. [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:
```
Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
```

Example 2:
```
Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
```

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

#### Solution 1

Inorder BFS

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
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return -1;
        stack<TreeNode*> todo;
        todo.push(root);
        int cnt = 0;
        while (root or !todo.empty()) {
            while (root) {
                todo.push(root);
                root = root->left;
            }
            root = todo.top(); todo.pop();
            cnt++;
            if (cnt == k) return root->val;
            root = root->right;
        }
        return -1;
    }
};
```

#### Solution 2

Count # of nodes on the left. If larger than k, kth smallest is on the left.
If smaller than k, it is on the right. Recurse with reduced k.

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
    int kthSmallest(TreeNode* root, int k) {
        int cnt = count(root->left);
        if (cnt > k - 1) {
            return kthSmallest(root->left, k);
        }
        else if (cnt < k - 1) {
            return kthSmallest(root->right, k - cnt - 1);
        }
        return root->val;
    }
    
    int count(TreeNode* root) {
        if (!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }
};
```

#### Solution 3

Inorder DFS

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
    int kthSmallest(TreeNode* root, int k) {
        return dfs(root, k);
    }
    
    int dfs(TreeNode* root, int& k) {
        if (!root) return -1;
        int val = dfs(root->left, k);
        if (k == 0) return val;
        k--;
        if (k == 0) return root->val;
        return dfs(root->right, k);
    }
};
```
