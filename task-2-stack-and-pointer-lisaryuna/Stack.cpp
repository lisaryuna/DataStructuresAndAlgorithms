#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 20

using namespace std;

// write the definition (body) of the stack here using struct and array
// the elements of the stack are integers
struct Stack
{
    int atas;
    int data[MAX];
} Tumpuk;

int kosong()
{
    if (Tumpuk.atas == -1)
        return 1;
    else
        return 0;
}

int penuh()
{
    if(Tumpuk.atas == MAX - 1)
        return 1;
    else
        return 0;
}
// write the function to implement all the operation needed
// push, pop, isEmpty, isFull, display, reset, init
void input (int data)
{
    if(kosong()==1)
    {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas]
            << " Masuk Ke Stack\n";
    }
    else if(penuh()==0)
    {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas]
            << " Masuk Ke Stack\n";
    }
    else
        cout << "Tumpukan Penuh\n";
}
void hapus()
{
    if(kosong()==0)
    {
        cout << "Data Teratas Sudah Terambil\n";
        Tumpuk.atas--;
    }
    else
    cout << "Data Kosong";
}
void tampil()
{
    if(kosong()==0)
    {
        for(int i = Tumpuk.atas; i >= 0; i--)
        {
            cout << "\nTumpukan Ke-" << i << " = "
            << Tumpuk.data[i];
        }
    }
    else
    cout << "Tumpukan Kosong";
}
void bersih ()
{
    Tumpuk.atas = -1;
    cout << "Tumpukan Kosong !";
}

// write the menu function in main scope
// to insert, delete, display, reset, exit

int main(){
    Tumpuk.atas = -1;
    int pilihan, data;
    do{
        cout << "\nMenu:\n";
        cout << "1. Masukkan Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Tampilkan Stack\n";
        cout << "4. Kosongkan Stack\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        switch(pilihan)
        {
            case 1:
                cout << "Masukkan Data: ";
                cin >> data;
                input(data);
                break;
            case 2:
                hapus();
                break;
            case 3:
                tampil();
                break;
            case 4:
                bersih();
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while(pilihan != 5);
    return 0;
}