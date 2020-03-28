### 215\. [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:
```
Input: [3,2,1,5,6,4] and k = 2
Output: 5
```

Example 2:
```
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
```
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.

#### Solution 1

priority queue

C++

```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> topK;
        for (int num : nums) {
            topK.push(num);
            if (topK.size() > k) topK.pop();
        }
        return topK.top();
    }
};
```

#### Solution 2

Quick sort

C++

```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() < k) return -1;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = partition(nums, left, right);
            if (mid == k - 1) return nums[mid];
            if (mid < k) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
    
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int idx = left - 1;
        for (int i = left; i < right; i++) {
            if (nums[i] > pivot) {
                idx++;
                swap(nums[i], nums[idx]);
            }
        }
        swap(nums[++idx], nums[right]);
        return idx;
    }
};
```

Another way of implementing the partition function

```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() < k) return -1;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = partition(nums, left, right);
            if (mid == k - 1) return nums[mid];
            if (mid < k - 1) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
    
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int i = left, j = right - 1;
        while (i <= j) {
            if (nums[i] < pivot and pivot < nums[j]) {
                swap(nums[i++], nums[j--]);
            }
            if (nums[i] >= pivot) i++;
            if (nums[j] <= pivot) j--;
        }
        swap(nums[right], nums[i]);
        return i;
    }
};
```
