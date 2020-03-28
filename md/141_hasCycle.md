### 141\. [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/submissions/)

Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.


Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.


Example 2:

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the first node.


Example 3:

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.


Follow up:

Can you solve it using O(1) (i.e. constant) memory?



#### Solution 1

Two pointers. One moves by a step of 1, one moves by a step of 2.
If the fast one meets the slow one, then there is a cycle.

```
bool hasCycle(ListNode *head) {
	if (!head or !head->next) return false;
	ListNode *slow = head, *fast = head;
	while (fast and fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow) return true;
	}
	return false;
}
```

#### Solution 2

Another solution uses one pointer but with a set to store all visited nodes.
Loop the list with a pointer and each time visiting a node, check if the 
node is in the set. Return true if so or otherwise continue the search.

```
bool hasCycle(ListNode *head) {
	if (!head or !head->next) return false;
	unordered_set<ListNode*> visited({head});
	while (head->next) {
		head = head->next;
		if (visited.count(head)) return true;
		visited.insert(head);
	}
	return false;
}
```
