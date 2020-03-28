### 21\. [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:
```
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
```

#### Solution 1

The problem can be a starting point for learning about linked list. A classic linked list consists 
a number of node each having a value and a pointer to the next node. Thus, there is no direct method
to access a node if not looping the list from the first node, but that is another story. In this
problem, we need to merge two lists into one. We can use the original nodes to build the new list.
Then, all we need to do is change the next pointer of the nodes. We first create a dummy node to lead the new list. Because we need to return the head of the newly built list or otherwise we will loose it
because we cannot go backward. We also need a node to record the currently last node of the new list.
Now, we can begin by assuming both lists have remaining nodes to be examined. We compare the heads of
the two lists and put the smaller one next to the current node. Then, the head of the chosen list can 
go to the next node. When we reach the end of either node, then we just append the rest of the remaining
node to the current last node of the new list. In the end return the next node of the dummy node because
that is the head, the dummy node is the node before the node that belongs to the original lists.

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
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
        
        cur->next = l1 ? l1 : l2;
        return dummy->next;
    }
};
```

Python 

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode(-1)
        cur = dummy
        while l1 and l2:
            if l1.val < l2.val:
                cur.next = l1
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
            cur = cur.next
        
        cur.next = l1 if l1 else l2
        return dummy.next
```


#### Solution 2

We can also merge the lists with recursion. The general idea is that all the nodes that come
after a node have values no smaller than the node. Thus, suppose we have built a sublist, then
we need to append it to the smaller node and then return the current node. If one of the 
nodes is null, simply return the other node. If the other node is also null, that's fine.

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
```

Python

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        if not l2:
            return l1
        if l1.val < l2.val:
            l1.next = self.mergeTwoLists(l1.next, l2)
            return l1
        else:
            l2.next = self.mergeTwoLists(l1, l2.next)
            return l2
```
