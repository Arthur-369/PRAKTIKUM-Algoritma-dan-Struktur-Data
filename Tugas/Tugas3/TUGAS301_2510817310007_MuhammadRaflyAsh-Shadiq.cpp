#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateRandom(int arr[], int n);
void bubbleSort(int arr[], int n);
bool binarySearch(int arr[], int kiri, int kanan, int target);

int main() {
    srand(time(0));
    int n, x;

    cout << "Masukkan jumlah data dan target jumlah : ";
        cin >> n >> x;

    if(n < 10) {
        cout << "Jumlah data minimal 10" << endl;
        return 0;
    }

    int arr[n];
    generateRandom(arr, n);
    cout << "\nData Random :" << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    bubbleSort(arr, n);
    int jumlahPasangan = 0;
    for(int i = 0; i < n - 1; i++) {

        if(i > 0 && arr[i] == arr[i - 1])
            continue;

        int target = x - arr[i];

        if(binarySearch(arr, i + 1, n - 1, target)) {
            jumlahPasangan++;
        }
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

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {

            if(arr[j] > arr[j + 1]) {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

bool binarySearch(int arr[], int kiri, int kanan, int target) {
    while(kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;

        if(arr[tengah] == target) {
            return true;
        }
        else if(target < arr[tengah]) {
            kanan = tengah - 1;
        }
        else {
            kiri = tengah + 1;
        }
    }
    return false;
}