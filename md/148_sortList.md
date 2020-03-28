### 148\. [Sort List](https://leetcode.com/problems/sort-list/)

Sort a linked list in O(n log n) time using constant space complexity.

Example 1:
```
Input: 4->2->1->3
Output: 1->2->3->4
```

Example 2:
```
Input: -1->5->3->4->0
Output: -1->0->3->4->5
```

#### Solution 1

Priority queue.
Loop over the list and push every value into the queue.
Loop over the list again and replace the value with the top
of the queue and then pop out the queue.

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
    ListNode* sortList(ListNode* head) {
        if (!head or !head->next) return head;
		priority_queue<int, vector<int>, greater<int>> q;
		ListNode* cur = head;
		while (cur) {
			q.push(cur->val); 
			cur = cur->next;
		}
		cur = head;
		while (!q.empty()) {
			cur->val = q.top(); q.pop();
			cur = cur->next;
		}
		return head;
    }
};
```
#### Solution 2

Merge Sort.

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
	ListNode* merge(ListNode* l1, ListNode* l2) {
		ListNode* dummy = new ListNode(0), *cur = dummy;
		while (l1 and l2) {
			if (l1->val < l2->val) { 
				cur->next = l1; 
				l1 = l1->next; 
			}
			else { 
				cur->next = l2; 
				l2 = l2->next; 
			}
			cur = cur->next;
		}
		if (l1) cur->next = l1;
		if (l2) cur->next = l2;
		return dummy->next;
	}

    ListNode* sortList(ListNode* head) {
        if (!head or !head->next) return head;
		ListNode* slow = head, *fast = head, *pre = head;
		while (fast and fast->next) {
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		pre->next = NULL;
		return merge(sortList(head), sortList(slow));
    }
};
```

Another implementation.

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
    ListNode* sortList(ListNode* head) {
      	// split 
        ListNode* fast = head;
        ListNode* slow = head;
        if (!fast or !fast->next) return head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* h1 = head;
        ListNode* t1 = slow;
        ListNode* h2 = slow->next;
        t1->next = NULL;

        // sort each
        h1 = sortList(h1);
        h2 = sortList(h2);

        // merge
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while (h1 and h2) {
            if (h1->val < h2->val) {
                cur->next = h1;
                h1 = h1->next;
            }
            else {
                cur->next = h2;
                h2 = h2->next;
            }
            cur = cur->next;
		}
        if (h1) cur->next = h1;
        if (h2) cur->next = h2;
        return dummy->next;
    }
};
```
