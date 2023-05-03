import numpy as np
import copy
from random import randint

import matplotlib.pyplot as plt
import numpy as np

MAX_CLUSTER_VALUE = 20

def data_distribution(data, cluster, k):
    cluster_content = [[] for i in range(k)]
    n = len(data)
    dim = len(data[0])

    for i in range(n):
        min_distance = float('inf')
        situable_cluster = -1
        for j in range(k):
            distance = 0
            for q in range(dim):
                distance += (data[i][q] - cluster[j][q]) ** 2

            distance = distance**(1/2)

            if distance < min_distance:
                min_distance = distance
                situable_cluster = j

        cluster_content[situable_cluster].append(data[i])
        # print(cluster_content)

    return cluster_content

def cluster_update(cluster, cluster_content, dim):
    k = len(cluster)
    for i in range(k): #по i кластерам
        for q in range(dim): #по q параметрам
            updated_parameter = 0
            for j in range(len(cluster_content[i])):
                updated_parameter += cluster_content[i][j][q]
            if len(cluster_content[i]) != 0:
                updated_parameter = updated_parameter / len(cluster_content[i])
            cluster[i][q] = updated_parameter
    return cluster

def clusterization(data, k=3):
    n = len(data)
    dim = len(data[0])

    cluster = [[0 for i in range(dim)] for q in range(k)]
    cluster_content = [[] for i in range(k)]

    # cluster = [[randint(0, MAX_CLUSTER_VALUE) for _ in range(k)] for _ in range(dim)]

    for i in range(dim):
        for q in range(k):
            cluster[q][i] = randint(0, MAX_CLUSTER_VALUE)

    cluster_content = data_distribution(data, cluster, k)
    # print(cluster_content)

    privious_cluster = copy.deepcopy(cluster)
    while 1:
        cluster = cluster_update(cluster, cluster_content, dim)
        cluster_content = data_distribution(data, cluster, k)
        if cluster == privious_cluster:
            break
        privious_cluster = copy.deepcopy(cluster)

    return cluster_content

def draw_cluster(cluster_content):
    for i in range(len(cluster_content)):
        print("cluster #%d: " % i, cluster_content[i])

    k = len(cluster_content)
    plt.grid()
    plt.xlabel("x")
    plt.ylabel("y")

    for i in range(k):
        x_coordinates = []
        y_coordinates = []
        for q in range(len(cluster_content[i])):
            x_coordinates.append(cluster_content[i][q][0])
            y_coordinates.append(cluster_content[i][q][1])
        plt.scatter(x_coordinates, y_coordinates)
    plt.show()
