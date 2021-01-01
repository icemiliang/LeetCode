#!/usr/bin/python3

def twoSum1(nums: list, target: int) -> list:
	dict = {}
	for i, num in enumerate(nums):
		dict[num] = i
	for i, num in enumerate(nums):
		diff = target - num
		if diff in dict:
			return [dict[diff], i]
	return []

def twoSum2(nums: list, target: int) -> list:
    dict = {}
    for i, num in enumerate(nums):
        diff = target - num
        if diff in dict:
            return [dict[diff], i]
        dict[num] = i
    return []

def twoSum3(nums: list, target: int) -> list:
	for i, numI in enumerate(nums):
		for j, numJ in enumerate(nums):
			if numI + numJ == target:
				return [i, j]
	return []

def main():
	nums = [2, 7, 11, 15]
	target = 9
	res1 = twoSum1(nums, target)
	res2 = twoSum2(nums, target)
	res3 = twoSum3(nums, target)
	print("Array: {}".format(nums))
	print("Target: {}".format(target))
	print("Result 1: {}".format(res1))
	print("Result 2: {}".format(res2))
	print("Result 3: {}".format(res3))

if __name__ == "__main__":
    # execute only if run as a script
    main()
