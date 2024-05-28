//Created by 23343068_Hanna Fadilah
#include <stdio.h>

// Mendefinisikan struct Mahasiswa
struct Mahasiswa {
    int NIM;
    char Nama[50];
    char TanggalLahir[20];
    float IPK;
};

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

    // Menampilkan informasi mahasiswa1
    printf("\nInformasi Mahasiswa :\n");
    printf("\nNIM : %d\n", mahasiswa1.NIM);
    printf("Nama : %s\n", mahasiswa1.Nama);
    printf("Tanggal Lahir : %s\n", mahasiswa1.TanggalLahir);
    printf("IPK : %.2f\n", mahasiswa1.IPK);

    return 0;
}
