//Created by 23343068_Hanna Fadilah

#include <stdio.h>

int main(){
	int n;
	int angka[100];
	
	printf("Masukkan banyaknya bilangan : ");scanf("%d", &n);
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		printf("Masukkan angka ke %d : ", i+1);
		scanf("%d", &angka[i]);
	}
	
	for(int i = 0; i < n; i++){
		printf("Angka %d : %d\n", i+1, angka[i]);
	}
	
	getchar();
	return 0;
}