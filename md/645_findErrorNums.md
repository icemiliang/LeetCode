### 645\. [Set Mismatch](https://leetcode.com/problems/set-mismatch/)

The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.

Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.

Example 1:
```
Input: nums = [1,2,2,4]
Output: [2,3]
```
Note:
1. The given array size will in the range [2, 10000].
2. The given array's numbers won't have any order.

#### Solution 1

C++

```
class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		int *s = new int[nums.size()];
		fill(&s[0],&s[nums.size()],0);
		for (int num : nums) s[num-1] += num;
		vector<int> res(2);
		for (int i = 0; i < nums.size(); i++) {
			if (s[i] == 0) { 
				res[1] = i+1; 
				if (res[0] != 0) return res; 
				continue; 
			}
			if (s[i] != i+1) {
				res[0] = i+1;
				if (res[1] != 0) return res;
			}
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
	vector<int> findErrorNums(vector<int>& nums) {
		vector<int> res(2,-1);
		for (int num : nums) {
			if (nums[abs(num)-1] < 0) res[0] = abs(num);
			else nums[abs(num)-1] *= -1;
		}	
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0) res[1] = i+1;
		}
		return res;
	}	
};
```

#### Solution 3

The idea is using array indexing, that is putting each nums[i] into the position with index nums[i] - 1. Then, the array becomes [1,2,3,4,5...,n]. So we can find the duplicate number when nums[i] != i+1.

C++

```
class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			while (nums[i] != nums[nums[i]-1]) 
				swap(nums[i], nums[nums[i]-1]);
		}
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != i+1) return {nums[i],i+1};
		}
		return {};
	}
};
```

