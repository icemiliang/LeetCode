### 82\. [Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:
```
Input: 1->2->3->3->4->4->5
Output: 1->2->5
```

Example 2:
```
Input: 1->1->1->2->3
Output: 2->3
```

#### Solution 1

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head or !head->next) return head;
        ListNode* dummy = new ListNode(-1);
        ListNode* last = dummy;
        dummy->next = head;
        while (last->next) {
            ListNode* cur = last->next;
            if (cur->next and cur->next->val == cur->val) {
                while (cur->next and cur->next->val == cur->val) {
                    ListNode* tmp = cur->next;
                    cur->next = tmp->next;
                    delete tmp;
                }
                last->next = cur->next;
                delete cur;
            }
            else last = last->next;
        }
        return dummy->next;
    }
};
```

#### Solution 2

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head or !head->next) return head;
        if (head->val == head->next->val) {
            while (head->next and head->val == head->next->val) {
                head = head->next;
            }
            return deleteDuplicates(head->next);
        }
        head->next = deleteDuplicates(head->next);
        return head;
    }
};
```
