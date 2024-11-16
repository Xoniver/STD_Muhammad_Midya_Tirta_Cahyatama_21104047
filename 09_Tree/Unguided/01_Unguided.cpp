// 1. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinputkan!
// 2. Buatlah fungsi rekursif is_valid_bst(node, min_val, max_val) untuk memeriksa apakah suatu pohon memenuhi properti Binary Search Tree. Uji fungsi ini pada berbagai pohon, baik yang valid maupun tidak valid sebagai BST.
// 3. Buatlah fungsi rekursif cari_simpul_daun(node) untuk menghitung jumlah simpul daun dalam Binary Tree. Simpul daun adalah node yang tidak memiliki anak kiri maupun kanan.

#include <iostream>

using namespace std;

// Program binary tree
// deklarasi pohon
struct Pohon{
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

// Inisiasi
void init(){
    root = NULL;
}

// Cek Node
bool isEmpty(){
    return root == NULL;
}

// Buat node baru
void buatNode(char data){
    if (isEmpty()){
        root = new Pohon{data, NULL, NULL, NULL};
        cout << "\nNode " << data << " berhasil menjadi Root" << endl;  
    } else {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

// Tambah node kiri
Pohon *insertLeft(char data, Pohon *Node) {
    if (isEmpty()) {
        cout << "\nPohon belum dibuat" << endl;
        return NULL;
    } if (Node -> left != NULL) {
        cout << "\nNode " << Node -> data << " sudah ada child kiri!" << endl;
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, Node};
    Node -> left = baru;
    cout << "\nNode " << data << " berhasil ditambahkan di kiri " << Node -> data << endl;
    return baru;
}

// Tambah node kanan
Pohon *insertRight(char data, Pohon *Node) {
    if (isEmpty()) {
        cout << "\nPohon belum dibuat" << endl;
        return NULL;
    } if (Node -> right != NULL) {
        cout << "\nNode " << Node -> data << " sudah ada child kanan!" << endl;
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, Node};
    Node -> right = baru;
    cout << "\nNode " << data << " berhasil ditambahkan di kanan " << Node -> data << endl;
    return baru;
}

// Tampilkan child node
void displayChild(Pohon *Node) {
    if (!Node) {
        cout << "Node tidak ditemukan.\n";
        return;
    }
    cout << "Node: " << Node->data << "\n";
    cout << "Child Kiri: " << (Node->left ? Node->left->data : '-') << "\n";
    cout << "Child Kanan: " << (Node->right ? Node->right->data : '-') << "\n";

}

// Tampilkan descendant node (rekursif)
void displayDescendant(Pohon *Node) {
    if (!Node) return;
    if (Node->left) {
        cout << Node->left->data << " ";
        displayDescendant(Node->left);
    }
    if (Node->right) {
        cout << Node->right->data << " ";
        displayDescendant(Node->right);
    }
}

// Fungsi rekursif untuk validasi BST
bool is_valid_bst(Pohon *node, char min_val, char max_val) {
    if (!node) return true; // Basis: node kosong selalu BST
    if (node->data <= min_val || node->data >= max_val) return false;

    // Rekursif periksa subtree kiri dan kanan
    return is_valid_bst(node->left, min_val, node->data) &&
           is_valid_bst(node->right, node->data, max_val);
}

// Fungsi rekursif untuk menghitung simpul daun
int cari_simpul_daun(Pohon *node) {
    if (!node) return 0;
    if (!node->left && !node->right) return 1;
    return cari_simpul_daun(node->left) + cari_simpul_daun(node->right);
}

// Main
void menu() {
    char pilihan, data;
    Pohon *temp = NULL;
    do {
        cout << "-----Menu Pohon Binar-----" << endl;
        cout << "1. Buat Root\n";
        cout << "2. Tambah Node Kiri\n";
        cout << "3. Tambah Node Kanan\n";
        cout << "4. Tampilkan Child Node\n";
        cout << "5. Tampilkan Descendant Node\n";
        cout << "6. Binary Search Tree\n";
        cout << "7. Cari Simpul Daun\n";
        cout << "8. Keluar\n";
        cout << "Pilihan: "; 
        cin >> pilihan;
        switch (pilihan) {
            case '1':
                cout << "Masukkan data: "; cin >> data;
                buatNode(data);
                break;
            case '2':
                cout << "Masukkan data: "; 
                cin >> data;
                cout << "Masukkan parent: "; 
                cin >> data;
                temp = insertLeft(data, temp);
                break;
            case '3':
                cout << "Masukkan data: "; 
                cin >> data;
                cout << "Masukkan parent: "; 
                cin >> data;
                temp = insertRight(data, temp);
                break;
            case '4':
                cout << "Masukkan data: "; 
                cin >> data;
                displayChild(temp);
                break;
            case '5':
                cout << "Masukkan data: "; 
                cin >> data;
                displayDescendant(temp);
                break;
            case '6':
                cout << "Masukkan data: "; 
                cin >> data;
                cout << "Apakah BST: " << (is_valid_bst(temp, -128, 127) ? "Ya" : "Tidak") << endl;
                break;
            case '7':
                cout << "Masukkan data: "; 
                cin >> data;
                cout << "Jumlah simpul daun: " << cari_simpul_daun(temp) << endl;
                break;
            case '8':
                cout << "Keluar" << endl;
                break;
            default:
                cout << "Pilihan tidak tersedia" << endl;
                break;
        }
    } while (pilihan != '8');
    
}

// main
int main() {
    init();
    menu();
    return 0;
}