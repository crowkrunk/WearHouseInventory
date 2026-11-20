#include <string>
using namespace std;

// Forward declaration struct
struct BarangNode;
struct KategoriNode;

// Pendefinisian tipe data pointer (address) untuk masing-masing node
typedef BarangNode* addrBarang;
typedef KategoriNode* addrKategori;

// 1. Node Barang (SKU) - Menggunakan struktur Binary Search Tree (BST)
struct BarangNode {
    string idBarang;        // Kunci utama pencarian (unik)
    string namaBarang;
    int stok;
    float harga;
    addrBarang left;        // Pointer ke child kiri (ID lebih kecil)
    addrBarang right;       // Pointer ke child kanan (ID lebih besar)
};

// 2. Node Kategori (Zona) - Menggunakan struktur Multi Linked List (MLL)
struct KategoriNode {
    string namaKategori;
    int jumlahSKU;
    addrBarang rootBarang;      // Pointer penghubung ke akar BST barang
    addrKategori nextKategori;  // Pointer ke node kategori berikutnya
};

// Prototype Operasi ADT Kategori (Multi Linked List)
void CreateList(addrKategori &head);
addrKategori AlokasiKategori(string namaKategori);
void InsertKategori(addrKategori &head, string namaKategori);
void DeleteKategori(addrKategori &head, string namaKategori);
void PrintZona(addrKategori head);

// Prototype Operasi ADT Barang (Binary Search Tree)
addrBarang AlokasiBarang(string id, string nama, int stok, float harga);
addrBarang InsertBST(addrBarang root, string id, string nama, int stok, float harga);
addrBarang SearchBST(addrBarang root, string id);
void InOrderTraversal(addrBarang root);
addrBarang DeleteBST(addrBarang root, string id);
