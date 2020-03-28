### 136\. [Single Number](https://leetcode.com/problems/single-number)

Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
```
Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
```

#### Solution 1

```2*(a+c+c) - (a+a+b+b+c) = c```

C++

```
int singleNumber1(vector<int>& nums) {
	int sumVec = 0;
	for (int i = 0; i < nums.size(); i++) {
		sumVec += nums[i];
	}

	unordered_set<int> s(nums.begin(), nums.end());

	int sumSet = 0;
	for (int i:s) {
		sumSet += i;
	}

	return 2 * sumSet - sumVec;
}
```

#### Solution 2

a XOR b XOR a = a XOR a XOR b = b
Do XOR for every number starting with a 0.
Every number that appears twice will cancel out themselves.
The result is the number that appears once.

C++

```
int singleNumber2(vector<int>& nums) {
	int res = 0;
	for (auto num : nums) res ^= num;
	return res;
}
```
