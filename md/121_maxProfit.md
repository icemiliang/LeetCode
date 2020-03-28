### 121\. [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)


Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.


Example 1:
```
Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
```

Example 2:
```
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
```


#### Solution 1

We can find the maximum profit with one loop. Keep two numbers -- minimum seen number and 
the maximum profit so far. Whenever we see a smaller number then the current buy price, 
we buy at the new price. Also, if the profit whether negative or positive to sell the stock
at the current price is higher than the current best, sell it now.

C++

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, buy = INT_MAX;
        for (int price : prices) {
            buy = min(buy, price);
            res = max(res, price - buy);
        }
        return res;
    }
};
```

Python

```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res, buy = 0, float('inf')
        for price in prices:
            buy = min(buy, price)
            res = max(res, price-buy)
        return res
```

#### Solution 2

Brute force can be applied to this problem too. We just compute the difference between each two 
elements. Return the highest one. Leetcode OJ doesn't allow this. It exceeds its time limit.

C++

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 0; i < prices.size()-1; i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                int profit = prices[j] - prices[i];
                if (profit > res) res = profit;
            }
        }
        return res;
    }
};
```

Python

```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res = 0
        for i in range(len(prices)):
            for j in range(i + 1, len(prices)):
                profit = prices[j] - prices[i]
                if profit > res:
                    res = profit
        return res
```
