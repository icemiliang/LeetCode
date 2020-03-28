#### 78\. [Subsets](https://leetcode.com/problems/subsets/)

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:
```
	Input: nums = [1,2,3]
	Output:
	[
	  [3],
	  [1],
	  [2],
	  [1,2,3],
	  [1,3],
	  [2,3],
	  [1,2],
	  []
	]
```

#### Solution 1

BFS

```
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        for (int num : nums) {
            for (int i = res.size() - 1; i >= 0; i--) {
                res.push_back(res[i]);
                res.back().push_back(num);
            }
        }
        return res;
    }
};
```

#### Solution 2

DFS

We can also do the same logic with recurssion. Keep the current position in
the original array. That is where the next element we will add.
Start from pushing an empty vector into the result.
Then, we add the next element to the empty vector and continue with that vector
and pop out the element.

```
Using the above example.
			      []
		   /       |   \
		 [1] 	  [2]  [3]
	     / \	   |
	 [1,2] [1,3] [2,3]
	 /
 [1,2,3]
```

C++

```
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> row;
        dfs(nums, res, row, 0);
        return res;
    }
    
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& row, int pos) {
        res.push_back(row);
        for (int i = pos; i < nums.size(); i++) {
            row.push_back(nums[i]);
            dfs(nums, res, row, i + 1);
            row.pop_back();
        }
    }
};
```
