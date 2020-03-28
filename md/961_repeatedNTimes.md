### 961\. [N-Repeated Element in Size 2N Array](https://leetcode.com/problems/n-repeated-element-in-size-2n-array/)

In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.

Return the element repeated N times.

Example 1:
```
Input: [1,2,3,3]
Output: 3
```

Example 2:
```
Input: [2,1,2,5,3,2]
Output: 2
```

Example 3:
```
Input: [5,1,5,2,5,3,5,4]
Output: 5
```

Note:

1. ```4 <= A.length <= 10000```
2. ```0 <= A[i] < 10000```
3. ```A.length``` is even


#### Solution 1

Maintain a set to store seen values. For each new value, 
if it is in the set, return it.

Time: O(n)
Space: O(n)

C++

```
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) {
            if (s.find(num) != s.end()) return num;
            else s.insert(num);
        }
        return -1;
    }
};
```


#### Solution 2

Sort and check middle

Time: O(nlogn)
Space: O(1)

C++

```
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        sort(A.begin(), A.end());
        int mid = A.size() / 2;
        if (A[mid] == A[mid - 1]) return A[mid];
        if (A[mid] == A[mid + 1]) return A[mid];
        return A[mid - 1];
    }
};
```

#### Solution 3

https://leetcode.com/problems/n-repeated-element-in-size-2n-array/discuss/208563/JavaC%2B%2BPython-O(1)-Solution

Time: O(n)
Space: O(1)

C++

```
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for (int i = 2; i < nums.size(); ++i)
            if (nums[i] == nums[i - 1] || nums[i] == nums[i - 2])
                return nums[i];
        return nums[0];
    }
};
```

#### Solution 4

Time: O(1)
Space: O(1)

C++

```
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int i = 0, j = 0, n = A.size();
        while (i == j or A[i] != A[j]) {
            i = rand() % n;
            j = rand() % n;
            cout << i << " "<< j << endl;
        }
        return A[i];
    }
};
```
