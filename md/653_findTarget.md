### 653\. [Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)

Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
```
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
```

Example 2:
```
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
```

#### Solution 1

Inorder traversal + two pointers.

Time: O(n)
Space: O(n)

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
    bool findTarget(TreeNode* root, int k) {
        if (!root) return k == 0;
        vector<int> sorted;
        inorder(root, sorted);
        for (int i = 0, j = sorted.size() - 1; i < j;) {
            int sum = sorted[i] + sorted[j];
            if (sum == k) return true;
            (sum < k) ? ++i : --j;
        }
        return false;
    }
    
    void inorder(TreeNode* root, vector<int>& sorted) {
        if (root->left) inorder(root->left, sorted);
        sorted.push_back(root->val);
        if (root->right) inorder(root->right, sorted);
    }
};
```

#### Solution 2

Recursive preorder + hash set.

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
    bool findTarget(TreeNode* root, int k) {
        if (!root) return k == 0;
        unordered_set<int> nums;
        return preorder(root, k, nums);
    }
    
    bool preorder(TreeNode* root, int k, unordered_set<int>& nums) {
        int t = k - root->val;
        if (nums.count(t)) return true;
        nums.insert(root->val);
        bool res = false;
        if (root->left) res |= preorder(root->left, k, nums);
        if (root->right) res |= preorder(root->right, k, nums);
        return res;
    }
};
```


#### Solution 3

Iterative level order + hash set.

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
    bool findTarget(TreeNode* root, int k) {
        if (!root) return k == 0;
        unordered_set<int> dict;
        queue<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty()) {
            auto t = todo.front(); todo.pop();
            if (dict.count(k - t->val)) return true;
            dict.insert(t->val);
            if (t->left) todo.push(t->left);
            if (t->right) todo.push(t->right);
        }
        return false;
    }
};
```
