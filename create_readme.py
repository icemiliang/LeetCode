import glob
w = open("README.md", "w")
files = glob.glob("md/*.md")
nums = [file.split('_')[0] for file in files]
nums = [num.split('/')[1] for num in nums]
nums = list(map(int, nums))
indices = sorted(range(len(nums)), key=lambda k: nums[k])
files = [files[i] for i in indices]
w.write("This is my own collection of Leetcode solutions. Some of them are inspired by [Grand Yang's blog](https://www.cnblogs.com/grandyang/p/4606334.html). The codes are mostly in C++. Some have Python versions.\n\n")
w.write('[Questions in groups](group.md)\n\n')
for file in files:
    with open(file) as f:
        title = f.readline()
        w.write(title[4:] + " [[Solution](" + file + ")]  \n")
w.close()
