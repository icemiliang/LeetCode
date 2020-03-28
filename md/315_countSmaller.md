### 315\. [Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)

You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:
```
Input: [5,2,6,1]
Output: [2,1,1,0] 
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
```

#### Solution 1

Brute force. TLE.

C++

```
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> counts(nums.size(), 0);
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] < nums[i]) counts[i]++;
            }
        }
        return counts;
    }
};
```

#### Solution 2

Binary search

Build an array which is a sorted version of the input. Given an empty array, start from 
the most right element of the input and insert it in the new array. The current index 
when any new element is inserted into the new array will be how many smaller elements
are to its right in the original array.

C++

```
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> t, res(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            int left = 0, right = t.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (t[mid] >= nums[i]) right = mid;
                else left = mid + 1;
            }
            res[i] = right;
            t.insert(t.begin() + right, nums[i]);
        }
        return res;
    }
};
```

Use some high-level functions to replace the some code blocks.

C++

```
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> t, res(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            int d = distance(t.begin(), lower_bound(t.begin(), t.end(), nums[i]));
            res[i] = d;
            t.insert(t.begin() + d, nums[i]);
        }
        return res;
    }
};
```

#### Solution 3

BST

C++

```
class Solution {
public:
    struct Node {
        int val, smaller;
        Node *left, *right;
        Node(int v, int s) : val(v), smaller(s), left(NULL), right(NULL) {}
    };
    int insert(Node*& root, int val) {
        if (!root) {
            root = new Node(val, 0);
            return 0;    
        } 
        if (root->val > val) {
            root->smaller++;
            return insert(root->left, val);    
        } 
        return insert(root->right, val) + root->smaller + (root->val < val ? 1 : 0);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        Node *root = NULL;
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] = insert(root, nums[i]);
        }
        return res;
    }
};
```
