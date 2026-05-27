#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

void sequentialSearching();
void binarySearching();
void jelaskanPerbedaan();

int main()
{
    srand(time(0));

    int pilih;
    do {
        cout << "Pilih menu"                                                        << endl;
        cout << "1. Sequential Searching"                                           << endl;
        cout << "2. Binary Searching"                                               << endl;
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching"   << endl;
        cout << "4. Exit"                                                           << endl;
        cout << "Pilih : ";
        cin  >> pilih;
        system("cls");

        switch (pilih) {
            case 1:
                sequentialSearching();
                cout << "\npress any key to continue..."; getch(); system("cls");
                break;
            case 2:
                binarySearching();
                cout << "\npress any key to continue..."; getch(); system("cls");
                break;
            case 3:
                jelaskanPerbedaan();
                cout << "\npress any key to continue..."; getch(); system("cls");
                break;
            case 4:
                cout << "Terima kasih telah menggunakan program ini!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid! Silahkan coba lagi." << endl;
                cout << "\npress any key to continue..."; getch(); system("cls");
        }

    } while (pilih != 4);

    return 0;
}

void generateRandom(int arr[], int n)
{
    int pool[451];
    for (int i = 0; i <= 450; i++) pool[i] = i;

    for (int i = 450; i > 0; i--) {
        int j  = rand() % (i + 1);
        int tmp = pool[i];
        pool[i] = pool[j];
        pool[j] = tmp;
    }

    for (int i = 0; i < n; i++) arr[i] = pool[i];
}

void sequentialSearching()
{
    int  n, key;
    bool ketemu = false;
    int  posisi = -1;

    cout << "============================================" << endl;
    cout << "          Sequential Searching              " << endl;
    cout << "============================================" << endl;
    cout << "Masukan jumlah data : ";
    cin  >> n;

    if (n < 1 || n > 200) {
        return;
    }

    int angka[n];
    generateRandom(angka, n);

    cout << "Data :" << endl;
    for (int i = 0; i < n; i++) {
        cout << angka[i];
        if (i < n - 1) cout << ", ";
    }

    cout << "\n\nMasukan angka yang dicari : ";
    cin  >> key;

    for (int i = 0; i < n; i++) {
        if (angka[i] == key) {
            ketemu = true;
            posisi = i;
            break;
        }
    }

    if (ketemu)
        cout << "\nAngka " << key << " ditemukan pada indeks ke-" << posisi << "!";
    else
        cout << "\nAngka " << key << " tidak ditemukan!";
    cout << endl;
}

void binarySearching()
{
    int  n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;
    int  posisi = -1;

    cout << "============================================" << endl;
    cout << "            Binary Searching                " << endl;
    cout << "============================================" << endl;
    cout << "Masukan jumlah data : ";
    cin  >> n;

    if (n < 1 || n > 200) {
        return;
    }

    int angka[n];
    generateRandom(angka, n);

    cout << "Data :" << endl;
    for (int i = 0; i < n; i++) {
        cout << angka[i];
        if (i < n - 1) cout << ", ";
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (angka[j] > angka[j + 1]) {
                temp         = angka[j];
                angka[j]     = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }

    cout << "\n\nData yang telah diurutkan :" << endl;
    for (int i = 0; i < n; i++) {
        cout << angka[i];
        if (i < n - 1) cout << ", ";
    }

    cout << "\n\nMasukan angka yang dicari : ";
    cin  >> key;

    kiri  = 0;
    kanan = n - 1;
    while (kiri <= kanan) {
        tengah = (kiri + kanan) / 2;
        if (key == angka[tengah]) {
            ketemu = true;
            posisi = tengah;
            break;
        } else if (key < angka[tengah]) {
            kanan = tengah - 1;
        } else {
            kiri  = tengah + 1;
        }
    }

    if (ketemu)
        cout << "\nAngka " << key << " ditemukan pada indeks ke-" << posisi << "!";
    else
        cout << "\nAngka " << key << " tidak ditemukan!";
    cout << endl;
}

void jelaskanPerbedaan()
{
    cout << "=====================================================" << endl;
    cout << "  Perbedaan Sequential Searching & Binary Searching  " << endl;
    cout << "=====================================================" << endl;

    cout << "\n[ CARA KERJA ]" << endl;
    cout << "  Sequential : Memeriksa data satu per satu dari awal" << endl;
    cout << "               hingga data ditemukan atau habis." << endl;
    cout << "  Binary     : Membagi ruang pencarian menjadi dua setiap" << endl;
    cout << "               iterasi, lalu memeriksa nilai tengah." << endl;

    cout << "\n[ SYARAT DATA ]" << endl;
    cout << "  Sequential : Data tidak perlu diurutkan terlebih dahulu." << endl;
    cout << "  Binary     : Data wajib diurutkan terlebih dahulu." << endl;

    cout << "\n[ KOMPLEKSITAS WAKTU ]" << endl;
    cout << "  Sequential : O(n)     = semakin banyak data, semakin lama." << endl;
    cout << "  Binary     : O(log n) = jauh lebih cepat untuk data besar." << endl;

    cout << "\n==========================" << endl;
    cout << "  KELEBIHAN & KEKURANGAN  " << endl;
    cout << "==========================" << endl;

    cout << "\n>> Sequential Searching" << endl;
    cout << "   Kelebihan :" << endl;
    cout << "   + Sederhana dan mudah diimplementasikan." << endl;
    cout << "   + Bekerja pada data tidak terurut maupun terurut." << endl;
    cout << "   + Cocok untuk data berukuran kecil." << endl;
    cout << "   Kekurangan :" << endl;
    cout << "   - Lambat untuk data berukuran besar O(n)." << endl;
    cout << "   - Tidak efisien jika data yang dicari selalu di akhir." << endl;

    cout << "\n>> Binary Searching" << endl;
    cout << "   Kelebihan :" << endl;
    cout << "   + Sangat cepat untuk data berukuran besar O(log n)." << endl;
    cout << "   + Jumlah perbandingan jauh lebih sedikit dari Sequential." << endl;
    cout << "   + Efisien untuk pencarian berulang pada data yang sama." << endl;
    cout << "   Kekurangan :" << endl;
    cout << "   - Data harus diurutkan dulu, memerlukan proses sorting." << endl;
    cout << "   - Tidak cocok untuk data yang sering berubah/dinamis." << endl;
    cout << "   - Implementasi lebih kompleks dari Sequential." << endl;
}