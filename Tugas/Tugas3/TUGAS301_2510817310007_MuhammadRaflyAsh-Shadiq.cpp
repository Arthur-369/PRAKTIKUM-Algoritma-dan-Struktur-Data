#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateRandom(int arr[], int n);
void insertionSort(int arr[], int n);
int binarySearchCount(int arr[], int kiri, int kanan, int target);

int main() {
    srand(time(0));
    int n, x;

    cout << "Masukkan jumlah data dan target jumlah : ";
    cin >> n >> x;

    if(n < 10) {
        cout << "Jumlah data minimal 10!" << endl;
        return 0;
    }

    int arr[n];
    generateRandom(arr, n);

    cout << "\nData Random :" << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    insertionSort(arr, n);
    cout << "\n\nData Setelah Diurutkan :" << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    int jumlahPasangan = 0;
    for(int i = 0; i < n - 1; i++) {

        int target = x - arr[i];

        jumlahPasangan += binarySearchCount(
            arr,
            i + 1,
            n - 1,
            target
        );
    }

    cout << "\n\nJumlah pasangan = "
         << jumlahPasangan << endl;

    return 0;
}

void generateRandom(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 25 + 1;
    }
}

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

int binarySearchCount(int arr[], int kiri, int kanan, int target) {
    int posisi = -1;
    while(kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;

        if(arr[tengah] == target) {
            posisi = tengah;
            break;
        }
        else if(target < arr[tengah]) {
            kanan = tengah - 1;
        }
        else {
            kiri = tengah + 1;
        }
    }
    if(posisi == -1) {
        return 0;
    }

    int jumlah = 1;
    int i = posisi - 1;
    while(i >= kiri && arr[i] == target) {
        jumlah++;
        i--;
    }
    i = posisi + 1;
    while(i <= kanan && arr[i] == target) {
        jumlah++;
        i++;
    }
    return jumlah;
}