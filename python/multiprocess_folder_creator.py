import os
import sys
import time
from multiprocess import Pool

THIS_DIR = os.path.dirname(os.path.realpath(__file__))

##################################################
def return_folder_name(_):
    folder = os.path.join(THIS_DIR, "test_folder")
    if not os.path.exists(folder):
        try:
            print "making a folder"
            os.mkdir(folder)
        except OSError as e:
            print "failed to make a folder"
            time.sleep(0.5)
            if not os.path.exists(folder):
                raise e
    return folder


##################################################
def main():
    folder = "test_folder"
    if os.path.exists(folder):
        os.rmdir(folder)
    p = Pool(4)
    p.map(return_folder_name, [None for i in range(4)])
    p.close()


##################################################
if __name__ == "__main__":
    for i in range(100):
        print "main is at iter [%d]" %i
        main()

