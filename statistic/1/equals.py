from scipy import stats

def equal_oneway(arr):
    return stats.f_oneway(*arr)
