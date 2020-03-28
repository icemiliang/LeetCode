### 46\. [Permutations](https://leetcode.com/problems/permutations/)

Given a collection of distinct integers, return all possible permutations.

Example:
```
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
```

#### Solution 1

DFS

Fill each position with all the numbers but use a visited vector to track which numbers have been used and exclude them numbers.

Time: O(n^2)
Space: O(n)

C++

```
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out(nums.size(), 0);
        vector<bool> visited(nums.size(), false);
        dfs(nums, 0, out, visited, res);
        return res;
    }
    
    void dfs(vector<int>& nums, int pos, vector<int>& out, vector<bool>& visited, vector<vector<int>>& res) {
        if (pos == out.size()) {
            res.push_back(out);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;
            out[pos] = nums[i];
            visited[i] = true;
            dfs(nums, pos + 1, out, visited, res);
            visited[i] = false;
        }
    }
};
```

#### Solution 2

Insert a new element at each position of all previous arrays.

C++

```
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        queue<vector<int>> todo;
        todo.push({});
        for (int num : nums) {
            for (int i = todo.size() - 1; i >= 0; --i) {
                auto t = todo.front();
                todo.pop();
                for (int j = 0; j <= t.size(); ++j) {
                    vector<int> one = t;
                    one.insert(one.begin() + j, num);
                    todo.push(one);
                }
            }
        }
        vector<vector<int>> res;
        while (!todo.empty()) {
            res.push_back(todo.front());
            todo.pop();
        }
        return res;
    }
};
```
