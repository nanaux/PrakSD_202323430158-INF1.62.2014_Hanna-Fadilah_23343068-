//created by 23343068_Hanna Fadilah
#include <stdio.h>

// Fungsi untuk melakukan partisi pada array dan mengembalikan index pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pilih elemen terakhir sebagai pivot
    int i = low - 1; // Index dari elemen yang lebih kecil dari pivot

    for (int j = low; j < high; j++) {
        // Jika elemen saat ini lebih kecil atau sama dengan pivot
        if (arr[j] <= pivot) {
            i++; // Tingkatkan index dari elemen yang lebih kecil
            // Tukar elemen arr[i] dan arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Tukar elemen arr[i+1] dan arr[high] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // Kembalikan index dari pivot
}

// Fungsi untuk melakukan Quick Sort pada array
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Lakukan partisi dan dapatkan index pivot
        int pi = partition(arr, low, high);

        // Rekursif untuk bagian sebelum pivot dan setelah pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fungsi untuk mencetak elemen-elemen array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array sebelum diurutkan:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1); // Panggil fungsi Quick Sort untuk mengurutkan array

    printf("Array setelah diurutkan menggunakan Quick Sort:\n");
    printArray(arr, n);

    return 0;
}
