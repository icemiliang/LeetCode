### 2\. [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
```
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
```

#### Solution 1

The problem has been simplified because it already reversed the order of the numbers
so that we can add those numbers from the most significant digit. The general idea is
add numbers in the same digits and keeep a carry variable in case the sum is bigger
than 10. There are two variants to implement the idea. One is add the numbers where
both of the lists exist. Then, add the carry number to the rest of the remaining list.
Another way is to check if either list is empty before adding anything.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while (l1 and l2) {
            carry += l1->val + l2->val;
            cur->next = new ListNode(carry % 10);
            carry /= 10;
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1) {
            carry += l1->val;
            cur->next = new ListNode(carry % 10);
            carry /= 10;
            cur = cur->next;
            l1 = l1->next;
        }
        
        while (l2) {
            carry += l2->val;
            cur->next = new ListNode(carry % 10);
            carry /= 10;
            cur = cur->next;
            l2 = l2->next;
        }
        if (carry) {
            cur->next = new ListNode(carry);
        }
        return dummy->next;
    }
};
```

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while (l1 or l2) {
            if (l1) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(carry % 10);
            cur = cur->next;
            carry /= 10;
        }
        if (carry) {
            cur->next = new ListNode(carry);
        }
        return dummy->next;
    }
};
```
