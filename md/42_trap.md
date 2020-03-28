### 42\. [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:
```
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
```

#### Solution 1

We keep twp pointers -- left and right -- and move the shorter one toward the other. Keep the 
old bar of the moving pointer. As we move the pointer, if the next bar is lower, add the 
difference to result and continue moving the same pointer. The logic is that because we are
moving the shorter pointer, it is safe to add all the difference because the higher bar makes 
sure the water is trapped in those low land.

C++

```
class Solution {
public:
    int trap(vector<int>& height) {
        int lo = 0;
        int hi = height.size() - 1;
        int res = 0;
        while (lo < hi) {
            int mn = min(height[lo], height[hi]);
            if (mn == height[lo]) {
                ++lo;
                while (lo < hi and height[lo] < mn) res += mn - height[lo++];
            }
            else {
                --hi;
                while (lo < hi and height[hi] < mn) res += mn - height[hi--];
            }
        }
        return res;
    }
};
```

Python

```
class Solution:
    def trap(self, height: List[int]) -> int:
        res = 0
        left = 0
        right = len(height) - 1
        while left < right:
            mn = min(height[left], height[right])
            if mn == height[left]:
                left += 1
                while left < right and height[left] <= mn:
                    res += mn - height[left]
                    left += 1
            else:
                right -= 1
                while left < right and height[right] <= mn:
                    res += mn - height[right]
                    right -= 1
                    
        return res
```

Below is a more concise way to implementing the idea.

C++

```
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1, level = 0, res = 0;
        while (left < right) {
            int lower = height[(height[left] < height[right]) ? left++ : right--];
            level = max(level, lower);
            res += level - lower;
        }
        return res;
    }
};
```

Python

```
class Solution:
    def trap(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        level = 0
        res = 0
        while left < right:
            if height[left] < height[right]:
                lower = height[left]
                left += 1
            else:
                lower = height[right]
                right -= 1
            level = max(level, lower)
            res += level - lower
        return res
```
