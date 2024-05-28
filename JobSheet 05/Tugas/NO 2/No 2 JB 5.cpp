//Created by 23343068_Hanna Fadilah
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur data untuk node mobil
struct Mobil {
    char noPlat[15];
    char merk[50];
    char pemilik[50];
    struct Mobil *prev;
    struct Mobil *next;
};

// Fungsi untuk membuat node baru
struct Mobil* buatNode(char noPlat[], char merk[], char pemilik[]) {
    struct Mobil* newNode = (struct Mobil*)malloc(sizeof(struct Mobil));
    strcpy(newNode->noPlat, noPlat);
    strcpy(newNode->merk, merk);
    strcpy(newNode->pemilik, pemilik);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menambahkan mobil ke dalam linked list
void tambahMobil(struct Mobil **head, char noPlat[], char merk[], char pemilik[]) {
    struct Mobil *temp = *head;
    struct Mobil *newNode = buatNode(noPlat, merk, pemilik);
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

// Fungsi untuk menghapus mobil dari linked list berdasarkan nomor plat
void hapusMobil(struct Mobil **head, char noPlat[]) {
    struct Mobil *temp = *head;
    if (*head == NULL) {
        printf("Linked list kosong\n");
        return;
    }
    while (temp != NULL) {
        if (strcmp(temp->noPlat, noPlat) == 0) {
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
            printf("Mobil dengan nomor plat '%s' berhasil dihapus\n", noPlat);
            return;
        }
        temp = temp->next;
    }
    printf("Mobil dengan nomor plat '%s' tidak ditemukan\n", noPlat);
}

// Fungsi untuk menampilkan semua mobil dalam linked list
void tampilkanMobil(struct Mobil *node) {
    if (node == NULL) {
        printf("Linked list kosong\n");
        return;
    }
    printf("Daftar Mobil:\n");
    while (node != NULL) {
        printf("No Plat: %s, Merk: %s, Pemilik: %s\n", node->noPlat, node->merk, node->pemilik);
        node = node->next;
    }
}

// Fungsi untuk menghapus semua mobil dalam linked list
void hapusSemuaMobil(struct Mobil **head) {
    struct Mobil *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    printf("Semua mobil berhasil dihapus\n");
}

int main() {
    struct Mobil *head = NULL;

    // Menambahkan mobil ke dalam linked list
    tambahMobil(&head, "BA 1347 OI", "Agya", "Hanna");
    tambahMobil(&head, "BA 1256 IY", "Honda", "Riri");

    // Menampilkan mobil-mobil yang ada dalam linked list
    tampilkanMobil(head);

    // Menghapus mobil dengan nomor plat "BA 1347 OI"
    hapusMobil(&head, "BA 1347 OI");

    // Menampilkan mobil-mobil setelah penghapusan
    tampilkanMobil(head);

    // Menghapus semua mobil
    hapusSemuaMobil(&head);

    return 0;
}
