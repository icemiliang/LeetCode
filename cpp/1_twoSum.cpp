#include <iostream>
#include <vector>
#include <unordered_map>

#include "utils.h"

using namespace std;

vector<int> twoSum1(vector<int>& nums, int target) {
	unordered_map<int, int> indices;
	for (int i = 0; i < nums.size(); ++i) {
		int diff = target - nums[i];
		if (indices.count(diff) and indices[diff] != i) {
			return {indices[diff], i};
		}
		indices[nums[i]] = i;
	}
	return {};
}

vector<int> twoSum2(vector<int>& nums, int target) {
	unordered_map<int, int> indices;
	for (int i = 0; i < nums.size(); ++i) {
		indices[nums[i]] = i;
	}

	for (int i = 0; i < nums.size(); ++i) {
		int diff = target - nums[i];
		if (indices.count(diff) and indices[diff] != i) {
			return {indices[diff], i};
		}
	}
	return {};
}


vector<int> twoSum3(vector<int>& nums, int target) {
	for (int i = 0; i < nums.size() - 1; ++i) {
		for (int j = i + 1; j < nums.size(); ++j) {
			if (nums[i] + nums[j] == target) {
				return {i, j};
			}
		}
	}
	return {};
}

int main() {
	vector<int> nums = {2, 7, 11, 15};
	int target = 9;
	vector<int> res1 = twoSum1(nums, target);
	vector<int> res2 = twoSum2(nums, target);
	vector<int> res3 = twoSum3(nums, target);

	cout << "Array: "; printVector(nums);
	cout << "Target: " << target << endl;
	cout << "Result 1: "; printVector(res1);
	cout << "Result 2: "; printVector(res2);
	cout << "Result 3: "; printVector(res3);

	return 0;
}
