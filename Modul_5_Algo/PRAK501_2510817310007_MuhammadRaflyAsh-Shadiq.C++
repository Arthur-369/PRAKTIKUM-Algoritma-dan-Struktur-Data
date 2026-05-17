#include <iostream>
#include <string>
#include <conio.h>

using namespace std;
void insertionSort(string data[], int jumlah) {
    for(int i = 1; i < jumlah; i++) {
        string sementara = data[i];
        int j = i - 1;

        while(j >= 0 && data[j] > sementara) {
            data[j + 1] = data[j];
            j--;
        }

        data[j + 1] = sementara;
    }
}

void merge(string data[], int kiri, int tengah, int kanan) {

    int jumlahKiri  = tengah - kiri + 1;
    int jumlahKanan = kanan - tengah;

    string arrKiri[100], arrKanan[100];

    for(int i = 0; i < jumlahKiri; i++) {
        arrKiri[i] = data[kiri + i];
    }

    for(int j = 0; j < jumlahKanan; j++) {
        arrKanan[j] = data[tengah + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = kiri;

    while(i < jumlahKiri && j < jumlahKanan) {

        if(arrKiri[i] <= arrKanan[j]) {
            data[k] = arrKiri[i];
            i++;
        } else {
            data[k] = arrKanan[j];
            j++;
        }

        k++;
    }

    while(i < jumlahKiri) {
        data[k] = arrKiri[i];
        i++;
        k++;
    }

    while(j < jumlahKanan) {
        data[k] = arrKanan[j];
        j++;
        k++;
    }
}

void mergeSort(string data[], int kiri, int kanan) {

    if(kiri < kanan) {

        int tengah = (kiri + kanan) / 2;

        mergeSort(data, kiri, tengah);
        mergeSort(data, tengah + 1, kanan);

        merge(data, kiri, tengah, kanan);
    }
}

void shellSort(string data[], int jumlah) {

    for(int jarak = jumlah / 2; jarak > 0; jarak /= 2) {

        for(int i = jarak; i < jumlah; i++) {

            string simpan = data[i];
            int j;

            for(j = i; j >= jarak && data[j - jarak] > simpan; j -= jarak) {
                data[j] = data[j - jarak];
            }

            data[j] = simpan;
        }
    }
}

int partition(int angka[], int awal, int akhir) {

    int pivot = angka[akhir];
    int indeksKecil = awal - 1;

    for(int i = awal; i < akhir; i++) {

        if(angka[i] < pivot) {

            indeksKecil++;

            int tukar = angka[indeksKecil];
            angka[indeksKecil] = angka[i];
            angka[i] = tukar;
        }
    }

    int tukar = angka[indeksKecil + 1];
    angka[indeksKecil + 1] = angka[akhir];
    angka[akhir] = tukar;

    return indeksKecil + 1;
}

void quickSort(int angka[], int awal, int akhir) {

    if(awal < akhir) {

        int posisiPivot = partition(angka, awal, akhir);

        quickSort(angka, awal, posisiPivot - 1);
        quickSort(angka, posisiPivot + 1, akhir);
    }
}

void bubbleSort(int angka[], int jumlah) {

    for(int i = 0; i < jumlah - 1; i++) {

        for(int j = 0; j < jumlah - i - 1; j++) {

            if(angka[j] > angka[j + 1]) {

                int tukar = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = tukar;
            }
        }
    }
}

void selectionSort(int angka[], int jumlah) {

    for(int i = 0; i < jumlah - 1; i++) {

        int posisiMin = i;

        for(int j = i + 1; j < jumlah; j++) {

            if(angka[j] < angka[posisiMin]) {
                posisiMin = j;
            }
        }

        int tukar = angka[i];
        angka[i] = angka[posisiMin];
        angka[posisiMin] = tukar;
    }
}

void tampilNama(string data[], int jumlah) {

    for(int i = 0; i < jumlah; i++) {
        cout << data[i] << " ";
    }

    cout << endl;
}

void tampilNIM(int data[], int jumlah) {

    for(int i = 0; i < jumlah; i++) {
        cout << data[i] << " ";
    }

    cout << endl;
}

int main() {

    int menu;

    do {

        system("cls");

        cout << "==========================================" << endl;
        cout << "      PROGRAM ALGORITMA SORTING           " << endl;
        cout << "==========================================" << endl;
        cout << "1. Insertion Sort (Nama)" << endl;
        cout << "2. Merge Sort     (Nama)" << endl;
        cout << "3. Shell Sort     (Nama)" << endl;
        cout << "4. Quick Sort     (NIM)" << endl;
        cout << "5. Bubble Sort    (NIM)" << endl;
        cout << "6. Selection Sort (NIM)" << endl;
        cout << "7. Keluar" << endl;
        cout << "==========================================" << endl;
        cout << "Masukkan Pilihan : ";
        cin  >> menu;

        if(menu >= 1 && menu <= 3) {

            int jumlahNama;

            cout << "\nJumlah Huruf/Nama : ";
            cin  >> jumlahNama;

            string nama[100];

            cout << "Masukkan Data Nama : " << endl;

            for(int i = 0; i < jumlahNama; i++) {
                cout << "Data ke-" << i + 1 << " : ";
                cin  >> nama[i];
            }

            cout << "\nData Sebelum Sorting : ";
            tampilNama(nama, jumlahNama);

            if(menu == 1) {

                insertionSort(nama, jumlahNama);

                cout << "Hasil Insertion Sort : ";
                tampilNama(nama, jumlahNama);

            } else if(menu == 2) {

                mergeSort(nama, 0, jumlahNama - 1);

                cout << "Hasil Merge Sort : ";
                tampilNama(nama, jumlahNama);

            } else if(menu == 3) {

                shellSort(nama, jumlahNama);

                cout << "Hasil Shell Sort : ";
                tampilNama(nama, jumlahNama);
            }
        }

        else if(menu >= 4 && menu <= 6) {

            int jumlahDigit;

            cout << "\nJumlah Angka NIM : ";
            cin  >> jumlahDigit;

            int nim[100];

            cout << "Masukkan Digit NIM : " << endl;

            for(int i = 0; i < jumlahDigit; i++) {
                cout << "Angka ke-" << i + 1 << " : ";
                cin  >> nim[i];
            }

            cout << "\nData Sebelum Sorting : ";
            tampilNIM(nim, jumlahDigit);

            if(menu == 4) {

                quickSort(nim, 0, jumlahDigit - 1);

                cout << "Hasil Quick Sort : ";
                tampilNIM(nim, jumlahDigit);

            } else if(menu == 5) {

                bubbleSort(nim, jumlahDigit);

                cout << "Hasil Bubble Sort : ";
                tampilNIM(nim, jumlahDigit);

            } else if(menu == 6) {

                selectionSort(nim, jumlahDigit);

                cout << "Hasil Selection Sort : ";
                tampilNIM(nim, jumlahDigit);
            }
        }

        cout << "\nTekan tombol apapun untuk melanjutkan...";
        getch();

    } while(menu != 7);

    cout << "\nTerima kasih telah menggunakan program ini." << endl;

    return 0;
}