//created by 23343068_Hanna Fadilah
#include <stdio.h>

// Fungsi untuk mengurutkan array menggunakan Shell Sort
void shellSort(int arr[], int n) {
    // Mulai dengan jarak terbesar
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Lakukan insertion sort untuk setiap gap
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            // Pindahkan elemen-elemen dari sub-array yang belum diurutkan
            // ke posisi yang benar dalam sub-array tersebut
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Fungsi untuk mencetak elemen-elemen array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array sebelum diurutkan:\n");
    printArray(arr, n);

    shellSort(arr, n); // Panggil fungsi Shell Sort untuk mengurutkan array

    printf("Array setelah diurutkan menggunakan Shell Sort:\n");
    printArray(arr, n);

    return 0;
}
