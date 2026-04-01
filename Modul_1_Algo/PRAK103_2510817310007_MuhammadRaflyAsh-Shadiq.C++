#include <iostream>
using namespace std;

int main() {
    char huruf;
    char kata[50];
    int angka;

    cout << "Masukkan sebuah huruf = ";
    cin >> huruf;

    cout << "Masukkan sebuah kata = ";
    cin.ignore();
    cin.getline(kata, 50);

    cout << "Masukkan Angka = ";
    cin >> angka;

    cout << "\n\n------------------------------\n";

    cout << "Huruf yang Anda masukkan adalah " << huruf << endl;
    cout << "Kata yang Anda masukkan adalah " << kata << endl;
    cout << "Angka yang Anda masukkan adalah " << angka << endl;

    return 0;
}