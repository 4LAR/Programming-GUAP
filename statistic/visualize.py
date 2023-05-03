import numpy as np
import copy
from random import randint

import matplotlib.pyplot as plt
import numpy as np

MAX_CLUSTER_VALUE = 20

def print_arr(arr):
    for el in arr:
        print("%lf" % el, end="\t")
    print()

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

    for i in range(dim):
        for q in range(k):
            cluster[q][i] = randint(0, MAX_CLUSTER_VALUE)

    cluster_content = data_distribution(data, cluster, k)

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

def to_2d_cluster(cluster_content):
    column_count = len(cluster_content[0])
    # column_count = 2
    cluser_reverse = [[] for _ in range(column_count)]
    for el in cluster_content:
        for i in range(column_count):
            cluser_reverse[i].append(el[i])

    X = np.stack(cluser_reverse)
    X_centered = [(X[i] - X[i].mean()) for i in range(column_count)]
    m = [(X[i].mean()) for i in range(column_count)]
    covmat = np.cov(X_centered)

    _, vecs = np.linalg.eig(covmat)
    v = -vecs[:,1]
    Xnew = np.dot(v, X_centered)
    for n in range(len(Xnew)):
        Xrestored = np.dot(Xnew[n],v) + m
        print()
        print_arr(X[:,n])
        print_arr(Xrestored)
