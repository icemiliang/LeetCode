### 1099\. [Two Sum Less Than K](https://leetcode.com/problems/two-sum-less-than-k/)

Given an array A of integers and integer K, return the maximum S such that there exists i < j with A[i] + A[j] = S and S < K. If no i, j exist satisfying this equation, return -1.

 

Example 1:
```
Input: A = [34,23,1,24,75,33,54,8], K = 60
Output: 58
Explanation: 
We can use 34 and 24 to sum 58 which is less than 60.
```
Example 2:
```
Input: A = [10,20,30], K = 15
Output: -1
Explanation: 
In this case it's not possible to get a pair sum less that 15.
 ```

Note:

1. 1 <= A.length <= 100
2. 1 <= A[i] <= 1000
3. 1 <= K <= 2000

#### Solution 1

Brute force. O(n^2)

C++

```
class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        int res = -1;
        for (int i = 0; i < A.size() - 1; i++) {
            for (int j = i + 1; j < A.size(); j++) {
                int S = A[i] + A[j];
                if (S < K) res = max(res, S); 
            }
        }
        return res;
    }
};
```

#### Solution 2

Sort + two pointers O(nlog(n))

C++

```
class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int low = 0, high = A.size() - 1;
        int res = -1;
        while (low < high) {
            int sum = A[low] + A[high];
            if (sum < K) {
                res = max(res, sum);
                ++low;
            }
            else --high;
        }
        return res;
    }
};
```
