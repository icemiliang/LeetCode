### 206\. [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)

Reverse a singly linked list.

Example:
```
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
```
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?


#### Solution 1

Iteration

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
    ListNode* reverseList(ListNode* head) {
        if (!head or !head->next) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = head;
        while (cur->next) {
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = dummy->next;
            dummy->next = tmp;
        }
        return dummy->next;
    }
};
```

#### Solution 2

Recursion.
Get the leading node of the reversed sublist. Now, the head's next is at the end of the sublist.
Append head to the end of the sublist. Return the leading node.

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
    ListNode* reverseList(ListNode* head) {
        if (!head or !head->next) return head;
        ListNode* node = reverseList(last->next);
        head->next->next = head;
        head->next = NULL;
        return node;
    }
};
```
