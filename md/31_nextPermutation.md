### 31\. [Next Permutation](https://leetcode.com/problems/next-permutation/)

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
```
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
```

#### Solution 1

Start from the end, find the first element i that is smaller than its successor.
Start from the end, find the first elment j that is larger than i.
Swap those two, now the elements after i are in the descending order.

C++

```
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        int j = n - 1;
        while (i >= 0 and nums[i] >= nums[i + 1]) --i;
        if (i >= 0) {
            while (nums[i] >= nums[j]) --j;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
```

A different implementation.

```
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1, k = i;
        while (i > 0 and nums[i - 1] >= nums[i]) --i;
        for (int j = i; j < k; ++j, --k) {
            swap(nums[j], nums[k]);
        }
        if (i > 0) {
            k = i--;
            while (nums[k] <= nums[i]) ++k;
            swap(nums[i], nums[k]);
        }
    }
};
```

#### Solution 2

Search from the end for the first element that is smaller than its next element.
If no such element, that means the array is in descending order. Reverse it and return.
If such element (pivot), binary search for the last element that is larger than pivot,
since the elements after the pivot must be in descending order. Swap pivot and the found.
Then reverse the subarray after pivot.

https://leetcode.com/problems/next-permutation/discuss/13921/1-4-11-lines-C%2B%2B
has different implementations.

C++

```
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 1; i > 0; --i) {
            if (nums[i - 1] < nums[i]) {
                auto it = lower_bound(nums.begin() + i + 1, nums.end(), nums[i - 1], greater<int>());
                it = prev(it);
                swap(nums[it - nums.begin()], nums[i - 1]);
                reverse(nums.begin() + i, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};
```

Trivial change. Combine two reverse.

```
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        for (; i > 0; --i) {
            if (nums[i - 1] < nums[i]) {
                auto it = lower_bound(nums.begin() + i + 1, nums.end(), nums[i - 1], greater<int>());
                it = prev(it);
                swap(nums[it - nums.begin()], nums[i - 1]);
                break;
            }
        }
        reverse(nums.begin() + i, nums.end());
    }
};
```
