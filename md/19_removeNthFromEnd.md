### 19\. [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/)

Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?


#### Solution 1

Because we cannot backtrack the listed list node from the end, we have
to scan from the begining. Here we use a trick to do it, which uses the
observation that the end is n steps ahead of the nth node from the end.
We define two pointers at the head, a slow pointer a fast pointer. The
fast pointer moves n steps. Now, the fast pointer is n steps ahead of
the slow pointer. Then, we let the slow and fast pointer move simutaneouly.
When the fast pointer reaches the end, the slow pointer is n steps behind,
which means the slow pointer is at the node that we want to remove. One
thing to notice is that this nth node from the end could be the head node.
Thus, we need to define a dummy node before head and start the slow and
fast pointers at the dummy node.

C++

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = new ListNode(-1);
        ListNode* slow = fast;
        ListNode* dummy = fast;
        fast->next = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* tmp = slow->next;
        slow->next = tmp->next;
        delete tmp;
        return dummy->next;
    }
};
```

Python 

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(-1)
        slow = dummy
        fast = dummy
        dummy.next = head
        for i in range(n):
            fast = fast.next
        while fast.next:
            fast = fast.next
            slow = slow.next
            
        tmp = slow.next
        slow.next = tmp.next
        return dummy.next
```
