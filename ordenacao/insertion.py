vetor_teste = [17, 3, 42, 9, 28, 55, 1, 34, 23, 11, 68, 5, 90, 14, 76, 39, 8, 61, 47, 19, 28, 39, 5, 100, 0]

def insertion_sort(arr,n):
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return 

insertion_sort(vetor_teste, len(vetor_teste))
print(vetor_teste)

