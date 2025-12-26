#include <iostream>
#include <iomanip>
#include <string>
#include <numeric>

using namespace std;

struct transaksi
{
    string namaBarang;
    int hargaBarang;
    int jumlahBeli;
};

void inputPembelian(int jumlahBarang, transaksi pembelian[]){
    for (size_t i = 0; i < jumlahBarang; i++)
    {
        cout << "Nama barang: ";
        cin >> pembelian[i].namaBarang;
        cout << "Harga barang: ";
        cin >> pembelian[i].hargaBarang;
        cout << "Jumlah beli: ";
        cin >> pembelian[i].jumlahBeli;
    }
    
}

int tampilkanPembelian(int jumlahBarang, transaksi pembelian[]){
    int totalHarga;
    cout << setfill('=') << setw(50) << '=' << endl;
    cout << "Nama Barang     Harga        Qty         Subtotal" << endl;
    cout << setfill('-') << setw(50) << '-' << endl;
    int subtotal[jumlahBarang];
    for (size_t i = 0; i < jumlahBarang; i++)
    {
        cout << pembelian[i].namaBarang << "       ";
        cout << pembelian[i].hargaBarang << "            ";
        cout << pembelian[i].jumlahBeli << "               ";
        subtotal[i] = pembelian[i].hargaBarang * pembelian[i].jumlahBeli;
        cout << subtotal[i] << endl;
    }
    cout << setfill('-') << setw(50) << '-' << endl << endl;
    totalHarga = accumulate(subtotal, subtotal+jumlahBarang, 0);
    cout << "Total harga: " << totalHarga << endl;

    return totalHarga;
}

void pembayaran(int totalHarga){
    int bayar, Kembalian;
    cout << "Uang pembayaran = ";
    cin >> bayar;
    
    if (bayar < totalHarga)
    {
       cout << "Uang tidak cukup" << endl;
       return; 
    }
    cout << "Kembalian = " << bayar - totalHarga << endl;
    cout << "Terimakasih sudah berbelanja di toko kami" << endl;
}

void headerStruk(){
    cout << setfill('=') << setw(50) << '=' << endl;
    cout << "PROGRAM KASIR TOKO" << endl;
    cout << setfill('=') << setw(50) << '=' << endl;
}

int main(){
    int jumlahBarang;
    
    // blok kode menampilkan header
    headerStruk();    
    
    // blok kode 1
    cout << "Masukkan jumlah barang: ";
    cin >> jumlahBarang;
    transaksi pembelian[jumlahBarang];
    
    inputPembelian(jumlahBarang, pembelian);
    
    // blok kode 2
    int totalHarga = tampilkanPembelian(jumlahBarang, pembelian);

    // blok kode 3
    pembayaran(totalHarga);
    
    return 0;
}