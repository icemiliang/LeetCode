import os, glob
r = open("group.csv")
w = open("group.md", "w")

os.chdir("./md")
files = glob.glob("*.md")
groups = r.read();
groups = groups.splitlines()
w.write("Some Leetcode questions in groups. Groups may have overlaps.\n")
for group in groups:
    group = group.split(",")
    header = group[0]
    w.write("\n\n### " + header + "\n")
    for prefix in group[1:]:
        print(prefix + " ", end = '')
        filename = [file for file in files if prefix + "_" == file[0:len(prefix)+1]]
        if len(filename) != 0:
            filename = filename[0]
            with open(filename) as f:
                title = f.readline()
                w.write(title[4:] + " [[Solution](" + filename + ")]  \n")
print('\n')
w.close()
r.close()