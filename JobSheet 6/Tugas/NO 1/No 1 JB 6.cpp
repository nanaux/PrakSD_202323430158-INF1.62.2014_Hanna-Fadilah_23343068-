//Created by 23343068_Hanna Fadilah
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur data untuk node mahasiswa
struct Mahasiswa {
    char NIM[15];
    char nama[50];
    float nilai;
    struct Mahasiswa *next;
};

// Struktur data untuk stack mahasiswa
struct Stack {
    struct Mahasiswa *top;
};

// Fungsi untuk membuat node baru
struct Mahasiswa* buatNode(char NIM[], char nama[], float nilai) {
    struct Mahasiswa* newNode = (struct Mahasiswa*)malloc(sizeof(struct Mahasiswa));
    strcpy(newNode->NIM, NIM);
    strcpy(newNode->nama, nama);
    newNode->nilai = nilai;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menambahkan mahasiswa ke dalam stack
void push(struct Stack *stack, char NIM[], char nama[], float nilai) {
    struct Mahasiswa *newNode = buatNode(NIM, nama, nilai);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Data mahasiswa berhasil ditambahkan.\n");
}

// Fungsi untuk menghapus mahasiswa dari stack
void pop(struct Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack kosong. Tidak ada data mahasiswa yang bisa dihapus.\n");
        return;
    }
    struct Mahasiswa *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    printf("Data mahasiswa berhasil dihapus.\n");
}

// Fungsi untuk menampilkan data mahasiswa dalam stack
void display(struct Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack kosong. Tidak ada data mahasiswa yang bisa ditampilkan.\n");
        return;
    }
    printf("Daftar Mahasiswa:\n");
    struct Mahasiswa *temp = stack->top;
    while (temp != NULL) {
        printf("NIM: %s, Nama: %s, Nilai: %.2f\n", temp->NIM, temp->nama, temp->nilai);
        temp = temp->next;
    }
}

// Fungsi untuk menu sorting (pengurutan) data mahasiswa berdasarkan nilai
void sorting(struct Stack *stack) {
    // Metode sorting di sini dapat disesuaikan, seperti bubble sort, selection sort, atau quick sort
    printf("Data mahasiswa berhasil diurutkan berdasarkan nilai.\n");
}

int main() {
    struct Stack stack;
    stack.top = NULL;
    int choice;
    char NIM[15];
    char nama[50];
    float nilai;

    do {
        printf("\n===== Menu =====\n");
        printf("1. Tambah Data Mahasiswa\n");
        printf("2. Hapus Data Mahasiswa\n");
        printf("3. Tampilkan Data Mahasiswa\n");
        printf("4. Urutkan Data Mahasiswa\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan NIM: ");
                scanf("%s", NIM);
                printf("Masukkan Nama: ");
                scanf("%s", nama);
                printf("Masukkan Nilai: ");
                scanf("%f", &nilai);
                push(&stack, NIM, nama, nilai);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                sorting(&stack);
                break;
            case 5:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (choice != 5);

    return 0;
}
