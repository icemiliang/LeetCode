### 24\. [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)

Given a linked list, swap every two adjacent nodes and return its head.

Example:
```
Given 1->2->3->4, you should return the list as 2->1->4->3.
```
Note:

Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be changed.

#### Solution 1

Classic swap nodes. Two pointers.

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
    ListNode* swapPairs(ListNode* head) {
        if (!head or !head->next) return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        while (fast->next and fast->next->next) {
            fast = fast->next;
            slow->next = fast->next;
            fast->next = slow->next->next;
            slow->next->next = fast;
            slow = fast;
        }
        return dummy->next;
    }
};
```

Use a for-loop.

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
    ListNode* swapPairs(ListNode* head) {
        if (!head or !head->next) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        for (ListNode* cur = dummy; cur->next and cur->next->next; cur = cur->next->next) {
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = cur->next->next;
            cur->next->next = tmp;
        }
        return dummy->next;
    }
};
```
