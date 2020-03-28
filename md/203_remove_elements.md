### 203\. [Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/)

Remove all elements from a linked list of integers that have value val.

Example:
```
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
```

#### Solution 1

Loop over the list, if next node eligible,
point current next to next's next and delete current next.

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = dummy;
        while (cur->next) {
            ListNode* tmp = cur->next;
            if (tmp->val == val) {
                cur->next = tmp->next;
                delete tmp;
            }
            else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
```

#### Solution 2

Recursion. 
The current node's next node leads a list 
that does not contain the removed value.
If the current node matches the value, 
the next node will lead the list.

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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};
```
