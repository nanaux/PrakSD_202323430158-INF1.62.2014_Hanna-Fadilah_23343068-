// created by 23343068_Hanna Fadilah
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mahasiswa {
    int nim;
    char nama[50];
    char ttl[20];
    float ipk;
} Mahasiswa;

Mahasiswa* data_mahasiswa; // Pointer untuk menyimpan data mahasiswa
int jumlah_mahasiswa; // Jumlah data mahasiswa

// Fungsi untuk inisialisasi data mahasiswa
void inisialisasi_mahasiswa() {
    // Mengalokasikan memori untuk data mahasiswa
    data_mahasiswa = (Mahasiswa*)malloc(4 * sizeof(Mahasiswa));
    if (data_mahasiswa == NULL) {
        printf("Gagal mengalokasikan memori\n");
        exit(1);
    }

    // Inisialisasi data mahasiswa secara manual
    data_mahasiswa[0] = (Mahasiswa){23343068, "Hanna", "2006-06-27", 3.8};
    data_mahasiswa[1] = (Mahasiswa){23343066, "Gema", "2005-01-11", 3.8};
    data_mahasiswa[2] = (Mahasiswa){23343086, "Serly", "2005-02-22", 3.8};
    data_mahasiswa[3] = (Mahasiswa){23343050, "Bunga", "2003-04-04", 3.7};

    // Mengatur jumlah_mahasiswa sesuai jumlah data yang diinisialisasi
    jumlah_mahasiswa = 4;
}

// Fungsi untuk mencari data mahasiswa dengan sequential search
Mahasiswa* sequential_search(int nim_dicari) {
    for (int i = 0; i < jumlah_mahasiswa; i++) {
        if (data_mahasiswa[i].nim == nim_dicari) {
            return &data_mahasiswa[i];
        }
    }
    return NULL;
}

// Fungsi untuk membandingkan dua mahasiswa berdasarkan NIM
int compare_nim(const void* a, const void* b) {
    Mahasiswa* mahasiswa1 = (Mahasiswa*)a;
    Mahasiswa* mahasiswa2 = (Mahasiswa*)b;
    return mahasiswa1->nim - mahasiswa2->nim;
}

// Fungsi untuk mencari data mahasiswa dengan binary search
Mahasiswa* binary_search(int nim_dicari) {
    int low = 0;
    int high = jumlah_mahasiswa - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (data_mahasiswa[mid].nim == nim_dicari) {
            return &data_mahasiswa[mid];
        } else if (data_mahasiswa[mid].nim < nim_dicari) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return NULL;
}

int main() {
    // Inisialisasi data mahasiswa
    inisialisasi_mahasiswa();

    // Mengurutkan data mahasiswa untuk binary search
    qsort(data_mahasiswa, jumlah_mahasiswa, sizeof(Mahasiswa), compare_nim);

    // Menampilkan data mahasiswa yang telah diinisialisasi
    printf("Data mahasiswa yang diinisialisasi:\n");
    for (int i = 0; i < jumlah_mahasiswa; i++) {
        printf("Mahasiswa ke-%d:\n", i + 1);
        printf("NIM: %d\n", data_mahasiswa[i].nim);
        printf("Nama: %s\n", data_mahasiswa[i].nama);
        printf("TTL: %s\n", data_mahasiswa[i].ttl);
        printf("IPK: %.2f\n", data_mahasiswa[i].ipk);
    }

    // Mencari data mahasiswa dengan NIM yang diberikan
    int nim_dicari;
    printf("\nMasukkan NIM yang ingin dicari: ");
    if (scanf("%d", &nim_dicari) != 1) {
        printf("Input tidak valid.\n");
        free(data_mahasiswa);
        return 1;
    }

    Mahasiswa* mahasiswa_dicari_sequential = sequential_search(nim_dicari);
    if (mahasiswa_dicari_sequential != NULL) {
        printf("\nPencarian Sequential Search:\n");
        printf("NIM: %d\n", mahasiswa_dicari_sequential->nim);
        printf("Nama: %s\n", mahasiswa_dicari_sequential->nama);
        printf("TTL: %s\n", mahasiswa_dicari_sequential->ttl);
        printf("IPK: %.2f\n", mahasiswa_dicari_sequential->ipk);
    } else {
        printf("Data tidak ditemukan dengan Sequential Search.\n");
    }

    Mahasiswa* mahasiswa_dicari_binary = binary_search(nim_dicari);
    if (mahasiswa_dicari_binary != NULL) {
        printf("\nPencarian Binary Search:\n");
        printf("NIM: %d\n", mahasiswa_dicari_binary->nim);
        printf("Nama: %s\n", mahasiswa_dicari_binary->nama);
        printf("TTL: %s\n", mahasiswa_dicari_binary->ttl);
        printf("IPK: %.2f\n", mahasiswa_dicari_binary->ipk);
    } else {
        printf("Data tidak ditemukan dengan Binary Search.\n");
    }

    // Menggunakan free untuk mengembalikan memori yang dialokasikan
    free(data_mahasiswa);

    return 0;
}
