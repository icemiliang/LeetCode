### 188\. [Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)

Say you have an array for which the i-th element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example 1:
```
Input: [2,4,1], k = 2
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
```

Example 2:
```
Input: [3,2,6,5,0,3], k = 2
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
```

#### Solution 1

C++

```
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
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
