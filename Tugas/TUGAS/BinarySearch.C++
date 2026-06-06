#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void insertionSort(int arr[], int n) {
     for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int binarySearch(int arr[], int n, int cari) {
    int kiri = 0;
    int kanan = n - 1;

    while(kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;

        if(arr[tengah] == cari)
            return tengah;

        else if(arr[tengah] > cari)
            kanan = tengah - 1;
        
        else
            kiri = tengah + 1;
    }
    return -1;
}

int main() {
    int jumlah, cari;

    cout << "Jumlah Data : ";
    cin >> jumlah;

    int data[1000];
    srand(time(0));

    for(int i = 0; i < jumlah; i++) {
        data[i] = rand() % 1000;
    }

    cout << "\nData Sebelum Sorting : \n";

    for(int i = 0; i < jumlah; i++) {
        cout << data[i] << " ";
    }

    insertionSort(data, jumlah);

    cout << "\n\nData Setelah Insertion Sort : \n";

    for(int i = 0; i < jumlah; i++) {
        cout << data[i] << " ";
    }

    cout << "\n\nMasukkan angka yang ingin dicari : ";
    cin >> cari;

    int hasil = binarySearch(data, jumlah, cari);

    if(hasil != -1)
        cout << "\nData ditemukan di indeks ke-" << hasil;

    else
        cout << "\nData tidak di temukan";

    return 0;
}