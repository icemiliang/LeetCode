### 59\. [Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/)

Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:
```
Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
```

#### Solution 1

This is a spin-off [54 Spiral Matrix](https://leetcode.com/problems/spiral-matrix/). We just need to 
define the 2d array beforehand and fill in the value according to the spiral order.

C++ 

```
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int up = 0, down = n - 1, left = 0, right = n - 1;
        int count = 1;
        while (true) {
            for (int j = left; j <= right; j++) res[up][j] = count++;
            if (++up > down) break;
            
            for (int i = up; i <= down; i++) res[i][right] = count++;
            if (--right < left) break;
            
            for (int j = right; j >= left; j--) res[down][j] = count++;
            if (--down < up) break;
            
            for (int i = down; i >= up; i--) res[i][left] = count++;
            if (++left > right) break;
        }
        return res;
    }
};
```

#### Solution 2

In python, there is a simple way to implement the idea due to the difference between C++ and Python on
the % operation. In C++ "-1 % 2 == -1" but in Python "-1 % 2 == 1".

Python

```
class Solution:
    def generateMatrix(self, n):
        res = [[0] * n for _ in range(n)]
        i, j, di, dj = 0, 0, 0, 1
        for k in range(1, n * n + 1):
            res[i][j] = k
            if res[(i+di)%n][(j+dj)%n]:
                di, dj = dj, -di
            i += di
            j += dj
        return res
```
