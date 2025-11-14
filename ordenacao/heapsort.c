#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void maxheapify(int *A, int m, int i) {
    int e, d, aux, maior;
    e = 2 * i + 1;
    d = 2 * i + 2;
    if ((e <= m) && (A[e] > A[i]))
        maior = e;
    else
        maior = i;

    if ((d <= m) && (A[d] > A[maior]))
        maior = d;

    if (maior != i) {
        aux = A[i];
        A[i] = A[maior];
        A[maior] = aux;
        maxheapify(A, m, maior);
    }
}

void build_maxheap (int *A, int n) {
    for(int i = n/2; i >= 0; i--)
        maxheapify(A, n-1, i);
}

void heapsort2 (int *A, int n) {
    int m, aux;
    build_maxheap (A, n-1);
    m = n - 1;
    for (int i = n -1; i >= 1; i--) {
        aux = A[0];
        A[0] = A[i];
        A[i] = aux;
        m--;
        maxheapify(A, m, 0);
    }
}

int* geraVetorDecrescente (int n) {
    int *v = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        v[i] = n - i;
    }
    return v;
}

int main() {
    // pensar mais para ver a curva nlongn
    int repeticoes = 1;
    int begin = 100000;
    int end = 500000;
    int step = 2;
    int i;
    double tempo;

    for (i = begin; i <= end; i += step)
    {
        for (int j = 0; j < repeticoes; j++) {
            int *a = geraVetorDecrescente(i);
            clock_t start = clock();
            heapsort2(a, i);
            clock_t end_time = clock();
            tempo = (double)(end_time - start) / CLOCKS_PER_SEC;
            printf("%d\t%d\t%lf\n", (j+1), i, tempo);
            free(a);
        }
    }
    return 0;
}