//Created by 23343068_Hanna Fadilah
#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk menghitung bilangan Fibonacci
int* fibonacci(int n) {
    int* fibSeries = (int*)malloc(n * sizeof(int));

    if (fibSeries == NULL) {
        fprintf(stderr, "Gagal mengalokasi memori\n");
        exit(1);
    }

    fibSeries[0] = 0;
    fibSeries[1] = 1;

    for (int i = 2; i < n; i++) {
        fibSeries[i] = fibSeries[i - 1] + fibSeries[i - 2];
    }

    return fibSeries;
}

int main() {
    int n;

    // Meminta input dari user
    printf("Masukkan nilai n untuk deret Fibonacci: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Masukkan n yang valid (n > 0)\n");
        return 1;
    }

    // Mendapatkan deret Fibonacci
    int* fibSeries = fibonacci(n);

    // Menampilkan hasil
    printf("Deret Fibonacci pertama %d angka:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibSeries[i]);
    }
    printf("\n");

    // Membebaskan memori yang dialokasikan
    free(fibSeries);

    return 0;
}
