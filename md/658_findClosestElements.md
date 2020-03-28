### 658\. [Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/)

Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
```
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
```

Example 2:
```
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
```

Note:

1. The value k is positive and will always be smaller than the length of the sorted array.
2. Length of the given array is positive and will not exceed 104
3. Absolute value of elements in the array and x will not exceed 104

UPDATE (2017/9/19):
The arr parameter had been changed to an array of integers (instead of a list of integers). Please reload the code definition to get the latest changes. 


#### Solution 1

Two pointers

Remove either the front or tail of the array according to their distances to x,
until there are k elments left. 

Two pointers -- left and right. If left distance is bigger, left++; otherwise right--.

C++

```
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - 1;
        while (right - left >= k) {
            if (x - arr[left] > arr[right] - x) left++;
            else right--;
        }
        vector<int> res;
        res.insert(res.begin(), arr.begin() + left, arr.begin() + right + 1);
        return res;
    }
};
```

#### Solution 2

Binary search. Find the starting point of the subarray of size k.
The starting point 

C++

```
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] > arr[mid + k] - x) left = mid + 1;
            else right = mid;
        }
        return vector<int> (arr.begin() + left, arr.begin() + left + k);
    }
};
```