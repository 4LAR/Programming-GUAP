import sys
from sys import platform
import os

def clear_screen():
    if platform == "linux" or platform == "linux2":
        os.system("clear")
    elif platform == "darwin":
        os.system("clear")
    elif platform == "win32":
        os.system("cls")

def check_format(str, template):
    if len(str) != len(template):
        return False

    for i in range(len(str)):
        if template[i] == "N" and not str[i].isdigit():
            return False
        if template[i] == "A" and not (str[i] in ["Л", "П", "О", "М"]):
            return False
        if template[i] == "-" and not (str[i] == "-"):
            return False

    return True

def read_bool(promt=""):
    while True:
        read = input(promt + " (y/n): ")
        if read in ["y", "Y", "n", "N", "д", "Д", "н", "Н"]:
            return (read in ["y", "Y", "д", "Д"])

class Menu:
    def __init__(self, elements, function=None):
        self.elements = elements
        self.function = function

    def run(self):
        clear_screen()
        while True:
            print("-" * 30)
            for i in range(len(self.elements)):
                print("%d) %s" % (i, self.elements[i][0]))

            try:
                menu_input = int(input("\n >> "))
                clear_screen()
                self.elements[menu_input][1]()
                if self.function != None:
                    self.function()

            except Exception as e:
                print("#" * 30)
                print("WARNING")
                exc_type, exc_obj, exc_tb = sys.exc_info()
                fname = os.path.split(exc_tb.tb_frame.f_code.co_filename)[1]
                print(exc_type, fname, exc_tb.tb_lineno)
                print(e)
                print("#" * 30)
