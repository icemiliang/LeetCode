### 328\. [Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/)

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:
```
Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
```

Example 2:
```
Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
```
Note:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...

#### Solution 1

Keep a pointer to the tail of the processed odds
and a pointer to the tail of the processed evens.
The tail of the processed evens could be null.
If there is an unprocessed node left, move it to 
the back of the tail of the odds and move its next
to the back of the tail of the evens.

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
    ListNode* oddEvenList(ListNode* head) {
        if (!head or !head->next) return head;
        ListNode* oddTail = head, *evenTail = head->next;
        while (evenTail and evenTail->next) {
            ListNode* evenHead = oddTail->next;
            oddTail->next = evenTail->next;
            evenTail->next = oddTail->next->next;
            oddTail->next->next = evenHead;
            oddTail = oddTail->next;
            evenTail = evenTail->next;      
        }
        return head;
    }
};
```
