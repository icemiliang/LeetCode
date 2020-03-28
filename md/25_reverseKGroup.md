### 25\. [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:
```
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
```
Note:

1. Only constant extra memory is allowed.
2. You may not alter the values in the list's nodes, only nodes itself may be changed.

#### Solution 1

Find length. Substract by k each interation until length < k.

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head or !head->next) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* last = dummy;
        ListNode* cur = dummy;
        int num = 0;
        while (cur->next) {
            cur = cur->next;
            num++;
        }
        while (num >= k) {
            cur = last->next;
            for (int i = 0; i < k - 1; i++) {
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = last->next;
                last->next = tmp;
            }
            last = cur;
            num -= k;
        }
        return dummy->next;
    }
};
```


#### Solution -1

If we still need to reverse the last less than k nodes

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head or !head->next) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* last = dummy;
        while (last and last->next) {
            ListNode* cur = last->next;
            int i = 1;
            while (cur->next) {
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = last->next;
                last->next = tmp;
                if (++i == k) break;
                
            }
            last = cur;
        }
        return dummy->next;
    }
};
```
