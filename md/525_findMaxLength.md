### 525\. [Contiguous Array](https://leetcode.com/problems/contiguous-array/)

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
```
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
```

Example 2:
```
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
```

Note: The length of the given binary array will not exceed 50,000.


#### Solution 1

Maintain a running sum. If one, plus one; if zero, minus one.
Then, an equal number of ones and zeros means a running sum 
being zero. Build a hash map from sum to its first occurance.

C++

```
class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		int res = 0, sum = 0;
		// hash map from sum to its first occurance
		unordered_map<int,int> m{{0,-1}};
		for (int i = 0; i < nums.size(); i++) {
			sum += (nums[i] == 1) ? 1 : -1;
			// if sum found before, compare with the current subarray
			// from i back to the sum's first occurance.
			if (m.find(sum) != m.end()) res = max(res, i-m[sum]);
			else m[sum] = i;
		}
		return res;
	}
};
```
