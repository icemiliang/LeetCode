### 77\. [Combinations](https://leetcode.com/problems/combinations/)

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

```
Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
```

#### Solution 1

DFS backtrack

C++

```
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> row;
        dfs(n, k, 1, row, res);
        return res;
    }

    void dfs(int n, int k, int i, vector<int>& row, vector<vector<int>>& res) {
        if (k == 0) {
            res.push_back(row);
            return;
        }
        for (int j = i; j <= n; ++j) {
            row.push_back(j);
            dfs(n, k - 1, j + 1, row, res);
            row.pop_back();
        }
    }
};
```

#### Solution 2

https://leetcode.com/problems/combinations/discuss/26992/Short-Iterative-C%2B%2B-Answer-8ms
https://www.cnblogs.com/grandyang/p/4332522.html
C++

```
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		int i = 0;
		vector<int> row(k, 0);
		while (i >= 0) {
			row[i]++;
			if (row[i] > n) --i;
			else if (i == k - 1) res.push_back(row);
			else {
			    ++i;
			    row[i] = row[i - 1];
			}
		}
		return res;
	}
};
```
