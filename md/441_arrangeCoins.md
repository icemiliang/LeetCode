### 441\. [Arranging Coins](https://leetcode.com/problems/arranging-coins/)

You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:
```
n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.
```

Example 2:
```
n = 8

The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

Because the 4th row is incomplete, we return 3.
```

#### Solution 1

Substract by each level until the remainder smaller than a full level.

Time: O(logn)
Space: O(1)

C++

```
class Solution {
public:
    int arrangeCoins(int n) {
        int res = 1;
        while (n >= res) {
            n -= res;
            ++res;
        }
        return res - 1;
    }
};
```

#### Solution 2

Binary search for the last full level index. 1 + 2 + 3 + ... + n = (1 + n) * n / 2

Time: O(loglogn)
Space: O(1)

C++

```
class Solution {
public:
    int arrangeCoins(int n) {
        int lo = 0, hi = max(1, (int)sqrt(2 * (long)n));;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int sum = mid % 2 ? (mid + 1) / 2 * mid : mid / 2 * (mid + 1);
            if (sum == n or (sum < n and sum + mid >= n)) return mid;
            else if (sum < n) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};
```
