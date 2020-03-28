### 92\. [Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii)

Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:
```
Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
```

#### Solution 1

The main idea is to maintain a front and a back pointer and each time
move the node after the front pointer to the front of the back pointer.

For example 1->2->3->4->5 m = 2, n = 4

The back pointer is to 1 and the front pointer is to 2. 
Step 1: move 3 to between 1 and 2. We get 1->3->2->4->5
Step 2: move 4 to between 1 and 3. We get 1->4->3->2->5

We also need a dummy pointer to head in case m = 1 which means head changes

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = dummy;
        for (int i = 0; i < m - 1; i++) {
            cur = cur->next;
        }
        ListNode* last = cur;
        cur = cur->next;
        for (int i = 0; i < n - m; i++) {
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = last->next;
            last->next = tmp;
        }
        return dummy->next;
    }
};
```
