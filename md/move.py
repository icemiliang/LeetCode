import glob, os
os.chdir(".")
os.system("rm bigfile.txt")
os.system("rm bigfile.md")
files = glob.glob("*.md")
f1 = open("bigfile.txt", "w")
f2 = open("bigfile.md", "w")
files.sort()
for file in files:
    tmp = open(file)
    read = tmp.read();
    f1.write(read)
    f1.write("\n");
    f2.write(read)
    f2.write("\n");
    tmp.close()
f1.close()
f2.close()
