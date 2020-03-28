### 528\. [Random Pick with Weight](https://leetcode.com/problems/random-pick-with-weight/)

Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

Note:

1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex will be called at most 10000 times.
Example 1:
```
Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]
```

Example 2:
```
Input: 
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0]
Explanation of Input Syntax:
```

The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array w. pickIndex has no arguments. Arguments are always wrapped with a list, even if there aren't any.


#### Solution 1

The description is not very clear to beginers. Let's use an example to explain the problem.
Suppose we have an input array [1, 3, 2, 4]. We want to randomly pick a number according to
their weights. There are four numbers. The total weight of these numbers 10. Thus, the number
at index 0 has a weight of 1/10, number 3 at index 1 has 3/10, number 2 at index 2 has 2/10,
number 4 at index 3 has 4/10. Thus, we want to pick number 3 at index 1 at the chance of 3 in 10.

Now, we can tackle the problem in this way. The total weight is 10. If we want to pick 3, then
we can just randomly choose a number between 1 and 10 and if the number is 1, 2, or 3, then we 
return 3. How to assign which number between 1 and 10 to 3? We can just use their order in the
original array. We can assign 1 -> 1, [2, 3, 4] -> 3, [5, 6] -> 2, [7, 8, 9, 10] -> 4. The trick 
is to build an array which records the current sum of the original array, i.e. [1, 4, 6, 10]. 
Then, randomly generate a number x between 1 and 10. If it is 1, return index 0; if it is between
2 and 4, return index 1; if it is between 5 and 6, return index 2; if it is between 7 and 10,
return index 3. Therefore, the problem boils down to a binary search of a randomly generated 
number in a sorted array.

The above explanation looks confusing too. I will circle back and refine it...


C++

```
class Solution {
    vector<int> sum;
public:
    Solution(vector<int>& w) {
        sum = w;
        for (int i = 1; i < w.size(); i++) {
            sum[i] = sum[i - 1] + w[i];
        }
    }
    
    int pickIndex() {
        int target = rand() % sum.back();
        int left = 0, right = sum.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (sum[mid] <= target) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};
```

Python

```
class Solution:
    def __init__(self, w: List[int]):
        self.sum = w
        for i in range(1, len(w)):
            self.sum[i] = self.sum[i - 1] + w[i]           

    def pickIndex(self) -> int:
        target = random.randint(0, self.sum[-1] - 1)
        left = 0; right = len(self.sum)
        while left < right:
            mid = left + (right - left) // 2
            if self.sum[mid] <= target:
                left = mid + 1
            else:
                right = mid
        return right
```
