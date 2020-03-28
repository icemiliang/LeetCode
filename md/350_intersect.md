### 350\. [Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/)

Given two arrays, write a function to compute their intersection.

Example 1:
```
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
```

Example 2:
```
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
```

Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.


Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

#### Solution 1

Different from 349, this time we have to output all the intersections,
including duplicates. Thus, we need two hashmaps to cnt the frequencies
of every number in thse two arrays. Then, we loop over one hashmap and
find if the current number also occurs in the other hashmap. Push back
the smaller number of instances of the number to an array and return it.

C++

```
class Solution {
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m1, m2;
        for (int num : nums1) m1[num]++;
        for (int num : nums2) m2[num]++;
        vector<int> res;
        for (auto it : m1) {
            if (m2.find(it.first) != m2.end()) {
                int n = min(m2[it.first], it.second);
                for (int i = 0; i < n; i++) {
                    res.push_back(it.first);
                }
            }
        }
        return res;
    }
};

```

Python

```
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        m1 = {}
        m2 = {}
        for num in nums1:
            if num in m1:
                m1[num] += 1
            else:
                m1[num] = 1
        for num in nums2:
            if num in m2:
                m2[num] += 1
            else:
                m2[num] = 1
        res = []
        for it in m1:
            if it in m2:
                n = min(m2[it], m1[it])
                for i in range(n):
                    res.append(it)
        return res
```


We can use one hashmap to store the frequency of array 1 and loop
array 2. Each time we run into an element that is in the hashmap,
put it in the result and reduce the frequency but 1 until it reaches
zero and the elment will be ignored forever.

C++

```
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1;
        for (int num : nums1) m1[num]++;
        vector<int> res;
        for (int num : nums2) {
            if (m1[num]-- > 0) res.push_back(num);
        }
        return res;
    }
};
```

Python

```
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        m = {}
        for num in nums1:
            if num in m:
                m[num] += 1
            else:
                m[num] = 1
        res = []
        for num in nums2:
            if m[num] > 0:
                res.append(num)
                m[num] -= 1
        return res
```

#### Solution 3

Like 349, we can sort the two arrays and use two pointers each traversing one
array. If the two current numbers equal, put the number into the result.
There is no need to check if the result already has the number or not because
we are asked to return as many as we see in both arrays.

C++

```
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        vector<int> res;
        while (i < nums1.size() and j < nums2.size()) {
            if (nums1[i] < nums2[j]) i++;
            else if (nums1[i] > nums2[j]) j++;
            else {
                res.push_back(nums1[i]);
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
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        res = []
        i, j = 0, 0
        while i < len(nums1) and j < len(nums2):
            if nums1[i] < nums2[j]:
                i += 1
            elif nums1[i] > nums2[i]:
                j += 1
            else:
                res.append(nums1[i])
        return res
```

#### Solution 4

Binary search

C++

```

```

Python 

```
class Solution:
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        # Corner cases
        if nums1 is None or nums2 is None:
            return
        
        # Determine which one is shorter and sort the shorter array
        if len(nums1) <= len(nums2):
            short, long = nums1, nums2
        else:
            short, long = nums2, nums1       
        short.sort()
        
        # A visited tag for elements already paired in the shorter array
        visited = [False for _ in short]
        rlt = []
        for num in long:
            if self._binarySearch(short, num, visited):
                rlt.append(num)
        return rlt
    
    def _binarySearch(self, arr, target, visited):
        """
        Find the first element that is equal to target but not visited before
        
        Note this is achievable as the visited flags are always set from left
        to right for equal elements
        """
        if arr is None or len(arr) == 0:
            return False
        
        start, end = 0, len(arr) - 1
        while start + 1 < end:
            mid = start + (end - start) // 2
            if arr[mid] == target:
                if not visited[mid]:
                    end = mid
                else:
                    start = mid
            elif arr[mid] < target:
                start = mid
            else:
                end = mid
                
        if arr[start] == target and not visited[start]:
            visited[start] = True
            return True
        if arr[end] == target and not visited[end]:
            visited[end] = True
            return True
        
        return False
```
