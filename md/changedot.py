import glob

files = glob.glob("*.md")
for file in files:
    flag = False
    with open(file) as f:
        data = f.read()
        if data[:3] == "###":
            flag = True

    if flag:
        i = data.find('.')
        data = data[:i] + '\\' + data[i:]

        with open(file, 'w') as f:
            f.write(data)
