### 314\. [Binary Tree Vertical Order Traversal](https://leetcode.com/problems/binary-tree-vertical-order-traversal/)

Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples 1:
```
Input: [3,9,20,null,null,15,7]

   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7 

Output:

[
  [9],
  [3,15],
  [20],
  [7]
]
```

Examples 2:
```
Input: [3,9,8,4,0,1,7]

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7 

Output:

[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]
```

Examples 3:
```
Input: [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5)

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2

Output:

[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]
```

#### Solution 1

map + queue

map: col index -> col values
queue: col index -> node

col index can be negative as long as the order is correct.
each time left child goes to the previous index and right child goes to the next index.

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return {};

        map<int, vector<int>> cols;
        queue<pair<int, TreeNode*>> todo;
        todo.push({0, root});
        while(!todo.empty()){
            auto t = todo.front(); todo.pop();
            int idx = t.first;
            TreeNode* node = t.second;
            cols[idx].push_back(node->val);
            if(node->left) todo.push({idx - 1, node->left});
            if(node->right) todo.push({idx + 1, node->right});
        }

        vector<vector<int>> res;
        for (auto& col : cols){
            res.push_back(col.second);
        }
        return res;
    }
};
```


#### Solution 2

No hashmap.

https://leetcode.com/problems/binary-tree-vertical-order-traversal/discuss/76514/C%2B%2B-8ms-without-using-HashMap

C++

```
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        std::queue<pair<int, TreeNode*>> q;
        vector<vector<int>> left;
        vector<vector<int>> right;
        vector<int> mid;
        if(!root) return left;
        q.push({0,root});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            if(p.first == 0) mid.push_back(p.second->val);
            else if(p.first > 0){
                if(p.first > right.size()) right.push_back(vector<int>());
                right[p.first-1].push_back(p.second->val);
            }
            else{
                if(0-p.first > left.size()) left.push_back(vector<int>());
                left[-1-p.first].push_back(p.second->val);
            }
            if(p.second->left) q.push({p.first-1, p.second->left});
            if(p.second->right) q.push({p.first+1, p.second->right});
        }
        int r = right.size();
        reverse(left.begin(), left.end());
        left.push_back(mid);
        for(int i=0; i<r; i++) left.push_back(right[i]);
        return left;
    }
};
```
