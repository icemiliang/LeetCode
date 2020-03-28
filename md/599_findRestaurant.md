### 599\. [Minimum Index Sum of Two Lists](https://leetcode.com/problems/minimum-index-sum-of-two-lists/)

Suppose Andy and Doris want to choose a restaurant for dinner, 
and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum.
If there is a choice tie between answers, output all of them with 
no order requirement. You could assume there always exists an answer.

Example 1:
```
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]

Output: ["Shogun"]

Explanation: The only restaurant they both like is "Shogun".
```

Example 2:
```
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]

Output: ["Shogun"]

Explanation: The restaurant they both like and have the least index sum 
is "Shogun" with index sum 1 (0+1).
```

Note:
1. The length of both lists will be in the range of [1, 1000].
2. The length of strings in both lists will be in the range of [1, 30].
3. The index is starting from 0 to the list length minus 1.
4. No duplicates in both lists.


#### Solution 1

Hashmap elements in list1 to their indices. Keep a vector to store candicates,
and a counter for the least index sum. Loop list2. If the same restaurant
is found in the hashmap and the current index sum is the same as the counter,
push the new restaurant into the vector. If smaller than the counter, replace
the vector with the new retaurant.

C++

```
class Solution {
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		if (list1.size() > list2.size()) return findRestaurant(list2,list1);
		vector<string> res;
		int sum = INT_MAX;
		unordered_map<string,int> m;
		for (int i = 0; i < list1.size(); i++) m[list1[i]] = i;
		for (int i = 0; i < list2.size(); i++) {
			if (m.find(list2[i]) == m.end()) continue;
			int tmp = m[list2[i]] + i;
			if (tmp == sum) res.push_back(list2[i]);
			else if (tmp < sum) {
				sum = tmp;
				res = {list2[i]};
			}
		}
		return res;
	}
};
```
