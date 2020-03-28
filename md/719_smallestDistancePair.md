### 719\. [Find K-th Smallest Pair Distance](https://leetcode.com/problems/find-k-th-smallest-pair-distance/)

Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

Example 1:
```
Input:
nums = [1,3,1]
k = 1
Output: 0 
Explanation:
Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
```
Note:
1. 2 <= len(nums) <= 10000.
2. 0 <= nums[i] < 1000000.
3. 1 <= k <= len(nums) * (len(nums) - 1) / 2.

#### Solution 1

short + binary search

C++

```
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), low = 0, high = 1000000;
        while (low < high) {
            int mid = low + (high - low) / 2, cnt = 0;
            for (int i = 0, j = 0; i < n; i++) {
                while (j < n and nums[j] - nums[i] <= mid) j++;
                cnt += j - i - 1;
            }
            if (cnt < k) 
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};
```

#### Solution 2

Bucket sort

C++

```
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int cnt[1000001] = {0};
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                cnt[abs(nums[i] - nums[j])]++;
            }
        }
        for (int i = 0; i < 1000001; i++) {
            if (cnt[i] >= k) return i;
            k -= cnt[i];
        }
        return 0;
    }
};
```
