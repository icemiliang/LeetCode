### 108\. [Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5


#### Solution 1

The BST has to be balanced, so the root of any subtree is the median of all the numbers.
We can do binary search on the array and recursively build the tree.
Each time we build a root from the median of the array and then use the left
half to build the left subtree and the right half array to build the right subtree.

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }
    
    TreeNode* dfs(vector<int>& nums, int left, int right) {
        if (left > right) return NULL;
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = dfs(nums, left, mid - 1);
        root->right = dfs(nums, mid + 1, right);
        return root;
    }
};
```


#### Solution 2

Use original function to recurse. Build new left and right arrays.

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return NULL;
        int mid = nums.size() / 2; 
        TreeNode* root = new TreeNode(nums[mid]);
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid + 1, nums.end());
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }
};
```
