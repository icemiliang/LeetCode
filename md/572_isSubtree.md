### 572\. [Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/)

Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:
```
     3
    / \
   4   5
  / \
 1   2

Given tree t:
   4 
  / \
 1   2

Return true, because t has the same structure and node values with a subtree of s.
```
Example 2:
```
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0

Given tree t:
   4
  / \
 1   2

Return false.
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s) return false;
        if (s->val == t->val and isSame(s, t)) return true;
        return isSubtree(s->left, t) or isSubtree(s->right, t);
    }
    
    bool isSame(TreeNode*s, TreeNode*t) {
        if (!s and !t) return true;
        if ((!s and t) or (s and !t) or (s->val != t->val)) return false;
        return isSame(s->left, t->left) and isSame(s->right, t->right);
    }
};
```


#### Solution 2

Tree -> String, subtree -> substring

C++

```
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        ostringstream os1, os2;
        serialize(s, os1);
        serialize(t, os2);
        return os1.str().find(os2.str()) != string::npos;
    }
    void serialize(TreeNode* node, ostringstream& os) {
        if (!node) os << ",#";
        else {
            os << "," << node->val;
            serialize(node->left, os);
            serialize(node->right, os);
        }
    }
};
```
