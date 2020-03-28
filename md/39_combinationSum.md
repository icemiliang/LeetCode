### 39\. [Combination Sum](https://leetcode.com/problems/combination-sum/)

Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

* All numbers (including target) will be positive integers.
* The solution set must not contain duplicate combinations.

Example 1:
```
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
```

Example 2:
```
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
```

#### Solution 1

DFS

C++

```
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> row;
        dfs(res, row, target, 0, candidates);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& row, int target, int pos, vector<int>& candidates) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(row);
            return;
        }
        for (int i = pos; i < candidates.size(); i++) {
            row.push_back(candidates[i]);
            dfs(res, row, target - candidates[i], i, candidates);    
            row.pop_back();    
        }
    }
};
```
