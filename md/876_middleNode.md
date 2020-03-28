### 876\. [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)

Given a non-empty, singly linked list with head node head, return a middle node of linked list.

If there are two middle nodes, return the second middle node.

Example 1:
```
Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.
```
Example 2:
```
Input: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
Since the list has two middle nodes with values 3 and 4, we return the second one.
```

#### Solution 1

We have seen many problems in which we need to get the middle node, for example, 
when doing bindary search, or reversing the second half of the list. Keep a
one-step slow pointer and a two-step fast pointer and loop the list. When the fast
pointer reaches the end the slow pointer will be pointing to the middle node.
The only catch here is that if there are an even number of nodes, we need to return
the second middle node. That needs the while loop to go for one more node if faster 
reaches the end, so we we check 'fast' and 'fast->next' instead of 'fast->next' and 
'fast->next->next'.

```
class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		if (!head or !head->next) return head;
		ListNode* slow = head, *fast = head;
		while (fast and fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
}
```
