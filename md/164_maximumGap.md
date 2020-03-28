### 164\. [Maximum Gap](https://leetcode.com/problems/maximum-gap/)

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Return 0 if the array contains less than 2 elements.

Example 1:
```
Input: [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either
             (3,6) or (6,9) has the maximum difference 3.
```

Example 2:
```
Input: [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
```

Note:

* You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
* Try to solve it in linear time/space.

#### Solution 1

C++

```
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        auto lohi = minmax_element(nums.begin(), nums.end());
        int lo = *lohi.first, hi = *lohi.second;
        int gap = max((hi - lo) / (n - 1), 1);
        int m = (hi - lo) / gap + 1;
        vector<int> bucketsMin(m, INT_MAX);
        vector<int> bucketsMax(m, INT_MIN);
        for (int num : nums) {
            int k = (num - lo) / gap;
            if (num < bucketsMin[k]) bucketsMin[k] = num;
            if (num > bucketsMax[k]) bucketsMax[k] = num;
        }
        int i = 0, j; 
        gap = bucketsMax[0] - bucketsMin[0];
        while (i < m) {
            j = i + 1;
            while (j < m and bucketsMin[j] == INT_MAX and bucketsMax[j] == INT_MIN) {
            	++j;
            }
            if (j == m) break;
            gap = max(gap, bucketsMin[j] - bucketsMax[i]);
            i = j;
        }
        return gap;
    }
};
```

#### Solution 2

C++

```
class Solution {
public:
	int maximumGap(vector<int> &nums) {
		int n = nums.size();
		if (n < 2) return 0;
		int minV = nums[0], maxV = nums[0];
		int bucket_size, bucket_num, bucket_id;
		int maxGap = INT_MIN;
		int last_max;

        for (int num : nums) {
            if (minV > num) minV = num;
            else if (maxV < num) maxV = num;
        }
        
        bucket_size = max(1, (maxV - minV ) / (n - 1));
        bucket_num  = (maxV - minV) / bucket_size + 1;

        if (bucket_num <= 1) return (maxV - minV); 
        vector<int> bucket_max(bucket_num, INT_MIN);
        vector<int> bucket_min(bucket_num, INT_MAX);
        vector<int> bucket_count(bucket_num, 0);
        
        for (int num : nums) {
            bucket_id = (num - minV) / bucket_size;
            ++bucket_count[bucket_id];
            bucket_min[bucket_id] = bucket_min[bucket_id] > num ? num : bucket_min[bucket_id];
            bucket_max[bucket_id] = bucket_max[bucket_id] < num ? num : bucket_max[bucket_id];
        }
        
        last_max = minV;
        for (size_t i = 0; i < bucket_num; i++) {
            if (bucket_count[i] > 0) {
                maxGap = max(maxGap, bucket_min[i]- last_max);
                last_max = bucket_max[i];
            }
        }
        return maxGap;
	}
};
```
