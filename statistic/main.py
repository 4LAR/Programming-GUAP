import os

from scipy import stats

from graph import *
from visualize import *
from visualize_new import *
from equals import *

class Table:
    def __init__(self, file_name, delimiter=","):
        self.file_name = file_name
        self.delimiter = delimiter

        self.table = []

        self.size = [0, 0]

        self.read_file()

    def read_file(self, file_name=None):
        self.table = []
        with open(file_name if (file_name) else self.file_name, "r") as f:
            for line in f.read().split("\n"):
                els_list = []
                for el in line.split(self.delimiter):
                    if len(el) > 0:
                        els_list.append(float(el))
                    else:
                        break

                else:
                    self.table.append(els_list)

    def get_table(self):
        return self.table

    def get_column(self, index):
        return [row[index] for row in self.table]

    def get_rotated(self):
        return [self.get_column(i) for i in range(len(self.table[0]))]

    def print(self):
        for row in self.table:
            for el in row:
                print(el, end="\t")
            print()

################################################################################
#
# table1 = Table("example.csv")
# table2 = Table("global.csv")
#
# for i in range(5):
#     a, b = stats.ttest_ind(table1.get_column(i), table2.get_column(i))
#     print("T:", a) # t
#     print("P:", b) # p
#     print("-"*20)

################################################################################

# table1 = Table("example.csv")
# draw_graph(table1.get_column(0), table1.get_column(2))

################################################################################

# table2 = Table("global.csv")
# cluster_content = clusterization(
#     table2.get_table()
# )
#
# draw_cluster(cluster_content)

################################################################################
# tables_obj = []
# tables = []
# for file_name in ["4131", "4132", "4133", "4134", "4136"]:
#     print("Reading:", file_name)
#     tables_obj.append(Table("groups/%s.csv" % file_name, ";"))
#
# results = []
# for i in range(5):
#     tables.append([el.get_column(i) for el in tables_obj])
#     results.append(equal_oneway(tables[-1]))
#
# print("1\t2\t3\t4\t5")
# for res in results:
#     print("%0.5lf" % res.pvalue, end="\t")
# print()
# for res in results:
#     print("%0.5lf" % res.statistic, end="\t")
# print()

################################################################################
#
# table2 = Table("global.csv")
#
# cluster_content = clusterization(
#     table2.get_table()
# )
#
# for el in cluster_content:
#     print("-" * 80)
#     to_2d_cluster(cluster_content[0])

################################################################################

table = Table("example.csv")
structure_data = Structure_data(
    table = table.get_rotated()
)

structure_data.draw()

################################################################################
