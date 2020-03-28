### 124\. [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)

Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:
```
Input: [1,2,3]

       1
      / \
     2   3

Output: 6
```

Example 2:
```
Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
```

#### Solution 1

DFS. Return two things 
1) max sum in current subtree
2) max sum to leaf from current node

return whichever is bigger 
1) current max sum or 
2) left path sum + right path sum + current val

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
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        dfs(root, sum);
        return sum;
    }
    
    int dfs(TreeNode* root, int& sum) {
        if (!root) return 0;
        int left = max(dfs(root->left, sum), 0);
        int right = max(dfs(root->right, sum), 0);
        sum = max(sum, left + right + root->val);
        return max(left, right) + root->val;
    }
};
```

#### Solution 2

Follow up: return the max path.

```
/**
* Definition for a binary tree node.
* struct TreeNode {
* int val;
* TreeNode *left;
* TreeNode *right;
* TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	list<int> row;
	int maxPathSum(TreeNode* root) {
		if (root == 0) return 0;
		int res = root->val;
		int tmp = 0;
		dfs(root, res, tmp);
		return res;
	}

	list<int> dfs(TreeNode* root, int& res, int &curSum){
		if (root == 0){
			curSum = 0;
			return {};
		}
		list<int> l = dfs(root->left, res, curSum);
		int lv = curSum;
		list<int> r = dfs(root->right, res, curSum);
		int rv = curSum;

		if (lv <= rv){
			swap(l, r);
			swap(lv, rv);
		}
		if (rv <= 0) {
			rv=0;
			r.clear();
		}
		if (lv <= 0){
			l.clear();
			lv=0;
		}
		curSum = max(lv, rv) + root->val;
		l.push_back(root->val);
		if (lv + rv + root->val > res) {
			res = lv + rv + root->val;
			row = l;
			row.splice(row.end(), r);
		}
		return l;
	}
};
```
