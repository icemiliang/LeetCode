### 119\. [Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/)

Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.

![alt text](PascalTriangleAnimated2.gif)

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:
```
Input: 3
Output: [1,3,3,1]
```

Follow up:
Could you optimize your algorithm to use only O(k) extra space?

#### Solution 

C++

```
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res{{1}};
        for (int i = 1; i <= rowIndex; ++i) {
            vector<int> next(res.size() + 1, 1);
            for (int j = 1; j < i; ++j) {
                next[j] = res[j] + res[j - 1];
            }
            res = next;
        }
        return res;
    }
};
```

#### Solution

```
Note that this solution is math derived from number of Combinations.

Each line of Pascal's Triangle is a full set of Combination number based on k .

comb(k,p) = k! /( p! *(k-p)!) = comb(k,k-p)

if p < k-p

comb(k,p) = comb(k,p-1) * (k-p+1) / p

Because :

comb(k,p) = [ k * (k-1) * (k-2) *... (k-p+1)] / [1 * 2 * 3 *...(p)]
```

C++

```
class Solution {
public:
	vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        if (rowIndex == 1) return {1, 1};
	    vector<int> ans(rowIndex + 1, 1);
	    int small = rowIndex / 2;
	    long comb = 1;
	    int j = 1;
	    for (int i = rowIndex; i >= small; --i){
	        comb *= i;
	        comb /= j;
	        ++j;
	        ans[i - 1] = (int)comb;
	        ans[j - 1] = (int)comb;
	    }
	    return ans;
	}
};
```