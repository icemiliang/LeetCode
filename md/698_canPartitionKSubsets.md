### 698\. [Partition to K Equal Sum Subsets](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/)

Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.


Example 1:
```
Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
```

Note:

* 1 <= k <= len(nums) <= 16.
* 0 < nums[i] < 10000.

#### Solution 1

DFS. Keep visited array. scan until curSum == sum / k. Then start another search.

C++

```
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        vector<bool> visited(nums.size(), false);
        return dfs(nums, visited, k, 0, 0, sum / k);
    }
    
    bool dfs(vector<int>& nums, vector<bool>& visited, int k, int start, int curSum, int sum) {
        if (k == 1) return true;
        if (curSum == sum) return dfs(nums, visited, k - 1, 0, 0, sum);
        for (int i = start; i < nums.size(); i++) {
            if (visited[i]) continue;
            visited[i] = true;
            if (dfs(nums, visited, k, i + 1, curSum + nums[i], sum)) return true;
            visited[i] = false;
        }
        return false;
    }
};
```


#### Solution 2

Sort. large to small.

C++

```
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        sort(nums.begin(), nums.end(), greater<int>());
        vector<bool> visited(nums.size(), false);
        return dfs(nums, visited, k, 0, 0, sum / k);
    }
    
    bool dfs(vector<int>& nums, vector<bool>& visited, int k, int start, int curSum, int sum) {
        if (k == 1) return true;
        if (curSum > sum) return false;
        if (curSum == sum) return dfs(nums, visited, k - 1, 0, 0, sum);
        for (int i = start; i < nums.size(); i++) {
            if (visited[i]) continue;
            visited[i] = true;
            if (dfs(nums, visited, k, i + 1, curSum + nums[i], sum)) return true;
            visited[i] = false;
        }
        return false;
    }
};
```
