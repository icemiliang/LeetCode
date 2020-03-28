### 238\. [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)

Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:
```
Input:  [1,2,3,4]
Output: [24,12,8,6]
```
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

#### Solution 1

Because we cannot solve it with division, we cannot compute the product of 
all the integers and then divide each integer individually. One solution uses
the idea of dynamic programming. We use an array to store the product of all
the integers to the left, and another array to store the product of all the 
integers to the right. Then, multiple each two elements at the same position
of the two arrays and return the resulting array.


C++

```
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1), res(n);
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < n; i++) {
            res[i] = left[i] * right[i];
        }
        return res;
    }
};
```

Python

```
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        left = [1 for i in range(n)]
        right = [1 for i in range(n)]
        res = [1 for i in range(n)]
        for i in range(1, n):
            left[i] = left[i - 1] * nums[i - 1]
        for i in range(n-2, -1, -1):
            right[i] = right[i + 1] * nums[i + 1]
        for i in range(n):
            res[i] = left[i] * right[i]
        return res
```


We can simplify the process and use one array to store intemediate numbers.
We loop the input array and record the left array as the previous solution.
Then, we use a variable, right, to record the current product, multiple it
by each new elemnet as we loop the input array again from right to left, and
multiple this variable to the left array. Then, the left array would be the 
final result.

C++
```
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        int right = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
};
```

Python

```
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = [1 for i in range(len(nums))]
        for i in range(1, len(nums)):
            res[i] = res[i - 1] * nums[i - 1]
        right = 1
        for i in range(len(nums) - 1, -1, -1):
            res[i] *= right
            right *= nums[i]
        return res
```


#### Solution 2

Brute force is applicable to this problem. For each element, we just compute
the product of all the other elements. However, Leetcode OJ does not allow this.

C++

```
class Solution {
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (j == i) continue;
                res[i] *= nums[j];
            }
        }
        return res;
    }
};
```

Python

```
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = [1 for i in range(len(nums))]
        for i in range(len(nums)):
            for j in range(len(nums)):
                if j == i:
                    continue
                res[i] *= nums[j]
        return res
```

#### Solution 3

Compute the product of all except zeros. If more than 2 zeros, all is zeros.
If 1 zero, only zero's position has value. 

C++

```
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long product = 1;
        vector<int> zeros;
        vector<int> res(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) zeros.push_back(i);
            else product *= nums[i];
            if (zeros.size() >= 2) return res;
        }
        if (zeros.size() == 1) {
            res[zeros[0]] = product;
            return res;
        }
        for (int i = 0; i < nums.size(); i++) {
            res[i] = int(product / nums[i]);
        }
        return res;
    }
};
```


#### Solution 4

C++

```
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int fromBegin = 1;
        int fromLast = 1;
        vector<int> res(n, 1);
        
        for(int i = 0; i < n; ++i){
            res[i] *= fromBegin;
            fromBegin *= nums[i];
        }
        
        for(int i = n - 1; i >= 0; --i) {
            res[i] *= fromLast;
            fromLast *= nums[i];
        }
        return res;
    }
};
```
