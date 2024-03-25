//Created by 23343068_Hanna Fadilah
#include <stdio.h>

// Mendefinisikan tipe data struct Mahasiswa
struct Mahasiswa {
    char NIM[20];
    char Nama[50];
    char TanggalLahir[15]; // Misal: "DD-MM-YYYY"
    float IPK;
};

int main() {
    // Deklarasi variabel bertipe struct Mahasiswa
    struct Mahasiswa mhs1;

    // Mengisi data untuk mhs1
    printf("Masukkan NIM: ");
    scanf("%s", mhs1.NIM);

    printf("Masukkan Nama: ");
    scanf("%s", mhs1.Nama);

    printf("Masukkan Tanggal Lahir (format DD-MM-YYYY): ");
    scanf("%s", mhs1.TanggalLahir);

    printf("Masukkan IPK: ");
    scanf("%f", &mhs1.IPK);

    // Menampilkan data mahasiswa
    printf("\nData Mahasiswa:\n");
    printf("NIM: %s\n", mhs1.NIM);
    printf("Nama: %s\n", mhs1.Nama);
    printf("Tanggal Lahir: %s\n", mhs1.TanggalLahir);
    printf("IPK: %.2f\n", mhs1.IPK);

    return 0;
}
