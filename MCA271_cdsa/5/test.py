def lomuto_partition(arr, lo, hi):
    pivot = arr[hi]
    for j in range(lo, hi):
        if arr[j] <= pivot:
            arr[lo], arr[j] = arr[j], arr[lo]
            lo += 1
 
    arr[lo], arr[hi] = arr[hi], arr[lo]
    return lo

# [4 2 7 3 1 9 6 0 8]

# [9 6 0 1]
