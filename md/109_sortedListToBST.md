### 109\. [Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:
```
Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
```

#### Solution 1

In 108, we can directly index the median element of an array. 
For a linked list, we need "slow-fast pointers" to find the median.
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return new TreeNode(head->val);
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = head;
        while (fast->next and fast->next->next) {
            pre = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        pre->next = NULL;
        TreeNode* root = new TreeNode(slow->val);
        root->left = head == slow ? NULL : sortedListToBST(head);
        root->right = (!fast and fast == head) ? NULL : sortedListToBST(fast);
        return root;
    }
};
```

#### Solution 2

The same algorithm with 1. We define a helper function
to do the recursion to avoid breaking the list.

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        return dfs(head, NULL);
    }
    
    TreeNode* dfs(ListNode* head, ListNode* tail) {
        if (head == tail) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != tail and fast->next != tail) {
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = dfs(head, slow);
        root->right = dfs(slow->next, tail);
        return root;
    }
};
```

#### Solution 3

Inorder 

```
ListNode* head;

TreeNode* sortedListToBST3(ListNode* node) {
    // Get the size of the linked list first
    int size = findSize(node);

    head = node;

    // Form the BST now that we know the size
    return convertListToBST(0, size - 1);
}

TreeNode* convertListToBST(int l, int r) {
    // Invalid case
    if (l > r) return NULL;

    int mid = (l + r) / 2;

    // First step of simulated inorder traversal. Recursively form
    // the left half
    TreeNode* left = convertListToBST(l, mid - 1);

    // Once left half is traversed, process the current node
    TreeNode* node = new TreeNode(head->val);
    node->left = left;

    // Maintain the invariance mentioned in the algorithm
    head = head->next;

    // Recurse on the right hand side and form BST out of them
    node->right = convertListToBST(mid + 1, r);
    return node;
}

int findSize(ListNode* head) {
    ListNode* ptr = head;
    int c = 0;
    while (ptr != NULL) {
      ptr = ptr->next;  
      c += 1;
    }
    return c;
}
```
