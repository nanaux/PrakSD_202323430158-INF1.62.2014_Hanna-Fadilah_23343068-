//Created by 23343068_Hanna Fadilah
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Struktur data untuk node stack
struct Node {
    char data;
    struct Node* next;
};

// Struktur data untuk stack
struct Stack {
    struct Node* top;
};

// Fungsi untuk inisialisasi stack
void initializeStack(struct Stack* stack) {
    stack->top = NULL;
}

// Fungsi untuk mengecek apakah stack kosong
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Fungsi untuk menambahkan elemen ke dalam stack
void push(struct Stack* stack, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Fungsi untuk menghapus elemen dari stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong.\n");
        return '\0';
    }
    struct Node* temp = stack->top;
    char data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Fungsi untuk membaca input kata dari pengguna
void inputKata(char* kata) {
    printf("Masukkan kata: ");
    scanf("%s", kata);
}

// Fungsi untuk membalikkan kata menggunakan stack
void balikKata(char* kata) {
    struct Stack stack;
    initializeStack(&stack);
    int length = strlen(kata);

    // Push setiap karakter dari kata ke dalam stack
    for (int i = 0; i < length; i++) {
        push(&stack, kata[i]);
    }

    // Pop karakter dari stack dan kembalikan ke dalam array kata
    for (int i = 0; i < length; i++) {
        kata[i] = pop(&stack);
    }
}

int main() {
    int choice;
    char kata[MAX_LENGTH];

    do {
        printf("\n===== Menu =====\n");
        printf("1. Input Kata\n");
        printf("2. Balik Kata\n");
        printf("3. Exit\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputKata(kata);
                break;
            case 2:
                balikKata(kata);
                printf("Kata setelah dibalik: %s\n", kata);
                break;
            case 3:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (choice != 3);

    return 0;
}
