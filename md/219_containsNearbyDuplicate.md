### 219\. [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/)

Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:
```
Input: nums = [1,2,3,1], k = 3
Output: true
```

Example 2:
```
Input: nums = [1,0,1,1], k = 1
Output: true
```
Example 3:
```
Input: nums = [1,2,3,1,2,3], k = 2
Output: false
```

#### Solution 1

hash map recording seen elements and position

C++

```
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(nums[i]) != m.end() and i - m[nums[i]] <= k) {
                return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};
```

#### Solution 2

hash set, two pointers, adding elements to set at high pointer
and removing elemnts at low pointer to keep them at a distance
of k.

C++

```
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        int low = 0, high = 0;
        while (high < nums.size()) {
            if (high - low > k) s.erase(nums[low++]);
            if (s.find(nums[high]) != s.end()) return true;
            s.insert(nums[high++]);
        }
        return false;
    }
};
```
