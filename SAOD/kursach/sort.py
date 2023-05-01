
def merge_sort(alist, start, end):
    if end - start > 1:
        mid = (start + end)//2
        merge_sort(alist, start, mid)
        merge_sort(alist, mid, end)
        merge_list(alist, start, mid, end)

def merge_list(alist, start, mid, end):
    left = alist[start:mid]
    right = alist[mid:end]
    k = start
    i = 0
    j = 0
    while (start + i < mid and mid + j < end):
        if (left[i].pasport <= right[j].pasport):
            alist[k].pasport = left[i].pasport
            i = i + 1
        else:
            alist[k].pasport = right[j].pasport
            j = j + 1
        k = k + 1
    if start + i < mid:
        while k < end:
            alist[k].pasport = left[i].pasport
            i = i + 1
            k = k + 1
    else:
        while k < end:
            alist[k].pasport = right[j].pasport
            j = j + 1
            k = k + 1
