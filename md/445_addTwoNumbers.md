### 445\. [Add Two Numbers II](https://leetcode.com/problems/add-two-numbers-ii/)

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:
```
Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
```

#### Solution 1

Convert lists to stacks.
Last number examined in the list will be popped first.
Pop a number from each stack and assign to the current node
their sum, until both stacks are empty. Create a new node with
the quotient of sum by 10. If quotient is 0, return head's next;
if not 0, return head.

Time O(n)

Space O(n)

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
        stack<int> num1, num2;
        while (l1) { num1.push(l1->val); l1 = l1->next; }
        while (l2) { num2.push(l2->val); l2 = l2->next; }
        ListNode* dummy = new ListNode(-1);
        int carry = 0;
        while (!num1.empty() or !num2.empty()) {
            if (!num1.empty()) { carry += num1.top(); num1.pop(); }
            if (!num2.empty()) { carry += num2.top(); num2.pop(); }
            ListNode* tmp = new ListNode(carry % 10);
            carry /= 10;
            tmp->next = dummy->next;
            dummy->next = tmp;
            dummy->val = carry;
        }
        return dummy->val == 0 ? dummy->next : dummy; 
    }
};
```

#### Solution 2

Convert lists to stacks.

Time O(n)

Space O(n)

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
        stack<int> s1, s2, sum;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        int carry = 0;
        while (!s1.empty() or !s2.empty()) {
            if (!s1.empty()) {
                carry += s1.top(); s1.pop();
            }
            if (!s2.empty()) {
                carry += s2.top(); s2.pop();
            }
            sum.push(carry % 10);
            carry /= 10;
        }
        if (carry) sum.push(1);
        
        ListNode* dummy = new ListNode(-1), *cur = dummy;
        while (!sum.empty()) {
            cur->next = new ListNode(sum.top()); sum.pop();
            cur = cur->next;
        }
        return dummy->next;
    }
};
```

#### Solution 3

No stack. 
1. Get the lengths of two lists. Loop over the longer one for the length of the length difference.
    Maintain a "cur" node as the last node of the current summed list.
2. Create a new node for each of the examined longer nodes. Maintain a "idx" pointer pointing to 
the most right node whose val is not 9. 
3. Loop over two lists together. Add up their vals. If bigger than 9, right->val++.
   All its right nodes must be 9, so turn them into 0. Set "idx" to "cur". Get the residual of val, 
   add it to the end of the new list. 

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
    int getLen(ListNode* head) {
        int len = 0;
        while (head) {
            head = head->next;
            len++;
        }
        return len;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = getLen(l1);
        int len2 = getLen(l2);
        if (len1 < len2) swap(l1, l2);
        
        int diff = abs(len1 - len2);
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        ListNode* last = cur;
        for (int i = 0; i < diff; i++) {
            cur->next = new ListNode(l1->val);
            cur = cur->next;
            if (l1->val != 9) last = cur;
            l1 = l1->next;
        }
        
        while (l1) {
            int sum = l1->val + l2->val;
            if (sum > 9) {
                last->val += 1;
                while (last->next) {
                    last->next->val = 0;
                    last = last->next;
                }
                sum -= 10;
            }
            cur->next = new ListNode(sum);
            cur = cur->next;
            if (cur->val != 9) last = cur;
            l1 = l1->next;
            l2 = l2->next;
        }
        return dummy->val == 0 ? dummy->next : dummy;
    }
};
```
