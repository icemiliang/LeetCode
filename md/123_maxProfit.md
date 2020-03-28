### 123\. [Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:
```
Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
```

Example 2:
```
Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
```
Example 3:
```
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
```

#### Solution 1

This problem is a special case of [188 Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/) 
when k = 2. We can use that solution.

C++

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return maxProfitK(2, prices);
    }
    
    int maxProfitK(int k, vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        // if k is too big, the problem degenerates to 122, buy and sell II
        if (k > n / 2) {
            for (int i = 1; i < prices.size(); i++) {
                if (prices[i] - prices[i - 1] > 0)
                    profit += prices[i] - prices[i - 1];
            }
            return profit;
        }
        
        vector<int> local(k + 1, 0); // trade as many times as possible
        vector<int> global(k + 1, 0); // trade only when profit
        for (int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i - 1];
            // update before modified, thus update from the end
            for (int j = k; j > 0; j--) {
                local[j] = max(global[j - 1] + diff, local[j] + diff);
                global[j] = max(global[j], local[j]);
            }
        }
        return global.back();
    }
};
```
