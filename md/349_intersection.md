### 349\. [Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/)

Given two arrays, write a function to compute their intersection.

Example 1:
```
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
```

Example 2:
```
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
```

Note:

Each element in the result must be unique.
The result can be in any order.


#### Solution 1

This problem in general has three solutions. Each solution has some variants.
The first solution is to use sets. We build a set for each array. Then, for 
each element of a set, check if it is also in the other set.

C++

```
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        vector<int> res;
        for (int num : s1) {
            if (s2.count(num)) res.push_back(num);
        }
        return res;
    }
};
```

Python

```
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        s1 = set(nums1)
        s2 = set(nums2)
        res = []
        for num in s1:
            if num in s2:
                res.append(num)
        return res
```

We can actually use one set to reduce the memory use. Build a set from one array
and check if each element in the nums2 is in the set. Use a set to temproraly 
store the result then convert it to a vector before returning it. In this way,
even if array 2 has duplicates, the result will only has one of them.

C++

```
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> res;
        for (int num : nums2) {
            if (s1.count(num)) res.insert(num);
        }
        return vector<int> (res.begin(), res.end());
    }
};
```

Python

```
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        s1 = set(nums1)
        res = set()
        for num in nums2:
            if num in s1:
                res.add(num)
        return res
```

Both C++ and Python have built-in functions to compute the intersection of two sets.
Note, there is a difference between C++ and Python. In C++ intersection can only be
used on ordered sets. In Python, there is no ordered set and intersection can be used
on unordered sets.

C++

```
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        vector<int> res(min(s1.size(), s2.size()));
        auto it = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), res.begin());
        res.resize(it-res.begin());
        return res;
    }
};
```

We can also use a set to store the intersection and later convert it to vector.
In this way, we don't need to define the vector with the size and then resize it.

```
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        unordered_set<int> res;
        auto it = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.begin()));
        return vector<int> (res.begin(), res.end());
    }
};
```

Python

```
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        s1 = set(nums1)
        s2 = set(nums2)
        res = s1.intersection(s2)
        return list(res)
```


#### Solution 2

We can first sort the arrays. Then, keep two pointers at the heads of the arrays. 
If two current numbers do not equal, increase the index of the smaller one.
If the back of the return array does not equal the current number,
then put it into the return array and increase both pointers.

C++

```
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int i = 0, j = 0;
        while (i < nums1.size() and j < nums2.size()) {
            if (nums1[i] < nums2[j]) i++;
            else if (nums1[i] > nums2[j]) j++;
            else {
                if (res.empty() or res.back() != nums1[i]) {
                    res.push_back(nums1[i]);
                }
                i++; j++;
            }
        }
        return res;
    }
};
```

Python 

```
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        res = []
        i, j = 0, 0
        while (i < len(nums1) and j < len(nums2)):
            if nums1[i] < nums2[j]:
                i += 1
            elif nums1[i] > nums2[j]:
                j += 1
            else:
                if len(res) == 0 or res[-1] != nums1[i]:
                    res.append(nums1[i])
                i += 1
                j += 1
        return res
```

#### Solution 3 

Another solution uses the binary search technique. The essential idea is
to sort one array and search for each element of the other array in this
sorted array. Binary search is a popular trick to search in sorted arrays.

C++

```
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        unordered_set<int> res;
        for (int num : nums2) {
            if (binarySearch(nums1, num)) {
                res.insert(num);
            }
        }
        return vector<int>(res.begin(), res.end());
    }

    bool binarySearch(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};
```

Python

```
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        def binarySearch(nums: List[int], target: int) -> bool:
            left = 0
            right = len(nums) - 1
            while (left <= right):
                mid = left + (right - left) // 2
                if nums[mid] == target:
                    return True
                if nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1;
            return False
        
        nums1.sort()
        res = set()
        for num in nums2:
            if binarySearch(nums1, num):
                res.add(num)
        return list(res)
```
