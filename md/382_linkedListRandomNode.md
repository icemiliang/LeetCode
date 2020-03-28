### 382\. [Linked List Random Node](https://leetcode.com/problems/linked-list-random-node/)

Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?

Example:
```
// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();
```

#### Solution 1

Reservior sampling. Only keep the head node in the class.
Each time getting a randome node, loop the list and use reservior sampling to get it.
The essential idea of reservior sampling is to sample the ith known value
with a probabilty of 1/i. Maintain a result node. Each time assign the current node
to the result node with a probabilty of 1/i.

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
    ListNode *head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res = -1;
        ListNode* cur = head;
        int len = 1;
        while (cur) {
            int keep = rand() % len;
            if (keep == 0) res = cur->val;
            ++len;
            cur = cur->next;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
```

#### Solution 2

This solution uses a underlying vector to store all the nodes during construction.
Then, each time we only need to generate a random index and return the node.

C++

```
class Solution {
public:
	Solution(ListNode *head) {
		while(head) {
			m_v.push_back(head);
			head = head->next;
		}
	}

	int getRandom() {
		return m_v[rand()%m_v.size()]->val;	
	}
protected:
	vector<ListNode*> m_v;
};
```
