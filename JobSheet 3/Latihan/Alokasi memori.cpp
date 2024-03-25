//Created by 23343068_Hanna Fadilah

#include <stdio.h>
#include <stdlib.h>

typedef struct employee_st {
    char name[40];
    int id;
} Employee;

int main() {
    int myInt;
    Employee john;
    
    printf("Size of int is %lu\n", sizeof(myInt)); 
    printf("Size of Employee is %lu\n", sizeof(Employee));
    printf("Size of john is %lu\n", sizeof(john));
    printf("Size of char is %lu\n", sizeof(char));
    printf("Size of short is %lu\n", sizeof(short));
    printf("Size of int is %lu\n", sizeof(int));
    printf("Size of long is %lu\n", sizeof(long));
    printf("Size of float is %lu\n", sizeof(float));
    printf("Size of double is %lu\n", sizeof(double));
    
    return 0;
}
