#include <iostream>
#include <vector>
#include <unordered_map>

#include "utils.h"

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() < 2) return nums.size();
    int last = 0;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[last]) {
            nums[++last] = nums[i];
        }
    }
    return last + 1;
}

int main() {
	vector<int> nums1 = {1, 1, 2};
	vector<int> nums2 = {0,0,1,1,1,2,2,3,3,4};
	int out1 = 2, out2 = 5;
	int res1 = removeDuplicates(nums1);
	int res2 = removeDuplicates(nums2);

	cout << "Array: "; printVector(nums1);
	cout << "Target: " << out1 << ", Result: " << res1 << endl;
	cout << "Array: "; printVector(nums2);
	cout << "Target: " << out2 << ", Result: " << res2 << endl;

	return 0;
}
