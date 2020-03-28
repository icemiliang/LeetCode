### 398\. [Random Pick Index](https://leetcode.com/problems/random-pick-index/)

Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.

Note:
The array size can be very large. Solution that uses too much extra space will not pass the judge.

Example:
```
int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(3);

// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);
```

#### Solution 1

Another reservior sampling problem. 
Loop the array, whenever a target value is found,
record the current index with a probabiliy of 1/count
where count counts how many times we have seen the target.

C++

```
class Solution {
public:
	Solution(vector<int> nums) {
		v = nums;
	}

	int pick(int target) {
		int cnt = 0, res = -1;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] != target) continue;
			cnt++;
			if (rand() % (cnt) == 0) res = i;
		}
		return res;
	}

protected:
	vector<int> v;
};
```

#### Solution 2

C++

```
class Solution {
    unordered_map<int, vector<int>> m;
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int size = m[target].size();
        int index = rand() % size;
        return m[target][index];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
```
