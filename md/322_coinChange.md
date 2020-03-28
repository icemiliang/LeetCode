### 322\. [Coin Change](https://leetcode.com/problems/coin-change/)

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
```
Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
```

Example 2:
```
Input: coins = [2], amount = 3
Output: -1
```

Note:
You may assume that you have an infinite number of each kind of coin.

#### Solution 1

We can recursively solve the problem. We start by adding the largest coin 
as many times as possible. If it didn't add up to the exact amount, remove
the last one and try adding a smaller coint. Remember to early stop if the 
current step is already larger than the current best.

DFS

C++

```
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int res = amount + 1;
        dfs(coins, coins.size() - 1, amount, 0, res);
        return res == amount + 1 ? -1 : res;
    }
    
    void dfs(vector<int>& coins, int type, int amount, int cur, int& res) {
        if (type < 0) return;
        if (amount % coins[type] == 0) {
            res = min(res, cur + amount / coins[type]);
            return;
        }
        
        for (int i = amount / coins[type]; i >= 0; --i) {
            if (cur + i > res) return;
            dfs(coins, type - 1, amount - i * coins[type], cur + i, res);
        }
    }
};
```

Python 

```
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        INT_MAX = 9223372036854775807
        def dfs(coins: List[int], type: int, amount: int, cur: int, res: int) -> int:
            if type < 0:
                return res
            if amount % coins[type] == 0:
                return min(res, cur + amount // coins[type]);

            for i in range(amount // coins[type], -1, -1):
                if cur + i >= res:
                    return res;
                res = dfs(coins, type - 1, amount - i * coins[type], cur + i, res)
            return res
        coins.sort()
        res = INT_MAX
        res = dfs(coins, len(coins) - 1, amount, 0, res)
        return -1 if res == INT_MAX else res;
```

#### Solution 2

Another solution uses dynamic programming. DP has two elements: state array and update function.
We can use the state array to store at i the minimum number of coins to add up to i. Then,
the update function would be given that we want to get to i and the coins, the minimum number
has to be dp[i - coin] + 1. Because we need to try all the coins for one DP position, we need
the compare the current solution with previously calculated DP[i]. Thus, the DP array has to
be initialized with a big number. Amount + 1 is a safe upper bound. The solution has to be
smaller than or equal to using all one cents.

DP

Time: O(n \* amount)
Time  O(amount)

C++

```
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    	vector<int> dp(amount + 1, amount + 1);
    	dp[0] = 0;
    	for (int i = 1; i <= amount; i++) {
    		for (int coin : coins) {
    			if (i >= coin) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
    			}	
    		}
    	}
    	return dp[amount] > amount ? -1 : dp[amount];
    }
};
```
