//created by 23343068_Hanna Fadilah
#include <stdio.h>

void insertionSort(int arr[], int n) {
  int i, j, key;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {5, 2, 4, 1, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Array sebelum diurutkan: ");
  printArray(arr, n);

  printf("\nInsertion Sort:\n");
  insertionSort(arr, n);
  printArray(arr, n);

  return 0;
}
