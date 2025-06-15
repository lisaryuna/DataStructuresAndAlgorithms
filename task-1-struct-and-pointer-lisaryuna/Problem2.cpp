#include <iostream>
using namespace std;

struct kendaraan
{
    char platNomor[20], jenisKendaraan[20], namaPemilik[50], alamat[100], kota[50];
};

int main() {
    kendaraan kendaraan;

    cout << "Plat Nomor Kendaraan: ";
    cin >> kendaraan.platNomor;
    cout << "Jenis Kendaraan: ";
    cin >> kendaraan.jenisKendaraan;
    cout << "Nama Pemilik: ";
    cin.ignore();
    cin.getline(kendaraan.namaPemilik, 50);
    cout << "Alamat: ";
    cin.getline(kendaraan.alamat, 100);
    cout << "Kota: ";
    cin.getline(kendaraan.kota, 50);

    cout << "\n----------------------------------\n";
    cout << "Plat Nomor Kendaraan: " << kendaraan.platNomor << endl;
    cout << "Jenis Kendaraan: " << kendaraan.jenisKendaraan << endl;
    cout << "Nama Pemilik: " << kendaraan.namaPemilik << endl;
    cout << "Alamat: " << kendaraan.alamat << endl;
    cout << "Kota: " << kendaraan.kota << endl;
}