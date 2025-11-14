vetor_teste = [17, 3, 42, 9, 28, 55, 1, 34, 23, 11, 68, 5, 90, 14, 76, 39, 8, 61, 47, 19, 28, 39, 5, 100, 0]

def merge(arr, start, middle, end):
    L = arr[start:middle + 1]
    R = arr[middle+1:end + 1]
    i = 0
    j = 0
    k = start
    while i < len(L) and j < len(R):
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1
    while i < len(L):
        arr[k] = L[i]    
        i += 1
        k += 1
    while j < len(R):
        arr[k] = R[j]
        j += 1
        k += 1


def mergesort(arr, start, end):
    if start >= end:
        return
    middle = (start + end) // 2
    mergesort(arr, start, middle)
    mergesort(arr, middle + 1, end)
    merge(arr, start, middle, end)
    return arr

print(mergesort(vetor_teste, 0, len(vetor_teste)))