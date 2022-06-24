import os

# should be parsed from input
cc_dir = 'C:\\msys64\\mingw64\\bin\\clang'

in_dir = os.getcwd()

out_dir = os.path.join(in_dir, 'scan-build-output')
out_log = os.path.join(in_dir, 'scan-build-log.txt')

make = 'make -C ./Debug clean all -j8'
command = 'scan-build' \
          ' -o {}' \
          ' --use-cc={}' \
          ' {}' \
          ' >{}'.format(out_dir, cc_dir, make, out_log)

if os.name != 'nt':
    command.replace('\\\\', '/')


def main():
    os.system("python makefile-update.py")
    os.system(command)

    dst = os.path.join(out_dir, "scan-build-log.txt")
    os.system("move {} {} >NUL".format(out_log, dst))

    return

    
if __name__ == "__main__":
    main()