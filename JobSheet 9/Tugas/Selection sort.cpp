//Created by 23343068_Hanna Fadilah
#include <stdio.h>

void selectionSort(int arr[], int n) 
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) 
	{
        min_idx = i;
        for (j = i+1; j < n; j++) 
		{
            if (arr[j] < arr[min_idx]) 
			{
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() 
{
    int arr[] = {17, 31, 25, 12, 22, 11, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}