#include <iostream>
using namespace std;

struct mhs {
    char nama[20], nim[10], jurusan[3];
    int sks, program;
};

struct mhs bayar[2];

int main() {
    int bts, var, tetap;

    for (int i = 0; i < 2; i++) {

        cout << "\n\n------------------------------\n";
        cout << "\nNama Mahasiswa = ";
        cin >> bayar[i].nama;

        cout << "NIM = ";
        cin >> bayar[i].nim;

        cout << "Jurusan [TI, PTK] = ";
        cin >> bayar[i].jurusan;

    input:
        cout << "Program [1=D3, 2=S1] = ";
        cin >> bayar[i].program;

        if (bayar[i].program < 1 || bayar[i].program > 2) {
            cout << "Program tidak sesuai\n";
            goto input;
        }

        cout << "Jumlah SKS = ";
        cin >> bayar[i].sks;

        if (bayar[i].program == 1) {
            tetap = 500000;
            var = bayar[i].sks * 25000;
        } else if (bayar[i].program == 2) {
            tetap = 750000;
            var = bayar[i].sks * 50000;
        }

        cout << "\n\n------------------------------\n";
        cout << "Output\n";
        cout << "------------------------------\n";

        cout << "\nNama Mahasiswa = " << bayar[i].nama;
        cout << "\nNIM = " << bayar[i].nim;
        cout << "\nJurusan = " << bayar[i].jurusan;
        cout << "\nProgram = " << bayar[i].program;
        cout << "\nJumlah SKS = " << bayar[i].sks;
        cout << "\nSPP tetap = " << tetap;
        cout << "\nSPP Variabel = " << var;

        cout << endl << endl;
    }

    return 0;
}