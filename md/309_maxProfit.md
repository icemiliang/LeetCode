### 309\. [Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:
```
Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]
```

#### Solution 1

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)

Three states s0, s1, s2



C++

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        vector<int> s0(n, 0);
        vector<int> s1(n, 0);
        vector<int> s2(n, 0);
        s1[0] -= prices[0];
        s0[0] = 0;
        s2[0] = INT_MIN;
        for (int i = 1; i < n; i++) {
            s0[i] = max(s2[i - 1], s0[i - 1]);
            s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
            s2[i] = s1[i - 1] + prices[i];
        }
        return max(s2[n - 1], s0[n - 1]);
    }
};
```

Only the last states matter, no need to store previous states.

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int s0 = 0;
        int s1 = -prices[0];
        int s2 = INT_MIN;
        
        for (int i = 1; i < prices.size(); i++) {
            int s11 = s1;
            s1 = max(s1, s0 - prices[i]);
            s0 = max(s2, s0);
            s2 = s11 + prices[i];
        }
        return max(s0, s2);
    }
};
```

A more concise way.

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = 0, hold = INT_MIN, rest = 0;
        for (int i=0; i<prices.size(); ++i)
        {
            int prvSold = sold;
            sold = hold + prices[i];
            hold = max(hold, rest-prices[i]);
            rest = max(rest, prvSold);
        }
        return max(sold, rest);
    }
};
```