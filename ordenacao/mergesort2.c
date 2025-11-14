#include <stdio.h>
#include <stdlib.h>

int vetor_teste[] = {
    17, 3, 42, 9, 28, 55, 1, 34, 23, 11,
    68, 5, 90, 14, 76, 39, 8, 61, 47, 19,
    28, 39, 5, 100, 0
};

static void merge(int *arr, int start, int middle, int end) {
    int left_size = middle - start + 1;
    int right_size = end - middle;

    int *L = malloc(left_size * sizeof(int));
    int *R = malloc(right_size * sizeof(int));

    for (int i = 0; i < left_size; i++) {
        L[i] = arr[start + i];
    }
    for (int j = 0; j < right_size; j++) {
        R[j] = arr[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = start;

    while (i < left_size && j < right_size) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < left_size) {
        arr[k++] = L[i++];
    }
    while (j < right_size) {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void mergesort2(int *arr, int start, int end) {
    if (start >= end) {
        return;
    }
    int middle = (start + end) / 2;
    mergesort2(arr, start, middle);
    mergesort2(arr, middle + 1, end);
    merge(arr, start, middle, end);
}

int main(void) {
    int n = sizeof(vetor_teste) / sizeof(vetor_teste[0]);

    mergesort2(vetor_teste, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", vetor_teste[i]);
    }
    printf("\n");
    return 0;
}
