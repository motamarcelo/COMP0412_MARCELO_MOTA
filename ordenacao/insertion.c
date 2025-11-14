#include <stdio.h>

int vetor[] = {
    17, 3, 42, 9, 28, 55, 1, 34, 23, 11,
    68, 5, 90, 14, 76, 39, 8, 61, 47, 19,
    28, 39, 5, 100, 0
};

void insertion_sort(int *A, int n) {
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main(void) {
    int n = sizeof(vetor) / sizeof(vetor[0]);
    insertion_sort(vetor, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return 0;
}
