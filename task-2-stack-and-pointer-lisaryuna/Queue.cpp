#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 20

using namespace std;

// write the definition (body) of the queue here using struct and array
// the elements of the queue are char 
struct Queue
{
    int F, R;
    char Q[MAX];
} Q;

int PIL;
char PILIHAN [1], HURUF;

// write the function to implement all the operation needed
// enqueue, dequeue, isEmpty, isFull, display, reset, init
int isEmpty(){
    return (Q.F == -1);
}
int isFull(){
    return (Q.R == MAX - 1);

}
void INSERT() {
    if(isFull()) {
        cout << "Queue penuh. Tidak bisa menambah data.\n";
    } else {
        cout << "Masukkan huruf: ";
        cin >> HURUF;

        if(isEmpty()) {
            Q.F = Q.R = 0; 
        } else {
            Q.R++; 
        }

        Q.Q[Q.R] = HURUF;
        cout << "Data " << HURUF << " berhasil dimasukkan ke queue.\n";
    }
}

void DELETE() {
    if (isEmpty()) {
        cout << "Queue kosong. Tidak ada data untuk dihapus.\n";
    } else {
        cout << "Data " << Q.Q[Q.F] << " dihapus dari queue.\n";

        if(Q.F == Q.R) {
            Q.F = Q.R = -1; 
        } else {
            Q.F++; 
        }
    }
}

void CETAKLAYAR() {
    if(isEmpty()) {
        cout << "Queue kosong.\n";
    } else {
        cout << "Isi queue: ";
        for(int i = Q.F; i <= Q.R; i++) {
            cout << Q.Q[i] << " ";
        }
        cout << endl;
    }
}

void Inisialisasi() {
    Q.F = Q.R = -1;
}

void RESET() {
    Q.F = Q.R = -1;
    cout << "Queue berhasil dikosongkan.\n";
}

// write the menu function in main scope
// to insert, delete, display, reset, exit
int main()
{
    Inisialisasi();
    do
    {
            cout <<"QUEUE"<< endl;
            cout <<"================"<< endl;
            cout <<"1. INSERT"<< endl;
            cout <<"2. DELETE"<< endl;
            cout <<"3. CETAK QUEUE"<< endl;
            cout <<"4. QUIT"<< endl;
            cout <<"PILIHAN: "; cin >> PILIHAN;
            PIL= atoi(PILIHAN);
        switch (PIL)
        {
        case 1:
            INSERT();
            break;
        case 2:
            DELETE();
            break;
        case 3:
            CETAKLAYAR();
            break;
        default:
            cout << "TERIMA KASIH" << endl;
            break;    
        }
        cout << "press any key to continue" << endl;
        getch();
        system("cls");
        } while (PIL<4);
    return 0;
}