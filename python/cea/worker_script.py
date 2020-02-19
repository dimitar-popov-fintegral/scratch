import os
import sys
import shutil 
import xlrd 
import re
from dbfread import DBF

THIS_DIR = os.path.dirname(os.path.realpath(__file__))

"""
Step 0.
  Install the following packages into your Anaconda environment
  DBF reader
  link -> https://dbfread.readthedocs.io/en/latest/installing.html
      i.e. pip install dbfread
  EXCEL reader
  link -> https://www.geeksforgeeks.org/reading-excel-file-using-python/
  i.e. pip install xlrd

  To run this script, in the command line:
  python worker_script.py

  All the inputs should be put in a directory called input

  All the outputs will be put in a directory called output

  Both input and output folders should be in the same directory as this script
"""

##################################################
def main():
    
    """
    Step 1.
      Creating copies of a file using names from an excel sheet

    """
    file_to_copy_name = "some.file"
    path_to_copy_file = os.path.join(THIS_DIR, file_to_copy_name)

    workbook_path = os.path.join(get_input_dir(), "workbook_with_file_names.xlsx")
    excel_workbook = xlrd.open_workbook(workbook_path)
    sheet_with_file_names = excel_workbook.sheet_by_index(0)
    file_names = sheet_with_file_names.row_values(0)
    print("found these file-names in excel", file_names)

    for name in file_names:
        output_directory = get_output_dir()
        path_to_destination_file = os.path.join(output_directory, name)
        shutil.copyfile(src=path_to_copy_file, dst=path_to_destination_file)
        print("successfully wrote [%s] to [%s]" \
              %(path_to_copy_file, path_to_destination_file))

    """
    Step 2.
      Editing .dbf files in two directories
      I can't test this as I don't have .dbf files :/
      The idea is just to iterate over the 'zone' files, read a row and write
      that row to the 'surroundings' file
    """
    dbf_zones_directory = os.path.join(get_input_dir(), "zone_files")
    dbf_surroundings_directory = os.path.join(get_input_dir(), "surroundings_files")
    zone_files = os.listdir(dbf_zones_directory)

    for zone in zone_files:
        zone_file_path = os.path.join(dbf_zones_directory, zone)
        surrounding_file_path = \
            os.path.join(dbf_surroundings_directory, zone.replace("zone", "surroundings"))
        assert os.path.exists(zone_file_path), \
            "missing .dbf zone file at absolute path [%s]" %check_file

        zone_table = DBF.read(zone_file_path)
        for record in zone_table:
            print(record)

        surrounding_table = DBF.read(surrounding_file_path)
        for record in surrounding_table:
            print(record)
        

##################################################
def get_output_dir() -> str:
    """return the absolute path to the output directory"""
    output_dir = os.path.join(THIS_DIR, "output")
    if not os.path.exists(output_dir):
        os.mkdir(output_dir)
    return output_dir


##################################################
def get_input_dir() -> str:
    """return the absolute path to the input directory"""
    input_dir = os.path.join(THIS_DIR, "input")
    if not os.path.exists(input_dir):
        os.mkdir(input_dir)
        raise IOError("input dir not found, created it and aborting")
    return input_dir


##################################################
if __name__ == "__main__":
    main()
