### 496\. [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/)

You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:
```
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
```

Example 2:
```
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
```
Note:
1. All elements in nums1 and nums2 are unique.
2. The length of both nums1 and nums2 would not exceed 1000.

#### Solution 1

Brute force

C++

```
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            int j = 0, k = 0;
            while (j < nums2.size() and nums2[j] != nums1[i]) j++;
            k = j + 1;
            while (k < nums2.size() and nums2[k] < nums1[i]) k++;
            res[i] = k < nums2.size() ? nums2[k] : -1;
        }
        return res;
    }
};
```

#### Solution 2

C++

```
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> pos;
        for (int i = 0; i < nums2.size(); i++) {
            pos[nums2[i]] = i;
        }
        vector<int> res(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++) {
            int p = pos[nums1[i]];
            for (int j = p + 1; j < nums2.size(); j++) {
                if (nums2[j] > nums1[i]) {
                    res[i] = nums2[j];
                    break;
                }
            }
        }
        return res;
    }
};
```

#### Solution 3

Compute and use a hashmap to record the next greater for each element in nums2. 
Then, for nums1, just call the query element.

C++

```
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> todo;
        unordered_map<int, int> next;
        for (int num : nums2) {
            while (!todo.empty() and num > todo.top()) {
                next[todo.top()] = num;
                todo.pop();
            }
            todo.push(num);
        }
        
        vector<int> res(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); ++i) {
            auto it = next.find(nums1[i]);
            if (it != next.end()) {
                res[i] = it->second;
            }
        }
        return res;
    }
};
```
