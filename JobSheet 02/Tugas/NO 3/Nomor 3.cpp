//Created by 23343068_Hanna Fadilah
#include <stdio.h>

// Mendefinisikan struct Mahasiswa
struct Mahasiswa {
    int NIM;
    char Nama[50];
    char TanggalLahir[20];
    float IPK;
};

// Fungsi untuk menampilkan data mahasiswa
void tampilkanDataMahasiswa(const struct Mahasiswa *mahasiswa) {
    printf("\nInformasi Mahasiswa :\n");
    printf("\nNIM : %d\n", mahasiswa->NIM);
    printf("Nama : %s\n", mahasiswa->Nama);
    printf("Tanggal Lahir : %s\n", mahasiswa->TanggalLahir);
    printf("IPK : %.2f\n", mahasiswa->IPK);
}

// Fungsi untuk mengisi data mahasiswa
void inputDataMahasiswa(struct Mahasiswa *mahasiswa) {
    printf("Masukkan NIM : ");
    scanf("%d", &mahasiswa->NIM);

    printf("Masukkan Nama : ");
    scanf(" %[^\n]s", mahasiswa->Nama);

    printf("Masukkan Tanggal Lahir (format: DD-MM-YYYY) : ");
    scanf(" %[^\n]s", mahasiswa->TanggalLahir);

    printf("Masukkan IPK : ");
    scanf("%f", &mahasiswa->IPK);
}

int main() {
    // Mendeklarasikan variabel mahasiswa1 dengan tipe struct Mahasiswa
    struct Mahasiswa mahasiswa1;

    // Memanggil fungsi inputDataMahasiswa untuk mengisi data mahasiswa1
    inputDataMahasiswa(&mahasiswa1);

    // Memanggil fungsi tampilkanDataMahasiswa untuk menampilkan informasi mahasiswa1
    tampilkanDataMahasiswa(&mahasiswa1);

    return 0;
}
