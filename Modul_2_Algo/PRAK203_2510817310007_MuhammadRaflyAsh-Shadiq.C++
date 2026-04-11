#include <iostream>
using namespace std;
#define n 10

int F, R;
char Q[n];

void Inisialisasi() {
    F = -1;
    R = -1;
}

bool kosong() {
    return (F == -1 || F > R);
}

bool penuh() {
    return (R == n - 1);
}

void INSERT() {
    if (penuh()) {
        cout << "Queue Penuh!\n";
    } else {
        char huruf;
        cout << "Masukkan huruf: ";
        cin >> huruf;

        if (F == -1)
            F = 0;

        R++;
        Q[R] = huruf;

        cout << "Data '" << huruf << "' masuk ke queue.\n";
    }
}

void DELETE() {
    if (kosong()) {
        cout << "Queue Kosong!\n";
    } else {
        cout << "Data keluar: " << Q[F] << endl;
        F++;

        if (F > R)
            Inisialisasi();
    }
}

void CETAKLAYAR() {
    if (kosong()) {
        cout << "Queue Kosong!\n";
    } else {
        cout << "Isi Queue: ";
        for (int i = F; i <= R; i++) {
            cout << Q[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int pilihan;

    Inisialisasi();

    do {
        cout << "\n=== MENU QUEUE ===\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Cetak Queue\n";
        cout << "4. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                INSERT();
                break;
            case 2:
                DELETE();
                break;
            case 3:
                CETAKLAYAR();
                break;
            case 4:
                cout << "Program selesai\n";
                break;
            default:
                cout << "Pilihan tidak valid\n";
        }

    } while (pilihan != 4);

    return 0;
}