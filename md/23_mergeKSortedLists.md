### 23\. [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:
```
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
```

#### Solution 1

If you have seen problem 21, then you must know how to merge 2 sorted lists.
For k lists, we can consider only 2 at a time and reduce the problem to 21. 
We can follow the divide-and-conquer idea like we do for merge sort. Merge all 
the lists two by two and then merge the merged lists two by two until there is 
only one list left. We copy the solution from [21. Merge Two Sorted Lists]
(https://leetcode.com/problems/merge-two-sorted-lists/).

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        int k = lists.size();
        
        while (k > 1) {
            for (int i = 0; i < k / 2; i++) {
                lists[i] = merge2Lists(lists[i], lists[k - i - 1]);
            }
            k = (k + 1) / 2;
        }
        return lists[0];
    }
    
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1), *cur = dummy;
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
};
```

#### Solution 2

Another solution merges all the lists at the same time. Since all the lists are sorted, 
each time, we only need to consider the heads of the lists. Create a priority queue to 
store the heads of the lists according to their values and pop the front of the queue
in sequence to form a single list.

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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		auto cmp = [](ListNode* l1, ListNode* l2) { return l1->val > l2->val; };
		priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> todo(cmp);
		for (auto list : lists) if (list) todo.push(list);

		ListNode* dummy = new ListNode(-1), *cur = dummy;
		while (!todo.empty()) {
			auto t = todo.top(); todo.pop();
			cur->next = t;
			cur = cur->next;
			if (t->next) todo.push(t->next);
		}
		return dummy->next;
	}
};
```

Below is another way of defining the custom comparator.

```
struct compare{
    bool operator()(const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> todo;
        
        for (auto list : lists) {
            if (list) todo.push(list);
    	}
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while (!todo.empty()) {
            cur->next = todo.top();
            todo.pop();
            if (cur->next->next) todo.push(cur->next->next);
            cur = cur->next;
        }
        return dummy->next;
    }
};
```
