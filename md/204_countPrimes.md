### 204\. [Count Primes](https://leetcode.com/problems/count-primes/)

Count the number of prime numbers less than a non-negative number, n.

Example:
```
Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
```

#### Solution 1

Define a vector of n trues and set all the non-prime numbers to false;

C++

```
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) return 0;
        vector<bool> isPrime(n, true);
        isPrime[0] = false; isPrime[1] = false;
        int limit = sqrt(n);

        for (int i = 2; i <= limit; ++i)
            for (int j = i * i; j < n; j += i)
                isPrime[j] = false;

        return count(isPrime.begin(), isPrime.end(), true);
    }
};
```

A faster version

```
class Solution {
public:
    int countPrimes(int n) {
        if (--n < 2) return 0;
        int m = (n + 1) / 2, count = m, k, u = (sqrt(n) - 1) / 2;
        bool notPrime[m] = {0};

        for (int i = 1; i <= u; ++i)
            if (!notPrime[i])
              for (k = (i + 1) * 2 * i; k < m; k += i * 2 + 1)
                  if (!notPrime[k]) {
                      notPrime[k] = true;
                      count--;
                  }
        return count;
    }
};
```
