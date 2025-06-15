#include <iostream>
#include <conio.h>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;


void sequentialSearch(const vector<int> &nums, int target){
    int count = 0;

    cout << "\nMenjalankan Sequential Search..." << endl;

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == target) {
            cout << "Angka " << target << " ditemukan pada indeks ke-" << i << "." << endl;
            count++;
        }
    }

    if (count == 0) {
        cout << "Angka " << target << " tidak ditemukan dalam daftar." << endl;
    } else {
        cout << "Total kemunculan: " << count << endl;
    }
}

void binarySearch(const vector<int> &nums, int target){
    vector<int> sortedNums = nums;
    sort(sortedNums.begin(), sortedNums.end());

    cout << "\nMenjalankan Binary Search..." << endl;
    cout << "Daftar angka yang diurutkan:\n";
    for (int i = 0; i < sortedNums.size(); ++i) {
        cout << "[" << i << "] " << sortedNums[i] << " ";
        if ((i + 1) % 10 == 0) cout << endl;
    }

    int left = 0;
    int right = sortedNums.size() - 1;
    bool found = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sortedNums[mid] == target) {
            cout << "\nAngka " << target << " ditemukan pada indeks ke-" << mid << " (dalam daftar yang diurutkan)." << endl;
            found = true;
            break;
        } else if (sortedNums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) {
        cout << "\nAngka " << target << " tidak ditemukan dalam daftar." << endl;
    }
}

/// use this to clear screen, change if necessary
void clearScreen(){
    system("cls");
}

// use this to  print your answer
void explain(){
    cout << "\n--- Perbedaan Sequential Searching dan Binary Searching ---" << endl;
    cout << "Sequential Searching (Pencarian Berurutan):" << endl;
    cout << "1. Cara Kerja: Metode ini mencari elemen secara berurutan, satu per satu, dari awal hingga akhir daftar." << endl;
    cout << "2. Persyaratan Data: Tidak memerlukan data yang diurutkan. Dapat bekerja pada daftar angka yang tidak terurut." << endl;
    cout << "3. Kecepatan: Relatif lebih lambat, terutama untuk daftar yang besar, karena dalam kasus terburuk harus memeriksa setiap elemen." << endl;
    cout << "4. Kompleksitas Waktu: Memiliki kompleksitas waktu rata-rata O(n), di mana 'n' adalah jumlah elemen dalam daftar." << endl;
    cout << "5. Kegunaan: Cocok untuk daftar yang kecil atau ketika data tidak perlu diurutkan." << endl;
    cout << "\nBinary Searching (Pencarian Biner):" << endl;
    cout << "1. Cara Kerja: Metode ini bekerja dengan membagi daftar menjadi dua bagian pada setiap langkah. Ini membandingkan elemen target dengan elemen tengah, dan kemudian memutuskan apakah akan mencari di paruh kiri atau paruh kanan." << endl;
    cout << "2. Persyaratan Data: Wajib memerlukan data yang sudah diurutkan. Jika data tidak diurutkan, Binary Search tidak akan memberikan hasil yang benar." << endl;
    cout << "3. Kecepatan: Jauh lebih cepat daripada Sequential Search untuk daftar yang besar, karena setiap langkah mengurangi ruang pencarian menjadi setengahnya." << endl;
    cout << "4. Kompleksitas Waktu: Memiliki kompleksitas waktu rata-rata O(log n), yang berarti waktu pencarian meningkat secara logaritmik dengan ukuran daftar." << endl;
    cout << "5. Kegunaan: Sangat efisien untuk daftar yang besar dan sudah terurut, seperti dalam database atau kamus." << endl;
    cout << "\n--- Kesimpulan ---" << endl;
    cout << "Pilihan antara Sequential Search dan Binary Search tergantung pada apakah data Anda sudah diurutkan dan seberapa besar daftar yang akan dicari." << endl;
}


int main() {
    int opt, target;
    do {
        cout << "Pilih menu" << endl;
        cout << "1. Sequential Searching" << endl;
        cout << "2. Binary Searching" << endl;
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilih: ";
        cin >> opt;

        switch (opt) {
            case 1: {
                vector<int> nums (100);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 50);

                for (auto &val: nums) {
                    val = (dist(rng));
                }

                // give message here
                // print the number list
                cout << "Daftar angka: " << endl;
                for (int i = 0; i < nums.size(); ++i) {
                    cout << "[" << i << "] " << nums[i] << " ";
                    if ((i + 1) % 10 == 0) cout << endl;
                }
                
                cout << "\nMasukkan angka yang ingin dicari: "; cin >> target;
                sequentialSearch(nums, target);
                break;
            }

            case 2: {
                int size;
                cout << "Masukkan ukuran vector: ";
                cin >> size;

                vector<int> nums(size);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 100);

                for (auto &val: nums) {
                    val = (dist(rng));
                }

                // give message here
                // print the number list
                cout << "Daftar angka:\n";
                for (int i = 0; i < nums.size(); ++i) {
                    cout << "[" << i << "] " << nums[i] << " ";
                    if ((i + 1) % 10 == 0) cout << endl;
                }

                cout << "\nMasukkan angka yang ingin dicari: "; cin >> target;
                binarySearch(nums, target);
                break;
            }

            case 3:
                explain();
                break;

            case 4:
                cout << "\nTERIMA KASIH\n";
                cout << "Programme was made by Noor Khalisa (2410817220012)" << endl;
                break;

            default:
                cout << "Opsi tidak terdefinisi, mohon masukkan ulang opsi" << endl;
                break;
        }

        if (opt != 4) {
            cout << "\nTekan sembarang tombol untuk melanjutkan...";
            getch();
            clearScreen();
        }

    } while (opt != 4);

    return 0;
}