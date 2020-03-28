### 169\. [Majority Element](https://leetcode.com/problems/majority-element)

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
```
Example 1:

Input: [3,2,3]
Output: 3
```
```
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
```

#### Solution 1

Moore voting.

Assume the first element is the result and set a counter to 1.
If the next element is equal to the current result, counter++,
or otherwise counter--. When the counter returns to 0, it means
the current result is not the majority element of the subarray 
we have examined. Use the next element as the result and set 
the counter back to 1.

```
int majorityElement(vector<int>& nums) {
    int res = 0, cnt = 0;
    for (int num : nums) {
        if (cnt == 0) { res = num; cnt++; }
        else (num == res) ? cnt++ : cnt--;
    }
    return res;
}
```
#### Solution 2

A simple solution is to record the frequency of each seen number.
If the frequency of some number is larger than n/2, return that number.
One catch is that the array size needs to be converted to double before
divided by 2 because the frequency has to be larger than n/2. 

```
int majorityElement(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
        if (freq[num] > double(nums.size()) / 2) return num;
    }
    return -1;
}
```
