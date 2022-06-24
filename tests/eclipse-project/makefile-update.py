import os, re

MATCH_COMPILER = "(?P<compiler>gcc|clang|\w+-\w+-\w+-gcc)"
# scan-build -o "scan-build-output" --use-cc=C:\msys64\mingw64\bin\clang make all -j8

def set_cc_variable(files):
    for n, file in enumerate(files):
        contents = ""

        with open(file, "r") as f:
            contents = f.read().splitlines()
            
        compiler, start = "", 0

        # find and capture file compiler and change it's usage to $(CC)
        for i, l in enumerate(contents):
            match = re.search(MATCH_COMPILER, l)
            if match is not None and l.startswith("CC=") == False:
                if start == 0:
                    start = i

                if compiler == "":
                    compiler = match.group("compiler")
                
                l = l.replace(compiler, "$(CC)")
                l = l.replace(' -fstack-usage', '')

                contents[i] = l
                match = None


        if compiler == "":
            continue

        # find earlier commented line to set CC variable to original file compiler
        while start != 1:
            if contents[start].startswith("#") == True:
                contents[start] = "CC={}\n".format(compiler)
                break

            start -= 1

        s = "\n".join(l for l in contents)
        
        with open(file, "w") as f:
            f.write(s)

    return


def find_makefiles(path):
    # linking happens in makefile file: don't use it

    mf = []
    for root, dirs, files in os.walk(path):
        for dir in dirs:
            p = os.path.join(root, dir)
            for file in os.listdir(p):
                f = os.path.join(p, file)
                if file.endswith(".mk") == True:
                    mf.append(f)

    return mf


if __name__ == "__main__":
    makefiles = find_makefiles(os.getcwd())
    set_cc_variable(makefiles)