### 234\. [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)

Given a singly linked list, determine if it is a palindrome.

Example 1:
```
Input: 1->2
Output: false
```
Example 2:
```
Input: 1->2->2->1
Output: true
```
Follow up:
Could you do it in O(n) time and O(1) space?


#### Solution 1

No extra space.
Find the middle point. Reverse the second half.

Time: O(n) Space: O(1)

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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // Find the middle point.
        ListNode* slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half.
        fast = slow->next;
        while (fast->next) {
            ListNode *tmp = fast->next;
            fast->next = tmp->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }

        // Compare head and middle point and continue.
        slow = slow->next;
        while (slow) {
            if (head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};
```

#### Solution 2

Ues a vector to store values.

Time: O(n) Space: O(n)

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
    bool isPalindrome(ListNode* head) {
        vector<int> res;
        while (head) {
            res.push_back(head->val);
            head = head->next;
        }
        int left = 0, right = res.size() - 1;
        while (left < right) {
            if (res[left] != res[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
```
