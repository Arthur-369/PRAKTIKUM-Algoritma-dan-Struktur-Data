#include <conio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
#include <stdlib.h>

using namespace std;

struct TNode {
    string data;
    TNode *next;
    TNode *prev;
};

TNode *head, *tail;
int    pil, menu;
char   pilihan[3];

void initH();
void initHT();
int  isEmptyH();
int  isEmptyHT();
int  countH();
int  countHT();

void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();
void hapusDepanH();
void hapusDepanHT();
void hapusBelakangH();
void hapusBelakangHT();
void hapusTargetH();
void hapusTargetHT();
void tampilkanH();
void tampilkanHT();
void clearH();
void clearHT();

vector<string> parseInput(const string &line) {
    vector<string> result;
    istringstream iss(line);
    string token;
    while (iss >> token) result.push_back(token);
    return result;
}

int main()
{
menu:
    cout << "Double Linked List Non Circular (DLLNC)"  << endl;
    cout << "======================================="  << endl;
    cout << "Silahkan pilih program DLLNC yang ingin dijalankan!" << endl;
    cout << "1. DLLNC dengan Head"           << endl;
    cout << "2. DLLNC dengan Head dan Tail"  << endl;
    cout << "3. Quit"                        << endl;
    cout << "Pilihan : ";
    cin  >> menu;
    system("cls");

    if (menu == 1) {
        do {
            cout << "Double Linked List Non Circular (DLLNC) (Head)" << endl;
            cout << "===============================================" << endl;
            cout << "1. Tambah Depan"                     << endl;
            cout << "2. Tambah Belakang"                  << endl;
            cout << "3. Tampilkan Data"                   << endl;
            cout << "4. Hapus Depan"                      << endl;
            cout << "5. Hapus Belakang (ke-N dari Belakang)" << endl;
            cout << "6. Hapus Berdasarkan Target"         << endl;
            cout << "7. Reset"                            << endl;
            cout << "8. Kembali ke Menu"                  << endl;
            cout << "Pilihan : ";
            cin  >> pilihan;
            pil  = atoi(pilihan);

            switch (pil) {
                case 1: tambahDepanH();    break;
                case 2: tambahBelakangH(); break;
                case 3: tampilkanH();      break;
                case 4: hapusDepanH();     break;
                case 5: hapusBelakangH();  break;
                case 6: hapusTargetH();    break;
                case 7: clearH();          break;
                default:
                    system("cls");
                    goto menu;
            }

            cout << "\npress any key to continue" << endl;
            getch();
            system("cls");
        } while (pil < 8);

    } else if (menu == 2) {
        do {
            cout << "Double Linked List Non Circular (DLLNC) (Head dan Tail)" << endl;
            cout << "========================================================" << endl;
            cout << "1. Tambah Depan"                        << endl;
            cout << "2. Tambah Belakang"                     << endl;
            cout << "3. Tampilkan Data"                      << endl;
            cout << "4. Hapus Depan"                         << endl;
            cout << "5. Hapus Belakang (ke-N dari Belakang)" << endl;
            cout << "6. Hapus Berdasarkan Target"            << endl;
            cout << "7. Reset"                               << endl;
            cout << "8. Kembali ke Menu"                     << endl;
            cout << "Pilihan : ";
            cin  >> pilihan;
            pil  = atoi(pilihan);

            switch (pil) {
                case 1: tambahDepanHT();    break;
                case 2: tambahBelakangHT(); break;
                case 3: tampilkanHT();      break;
                case 4: hapusDepanHT();     break;
                case 5: hapusBelakangHT();  break;
                case 6: hapusTargetHT();    break;
                case 7: clearHT();          break;
                default:
                    system("cls");
                    goto menu;
            }

            cout << "\npress any key to continue" << endl;
            getch();
            system("cls");
        } while (pil < 8);

    } else {
        cout << "\nTERIMA KASIH" << endl;
        cout << " Muhammad Rafly Ash-Shadiq (2510817310007)." << endl;
    }

    return 0;
}

void initH()  { head = NULL; }
void initHT() { head = NULL; tail = NULL; }

int isEmptyH()  { return (head == NULL) ? 1 : 0; }
int isEmptyHT() { return (tail == NULL) ? 1 : 0; }

int countH() {
    int n = 0;
    TNode *b = head;
    while (b) { n++; b = b->next; }
    return n;
}

int countHT() {
    int n = 0;
    TNode *b = head;
    while (b) { n++; b = b->next; }
    return n;
}

void tambahDepanH() {
    cout << "Masukkan data : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string line;
    getline(cin, line);

    vector<string> v = parseInput(line);
    if (v.empty()) { cout << "Tidak ada data yang dimasukkan."; return; }

    for (int i = (int)v.size() - 1; i >= 0; i--) {
        TNode *baru  = new TNode;
        baru->data   = v[i];
        baru->next   = NULL;
        baru->prev   = NULL;
        if (isEmptyH()) {
            head = baru;
        } else {
            baru->next  = head;
            head->prev  = baru;
            head        = baru;
        }
    }

    cout << "Data berhasil dimasukkan di bagian depan: ";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << "\"" << v[i] << "\"";
        if (i < (int)v.size() - 1) cout << ", ";
    }
}

void tambahDepanHT() {
    cout << "Masukkan data : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string line;
    getline(cin, line);

    vector<string> v = parseInput(line);
    if (v.empty()) { cout << "Tidak ada data yang dimasukkan."; return; }

    for (int i = (int)v.size() - 1; i >= 0; i--) {
        TNode *baru  = new TNode;
        baru->data   = v[i];
        baru->next   = NULL;
        baru->prev   = NULL;
        if (isEmptyHT()) {
            head = baru;
            tail = baru;
        } else {
            baru->next  = head;
            head->prev  = baru;
            head        = baru;
        }
    }

    cout << "Data berhasil dimasukkan di bagian depan: ";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << "\"" << v[i] << "\"";
        if (i < (int)v.size() - 1) cout << ", ";
    }
}

void tambahBelakangH() {
    cout << "Masukkan data : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string line;
    getline(cin, line);

    vector<string> v = parseInput(line);
    if (v.empty()) { cout << "Tidak ada data yang dimasukkan."; return; }

    TNode *last = NULL;
    if (!isEmptyH()) {
        last = head;
        while (last->next) last = last->next;
    }

    for (int i = 0; i < (int)v.size(); i++) {
        TNode *baru  = new TNode;
        baru->data   = v[i];
        baru->next   = NULL;
        baru->prev   = NULL;
        if (!last) {
            head = baru;
        } else {
            last->next  = baru;
            baru->prev  = last;
        }
        last = baru;
    }

    cout << "Data berhasil dimasukkan di bagian belakang: ";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << "\"" << v[i] << "\"";
        if (i < (int)v.size() - 1) cout << ", ";
    }
}

void tambahBelakangHT() {
    cout << "Masukkan data : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string line;
    getline(cin, line);

    vector<string> v = parseInput(line);
    if (v.empty()) { cout << "Tidak ada data yang dimasukkan."; return; }

    for (int i = 0; i < (int)v.size(); i++) {
        TNode *baru  = new TNode;
        baru->data   = v[i];
        baru->next   = NULL;
        baru->prev   = NULL;
        if (isEmptyHT()) {
            head = baru;
            tail = baru;
        } else {
            tail->next  = baru;
            baru->prev  = tail;
            tail        = baru;
        }
    }

    cout << "Data berhasil dimasukkan di bagian belakang: ";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << "\"" << v[i] << "\"";
        if (i < (int)v.size() - 1) cout << ", ";
    }
}

void tampilkanH() {
    if (isEmptyH()) { cout << "Tidak terdapat data pada Linked List"; return; }
    TNode *b = head;
    while (b) { cout << b->data << ' '; b = b->next; }
    cout << endl;
}

void tampilkanHT() {
    if (isEmptyHT()) { cout << "Tidak terdapat data pada Linked List"; return; }
    TNode *b = head;
    while (b) { cout << b->data << ' '; b = b->next; }
    cout << endl;
}

void hapusDepanH() {
    if (isEmptyH()) { cout << "Tidak terdapat data pada Linked List"; return; }
    TNode *hapus = head;
    string data  = hapus->data;
    if (head->next) { head = head->next; head->prev = NULL; }
    else              initH();
    delete hapus;
    cout << "Data \"" << data << "\" yang berada di depan telah berhasil dihapus.";
}

void hapusDepanHT() {
    if (isEmptyHT()) { cout << "Tidak terdapat data pada Linked List"; return; }
    TNode *hapus = head;
    string data  = hapus->data;
    if (head->next) { head = head->next; head->prev = NULL; }
    else              initHT();
    delete hapus;
    cout << "Data \"" << data << "\" yang berada di depan telah berhasil dihapus.";
}

void hapusBelakangH() {
    if (isEmptyH()) { cout << "Tidak terdapat data pada Linked List"; return; }

    int N;
    cout << "Masukkan N : ";
    cin  >> N;

    int count = countH();

    if (N > count) {
        int oriN = N;
        N = ((N - 1) % count) + 1;
        cout << "N=" << oriN << " melebihi jumlah node (" << count
             << "), sistem mundur menggunakan N=" << N << endl;
    }

    TNode *hapus = head;
    for (int i = 0; i < count - N; i++) hapus = hapus->next;

    string data = hapus->data;

    if (hapus->prev) hapus->prev->next = hapus->next;
    else             head = hapus->next;

    if (hapus->next) hapus->next->prev = hapus->prev;

    delete hapus;
    cout << "Data \"" << data << "\" (node ke-" << N
         << " dari belakang) telah berhasil dihapus.";
}

void hapusBelakangHT() {
    if (isEmptyHT()) { cout << "Tidak terdapat data pada Linked List"; return; }

    int N;
    cout << "Masukkan N : ";
    cin  >> N;

    int count = countHT();

    if (N > count) {
        int oriN = N;
        N = ((N - 1) % count) + 1;
        cout << "N=" << oriN << " melebihi jumlah node (" << count
             << "), sistem mundur menggunakan N=" << N << endl;
    }

    TNode *hapus = tail;
    for (int i = 1; i < N; i++) hapus = hapus->prev;

    string data = hapus->data;

    if (hapus->prev) hapus->prev->next = hapus->next;
    else             head = hapus->next;

    if (hapus->next) hapus->next->prev = hapus->prev;
    else             tail = hapus->prev;

    delete hapus;
    cout << "Data \"" << data << "\" (node ke-" << N
         << " dari belakang) telah berhasil dihapus.";
}

void hapusTargetH() {
    if (isEmptyH()) { cout << "Tidak terdapat data pada Linked List"; return; }

    string target;
    cout << "Masukkan data target yang ingin dihapus : ";
    cin  >> target;

    TNode *b        = head;
    int    deleted  = 0;

    while (b) {
        TNode *nxt = b->next;
        if (b->data == target) {
            if (b->prev) b->prev->next = b->next;
            else         head          = b->next;

            if (b->next) b->next->prev = b->prev;

            delete b;
            deleted++;
        }
        b = nxt;
    }

    if (deleted)
        cout << deleted << " node dengan data \"" << target
             << "\" telah berhasil dihapus.";
    else
        cout << "Data \"" << target << "\" tidak ditemukan dalam Linked List.";
}

void hapusTargetHT() {
    if (isEmptyHT()) { cout << "Tidak terdapat data pada Linked List"; return; }

    string target;
    cout << "Masukkan data target yang ingin dihapus : ";
    cin  >> target;

    TNode *b        = head;
    int    deleted  = 0;

    while (b) {
        TNode *nxt = b->next;
        if (b->data == target) {
            if (b->prev) b->prev->next = b->next;
            else         head          = b->next;

            if (b->next) b->next->prev = b->prev;
            else         tail          = b->prev;

            delete b;
            deleted++;
        }
        b = nxt;
    }

    if (deleted)
        cout << deleted << " node dengan data \"" << target
             << "\" telah berhasil dihapus.";
    else
        cout << "Data \"" << target << "\" tidak ditemukan dalam Linked List.";
}

void clearH() {
    if (isEmptyH()) { cout << "Linked List sudah kosong."; return; }

    int  urutan   = 1;
    bool depan    = true;

    while (!isEmptyH()) {
        TNode  *hapus;
        string  data, arah;

        if (depan) {
            hapus = head;
            data  = hapus->data;
            arah  = "depan";
            if (head->next) { head = head->next; head->prev = NULL; }
            else              initH();
        } else {
            hapus = head;
            while (hapus->next) hapus = hapus->next;
            data = hapus->data;
            arah = "belakang";
            if (hapus->prev) hapus->prev->next = NULL;
            else              initH();
        }

        cout << "Penghapusan ke-" << urutan++
             << " (dari " << arah << "): \"" << data << "\"" << endl;
        delete hapus;
        depan = !depan;
    }

    cout << "Seluruh data pada Linked List telah dibersihkan.";
}

void clearHT() {
    if (isEmptyHT()) { cout << "Linked List sudah kosong."; return; }

    int  urutan   = 1;
    bool depan    = true;

    while (!isEmptyHT()) {
        TNode  *hapus;
        string  data, arah;

        if (depan) {
            hapus = head;
            data  = hapus->data;
            arah  = "depan";
            if (head->next) { head = head->next; head->prev = NULL; }
            else              initHT();
        } else {
            hapus = tail;
            data  = hapus->data;
            arah  = "belakang";
            if (tail->prev) { tail = tail->prev; tail->next = NULL; }
            else              initHT();
        }

        cout << "Penghapusan ke-" << urutan++
             << " (dari " << arah << "): \"" << data << "\"" << endl;
        delete hapus;
        depan = !depan;
    }

    cout << "Seluruh data pada Linked List telah dibersihkan.";
}