vetor_teste = [17, 3, 42, 9, 28, 55, 1, 34, 23, 11, 68, 5, 90, 14, 76, 39, 8, 61, 47, 19, 28, 39, 5, 100, 0]

def partition(A, p, r):
    x = A[r]
    i = p - 1
    for j in range(p, r):
        if A[j] <= x:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i + 1], A[r] = A[r], A[i + 1]
    return i + 1

def quicksort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        quicksort(A, p, q - 1)
        quicksort(A, q + 1, r)
    return A
vetor_teste = [17, 3, 42, 9, 28, 55, 1, 34, 23, 11, 68, 5, 90, 14, 76, 39, 8, 61, 47, 19, 28, 39, 5, 100, 0]
print(quicksort(vetor_teste, 0, len(vetor_teste) - 1))