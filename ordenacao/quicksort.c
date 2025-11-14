#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int vetor_teste[] = {
    17, 3, 42, 9, 28, 55, 1, 34, 23, 11,
    68, 5, 90, 14, 76, 39, 8, 61, 47, 19,
    28, 39, 5, 100, 0
};

// Inicializa o gerador de números aleatórios (chamado uma vez)
static int random_initialized = 0;

static void init_random(void) {
    if (!random_initialized) {
        srand(time(NULL));
        random_initialized = 1;
    }
}

static int partition(int *A, int p, int r) {
    // MELHORIA: Escolhe pivô aleatório para evitar O(n²) em dados ordenados
    init_random();
    int pivot_idx = p + rand() % (r - p + 1);

    // Troca pivô escolhido com o último elemento
    int tmp = A[pivot_idx];
    A[pivot_idx] = A[r];
    A[r] = tmp;

    int pivot = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j] <= pivot) {
            i++;
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    tmp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = tmp;
    return i + 1;
}

void quicksort(int *A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}

int main(void) {
    int n = sizeof(vetor_teste) / sizeof(vetor_teste[0]);
    quicksort(vetor_teste, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", vetor_teste[i]);
    }
    printf("\n");
    return 0;
}
