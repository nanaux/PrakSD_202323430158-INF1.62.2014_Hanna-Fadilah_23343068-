//created by 23343068_Hanna Fadilah
#include <stdio.h>

void bubbleSort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
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

  printf("\nBubble Sort:\n");
  bubbleSort(arr, n);
  printArray(arr, n);

  return 0;
}
