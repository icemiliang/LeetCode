### 646\. [Maximum Length of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain/)

You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:
```
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
```
Note:
1. The number of given pairs will be in the range [1, 1000].

#### Solution 1

C++

```
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b){return a[1] < b[1];});
        int pre_end = INT_MIN;
        int len = 0;
        for (auto& pair : pairs) {
            if (pair[0] > pre_end) {
                pre_end = pair[1];
                len++;
            }
        }
        return len;
    }
};
```

#### Solution 2

https://leetcode.com/problems/maximum-length-of-pair-chain/discuss/105641/C%2B%2B-DPDetailed-Explanation-for-Beginners

C++

```
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        //define dp[i]:the maximum chain we can get at position i
        //our goal:get d[totol_length-1](the final position)
        //dp[i]=max(dp[i],dp[j]), for j in range [0,i), if pairs[i][0]<=pairs[j][1]
        //dp[i]=max(dp[i],dp[j]+1), for j in range [0,i), if pairs[i][0]>pairs[j][1]
        //border:dp[0]=1
        //NOTE:we must sort the array
        int len=pairs.size();
        vector<int>dp(len,0);
        sort(pairs.begin(),pairs.end(),cmp);
        dp[0]=1;
        for(int i=0;i<len;i++){
            for(int j=0;j<i;j++){
                if(pairs[i][0]<=pairs[j][1])
                    dp[i]=max(dp[i],dp[j]);
                else
                    dp[i]=max(dp[i],dp[j]+1);
            }
        }
        return dp[len-1];
    }
    //sort according to the first column, i.e. the first number in each pair
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0]<b[0];
    }
};
```
