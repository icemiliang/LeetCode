### 384\. [Shuffle an Array](https://leetcode.com/problems/shuffle-an-array/)

Shuffle a set of numbers without duplicates.

Example:
```
// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. 
Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
```

#### Solution 1

Another resevoir sampling problem. Store the original array and return it
when reset is called. When shuffle is called, return a new shuffled array.
To make each permutaton having an equal possibility, we can use resevoir 
sampling. First, copy the original array. Then, shuffle the new array by 
repeatedly swap elements and then return it. To shuffle the array, loop
the array, for each element nums[i], find an index j and swap nums[i] and
nums[j]. j is defined as one of the indices until i, including i.
By using resevoir sampling, at any time, every examined element has the 
equal possibility to be swapped to the same position. 

For example, [0,1,2,3].
iter 0: 0 has a prob of 1 to be at nums[0]
iter 1: 1 has a prob of 0.5 to be swapped with itself, keeping it at nums[1],
        and it has a prob of 0.5 to be swapped with 0, moving it to nums[0].
        Similarly, 0 has a prob of 0.5 at nums[0] and 0.5 at nums[1].
iter 2: 2 has a prob of 0.33 to be at nums[0], nums[1], or nums[2].
        Suppose 1 is at nums[0] with a prob of 0.5, it has 0.67 to be not chosen 
        to be swapped with 2, resulting in 0.33 at nums[0]. Similarly it has 
        0.33 to be at nums[1]. It also has 0.33 to be chosen to be swapped to nums[2].

        element  index   prob
iter 0:    0       0       1

iter 1:    0       0       1*1/2 = 1/2
           0       1       1*1/2 = 1/2
           1       0       1/2
           1       1       1/2

iter 2:    0       0       1/2 * 2/3 = 1/3
           0       1       1/2 * 2/3 = 1/3
           0       2       1/3
           1       0       1/2 * 2/3 = 1/3
           1       1       1/2 * 2/3 = 1/3
           1       2       1/3
           2       0       1/3
           2       1       1/3
           2       2       1/3

iter 3:    0       0       1/3 * 3/4 = 1/4
           0       1       1/3 * 3/4 = 1/4
           0       2       1/3 * 3/4 = 1/4
           0       3       1/4
           1       0       1/3 * 3/4 = 1/4
           1       1       1/3 * 3/4 = 1/4
           1       2       1/3 * 3/4 = 1/4
           1       3       1/4
           2       0       1/3 * 3/4 = 1/4
           2       1       1/3 * 3/4 = 1/4
           2       2       1/3 * 3/4 = 1/4
           2       3       1/4
           3       0       1/4        
           3       1       1/4        
           3       2       1/4        
           3       3       1/4       

```
class ShuffleArray {
public:
    ShuffleArray(vector<int> nums) : v(nums) {}

    vector<int> reset() {
        return v;
    }

    vector<int> shuffle() {
        vector<int> res(v);
        for (int i = 0; i < res.size(); i++) {
            int j = rand()%(i+1);
            swap(res[i], res[j]);
        }
        return res;
    }

protected:
    vector<int> v;
};
```
