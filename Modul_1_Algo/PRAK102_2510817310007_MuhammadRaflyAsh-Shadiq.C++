#include <iostream>
using namespace std;

struct kendaraan {
    char plat[15];
    char jenis[20];
    char nama[30];
    char alamat[50];
    char kota[20];
};

int main() {
    kendaraan data;

    cout << "Masukkan Data Kendaraan\n";

    cout << "Plat Nomor Kendaraan = ";
    cin >> data.plat;

    cout << "Jenis Kendaraan = ";
    cin.ignore();
    cin.getline(data.jenis, 20);

    cout << "Nama Pemilik = ";
    cin.getline(data.nama, 30);

    cout << "Alamat = ";
    cin.getline(data.alamat, 50);

    cout << "Kota = ";
    cin.getline(data.kota, 20);

    cout << "\n\n------------------------------\n";
    cout << "Output\n";
    cout << "------------------------------\n";

    cout << "Plat Nomor Kendaraan : " << data.plat << endl;
    cout << "Jenis Kendaraan      : " << data.jenis << endl;
    cout << "Nama Pemilik         : " << data.nama << endl;
    cout << "Alamat               : " << data.alamat << endl;
    cout << "Kota                 : " << data.kota << endl;

    return 0;
}