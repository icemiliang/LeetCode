### 540\. [Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/)

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

 
Example 1:
```
Input: [1,1,2,3,3,4,4,8,8]
Output: 2
```
Example 2:
```
Input: [3,3,7,7,10,11,11]
Output: 10
```

Note: Your solution should run in O(log n) time and O(1) space.

#### Solution 1

Binary search

C++

```
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.empty()) return -1;
        if (nums.size() == 1) return nums[0];
        int low = 0, high = nums.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mid % 2 == 0) {
                if (mid < nums.size() - 1 and nums[mid] == nums[mid + 1]) {
                    low = mid + 2;
                }
                else high = mid;
            }
            else {
                if (nums[mid] == nums[mid - 1]) {
                    low = mid + 1;
                }
                else high = mid;
            }
        }
        return nums[high];
    }
};
```

#### Solution 2

Brute force

C++

```
class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		if (nums.size() < 3) return -1;
		for (int i = 0; i < nums.size()-1; i++) {
			if (nums[i-1] != nums[i] && nums[i] != nums[i+1]) {
				return nums[i];
			}
		}
		if (nums[0] != nums[1]) return nums[0];
		if (nums[nums.size()-1] != nums[nums.size()-2]) return nums[nums.size()-1];
		return 0;
	}
};
```
