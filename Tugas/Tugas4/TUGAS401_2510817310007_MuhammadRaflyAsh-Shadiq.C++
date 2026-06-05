#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *kiri;
    Node *kanan;
};

void tambah(Node **root, int databaru) {
    if (*root == NULL) {
        Node *baru = new Node;

        baru->data = databaru;
        baru->kiri = NULL;
        baru->kanan = NULL;
        *root = baru;
    }
    else if (databaru < (*root)->data) {
        tambah(&(*root)->kiri, databaru);
    }
    else if (databaru > (*root)->data) {
        tambah(&(*root)->kanan, databaru);
    }
}

int tinggi(Node *root) {
    if (root == NULL) {
        return 0;
    }

    int tinggiKiri = tinggi(root->kiri);
    int tinggiKanan = tinggi(root->kanan);

    if (tinggiKiri > tinggiKanan) {
        return tinggiKiri + 1;
    }
    else {
        return tinggiKanan + 1;
    }
}

int diameter(Node *root) {
    if (root == NULL) {
        return 0;
    }

    int tinggiKiri = tinggi(root->kiri);
    int tinggiKanan = tinggi(root->kanan);
    int diameterLewatRoot = tinggiKiri + tinggiKanan;

    int diameterKiri = diameter(root->kiri);
    int diameterKanan = diameter(root->kanan);
    int maksimum = diameterLewatRoot;

    if (diameterKiri > maksimum) {
        maksimum = diameterKiri;
    }

    if (diameterKanan > maksimum) {
        maksimum = diameterKanan;
    }
    return maksimum;
}

int main() {
    int N;
    cout << "Masukkan jumlah node BST : ";
    cin >> N;

    Node *root = NULL;
    cout << "Masukkan " << N << " bilangan unik : ";

    for (int i = 0; i < N; i++) {
        int angka;
        cin >> angka;

        tambah(&root, angka);
    }
    cout << "\nHasil jarak terjauh : " << diameter(root) << endl;

    return 0;
}