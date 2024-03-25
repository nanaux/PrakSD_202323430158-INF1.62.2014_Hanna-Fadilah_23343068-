//Created by 23342068_Hanna Fadilah
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Fungsi untuk mengecek apakah suatu bilangan adalah bilangan prima
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Fungsi untuk menghasilkan bilangan prima pertama sampai ke-n
int* generatePrimes(int n, int* size) {
    int* primes = (int*)malloc(n * sizeof(int));
    if (primes == NULL) {
        fprintf(stderr, "Gagal mengalokasi memori\n");
        exit(1);
    }

    int count = 0;
    for (int i = 2; count < n; i++) {
        if (isPrime(i)) {
            primes[count++] = i;
        }
    }

    *size = count;
    return primes;
}

int main() {
    int n, m;

    // Meminta input dari user untuk n dan m
    printf("Masukkan nilai n untuk bilangan prima: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Masukkan n yang valid (n > 0)\n");
        return 1;
    }

    printf("Masukkan nilai m untuk realokasi memori: ");
    scanf("%d", &m);

    if (m <= n) {
        printf("Masukkan m yang valid (m > n)\n");
        return 1;
    }

    // Menghasilkan bilangan prima pertama sampai ke-n
    int size;
    int* primes = generatePrimes(n, &size);

    // Menampilkan hasil
    printf("Bilangan Prima pertama %d angka:\n", n);
    for (int i = 0; i < size; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    // Menggunakan realloc untuk mengubah ukuran memori menjadi m
    primes = (int*)realloc(primes, m * sizeof(int));
    if (primes == NULL) {
        fprintf(stderr, "Gagal mengalokasi memori baru\n");
        exit(1);
    }

    // Menampilkan hasil setelah realokasi
    printf("Bilangan Prima setelah realokasi menjadi %d angka:\n", m);
    for (int i = size; i < m; i++) {
        primes[i] = isPrime(i) ? i : 0;
        printf("%d ", primes[i]);
    }
    printf("\n");

    // Membebaskan memori yang dialokasikan
    free(primes);

    return 0;
}
