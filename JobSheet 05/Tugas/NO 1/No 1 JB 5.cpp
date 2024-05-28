//Created by 23343068_Hanna Fadilah
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur data untuk node buku
struct Buku {
    char judul[100];
    char pengarang[50];
    int tahun;
    struct Buku *prev;
    struct Buku *next;
};

// Fungsi untuk membuat node baru
struct Buku* buatNode(char judul[], char pengarang[], int tahun) {
    struct Buku* newNode = (struct Buku*)malloc(sizeof(struct Buku));
    strcpy(newNode->judul, judul);
    strcpy(newNode->pengarang, pengarang);
    newNode->tahun = tahun;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menambahkan buku ke dalam linked list
void tambahBuku(struct Buku **head, char judul[], char pengarang[], int tahun) {
    struct Buku *temp = *head;
    struct Buku *newNode = buatNode(judul, pengarang, tahun);
    if (*head == NULL) {
        *head = newNode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Fungsi untuk menghapus buku dari linked list berdasarkan judul
void hapusBuku(struct Buku **head, char judul[]) {
    struct Buku *temp = *head;
    if (*head == NULL) {
        printf("Linked list kosong\n");
        return;
    }
    while (temp != NULL) {
        if (strcmp(temp->judul, judul) == 0) {
            if (temp->prev == NULL) {
                *head = temp->next;
                if (*head != NULL)
                    (*head)->prev = NULL;
            } else if (temp->next == NULL) {
                temp->prev->next = NULL;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            free(temp);
            printf("Buku dengan judul '%s' berhasil dihapus\n", judul);
            return;
        }
        temp = temp->next;
    }
    printf("Buku dengan judul '%s' tidak ditemukan\n", judul);
}

// Fungsi untuk menampilkan semua buku dalam linked list
void tampilkanBuku(struct Buku *node) {
    if (node == NULL) {
        printf("Linked list kosong\n");
        return;
    }
    printf("Daftar Buku:\n");
    while (node != NULL) {
        printf("Judul: %s, Pengarang: %s, Tahun: %d\n", node->judul, node->pengarang, node->tahun);
        node = node->next;
    }
}

// Fungsi untuk menghapus semua buku dalam linked list
void hapusSemuaBuku(struct Buku **head) {
    struct Buku *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    printf("Semua buku berhasil dihapus\n");
}

int main() {
    struct Buku *head = NULL;

    // Menambahkan buku ke dalam linked list
    tambahBuku(&head, "Cara menjadi wanita sholehah", "Hanna", 2020);
    tambahBuku(&head, "Cara berbakti kepada orang tua", "Hanna", 2021);

    // Menampilkan buku-buku yang ada dalam linked list
    tampilkanBuku(head);

    // Menghapus buku dengan judul "Cara menjadi wanita sholehah"
    hapusBuku(&head, "Cara menjadi wanita sholehah");

    // Menampilkan buku-buku setelah penghapusan
    tampilkanBuku(head);

    // Menghapus semua buku
    hapusSemuaBuku(&head);

    return 0;
}
