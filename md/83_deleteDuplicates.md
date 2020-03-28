### 83\. [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)

Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:
```
Input: 1->1->2
Output: 1->2
```
Example 2:
```
Input: 1->1->2->3->3
Output: 1->2->3
```

#### Solution 1

Iteration.

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
        ListNode* cur = head;
        while (cur and cur->next) {
            auto tmp = cur->next;
            if (cur->val == tmp->val) {
                cur->next = tmp->next;
                delete tmp;
            }
            if (cur->next and cur->val != cur->next->val) {
                cur = cur->next;    
            }
        }
        return head;
    }
};
```

A similar implementation.

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
        ListNode* cur = head;
        while (cur and cur->next) {
            while (cur->next and cur->val == cur->next->val) {
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                delete(tmp);
            }  
            cur = cur->next;
        }
        return head;
    }
};
```

#### Solution 2

Recursion.

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
            return deleteDuplicates(head);
        }
        head->next = deleteDuplicates(head->next);
        return head;
    }
};
```
