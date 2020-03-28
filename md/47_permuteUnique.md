### 47\. [Permutations II](https://leetcode.com/problems/permutations-ii/)

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:
```
Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
```

#### Solution 1

Similar to [46. Permutations](https://leetcode.com/problems/permutations/) except that 
the input array may contain duplicates and the result cannot.

C++

```
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> out(nums.size(), 0);
        vector<bool> visited(nums.size(), false);
        dfs(nums, 0, out, visited, res);
        return res;
    }
    
    void dfs(vector<int>& nums, int pos, vector<int>& out, vector<bool>& visited, vector<vector<int>>& res) {
        if (pos >= nums.size()) {
            res.push_back(out);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;
            if (i > 0 and nums[i] == nums[i - 1] and !visited[i - 1]) continue;
            visited[i] = true;
            out[pos] = nums[i];
            dfs(nums, pos + 1, out, visited, res);
            visited[i] = false;
        }
    }
};
```

#### Solution 2

No visited array, but need to pass value not reference each time.

C++

```
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        permute(nums, 0, res);
        return res;
    }
    
private:
    void permute(vector<int> nums, int i, vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(nums);
            return;
        }
        
        for (int j = i; j < nums.size(); j++) {
            if (j == i or nums[j] != nums[i]) {
                swap(nums[i], nums[j]);
                permute(nums, i + 1, res);
            }
        }
    }
};
```
