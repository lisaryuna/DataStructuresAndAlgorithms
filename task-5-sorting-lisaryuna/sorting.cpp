#include <iostream>
#include <functional>
#include <chrono>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

string name, id;

void timeSort(const function<void()>& sortFunc, const string& sortName) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << sortName << " took " << fixed << setprecision(10) << duration.count() << " seconds\n";
}

void merge(string& str, int left, int mid, int right){
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    char* leftSide = new char[leftSize];
    char* rightSide = new char[rightSize];

    for(int i = 0; i < leftSize; i++)
        leftSide[i] = str[left + i];
    for(int j = 0; j < rightSize; j++)
        rightSide[j] = str[mid + 1 + j];

    int l = 0, r = 0, k = left;
    while(l < leftSize && r < rightSize){
        if(leftSide[l] <= rightSide[r]){
            str[k++] = leftSide[l++];
        } else {
            str[k++] = rightSide[r++];
        }
    }
    while (l < leftSize)
        str[k++] = leftSide[l++];
    while (r < rightSize)
        str[k++] = rightSide[r++];
    
    delete[] leftSide;
    delete[] rightSide;
}

void mergeSortRecursive(string& str, int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSortRecursive(str, left, mid);
        mergeSortRecursive(str, mid + 1, right);
        merge(str, left, mid, right);
    }
}

void insertionSort(string& str) {
    int n = str.length();
    for(int i = 1; i < n; i++) {
        char key = str[i];
        int j = i - 1;
        while(j >= 0 && str[j] > key) {
            str[j + 1] = str[j];
            j--;
        }
        str[j + 1] = key;
    }
}

void mergeSort(string& str) {
    mergeSortRecursive(str, 0, str.length() - 1);
}

void shellSort(string& str){
    int n = str.length();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char temp = str[i];
            int j;
            for (j = i; j>= gap && str[j - gap] > temp; j -= gap) {
                str[j] = str[j - gap];
            }
            str[j] = temp;
        }
    }
}

void bubbleSort(string& str) {
    int n = str.length();
    bool swapped;
    for(int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                swap(str[j], str[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // If no two elements were swapped, the array is sorted
    }
}

int partition(string& str, int low, int high) {
    char pivot = str[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (str[j] < pivot) {
            i++;
            swap(str[i], str[j]);
        }
    }
    swap(str[i + 1], str[high]);
    return (i + 1);
}

void quickSortRecursive(string& str, int low, int high) {
    if (low < high) {
        int pi = partition(str, low, high);
        quickSortRecursive(str, low, pi - 1);
        quickSortRecursive(str, pi + 1, high);
    }
}

void quickSort(string& str) {
    quickSortRecursive(str, 0, str.length() - 1);
}

void selectionSort(string& str){
    int n = str.length();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (str[j] < str[minIndex]) {
                minIndex = j;
            }
        }
        swap(str[i], str[minIndex]);
    }
}

int main(){
    int menu;
    string name, id;
    do{
        cout << "\n------------------------" << endl;
        cout << "|--------SORTING--------|" << endl;
        cout << "------------------------" << endl;
        cout << "1. Insertion Sort" << endl;
        cout << "2. Merge Sort" << endl;
        cout << "3. Shell Sort" << endl;
        cout << "4. Quick Sort" << endl;
        cout << "5. Bubble Sort" << endl;
        cout << "6. Selection Sort" << endl;
        cout << "7. Exit" << endl;
        cout << "------------------------" << endl;
        cout << "Masukkan Pilihan: ";
        cin >> menu;
        cin.ignore(); 

        if(menu >= 1 && menu <= 3) {
            cout << "Masukkan Nama: ";
            getline(cin, name);
        } else if(menu >= 4 && menu <= 6) {
            cout << "Masukkan NIM: ";
            getline(cin, id);
        }
        string nama, nim;
        switch(menu) {
            case 1:
                cout << "\nInsertion Sort" << endl;
                nama = name;

                cout << "Nama Awal: " << name << endl;
                timeSort([&] { insertionSort(nama); }, "Insertion Sort");
                cout << "Nama Terurut: " << nama << endl;
                break;
            case 2:
                cout << "\nMerge Sort" << endl;
                nama = name;

                cout << "Nama Awal: " << name << endl;
                timeSort([&] { mergeSort(nama); }, "Merge Sort");
                cout << "Nama Terurut: " << nama << endl;
                break;
            case 3:
                cout << "\nShell Sort" << endl;
                nama = name;

                cout << "Nama Awal: " << name << endl;
                timeSort([&] { shellSort(nama); }, "Shell Sort");
                cout << "Nama Terurut: " << nama << endl;
                break;
            case 4:
                cout << "\nQuick Sort" << endl;
                nim = id;

                cout << "\nNIM Awal: " << id << endl;
                timeSort([&] { quickSort(nim); }, "Quick Sort");
                cout << "NIM Terurut: " << nim << endl;
                break;
            case 5:
                cout << "\nBubble Sort" << endl;
                nim = id;

                cout << "\nNIM Awal: " << id << endl;
                timeSort([&] { bubbleSort(nim); }, "Bubble Sort");
                cout << "NIM Terurut: " << nim << endl;
                break;
            case 6:
                cout << "\nSelection Sort" << endl;
                nim = id;
                
                cout << "\nNIM Awal: " << id << endl;
                timeSort([&] { selectionSort(nim); }, "Selection Sort");
                cout << "NIM Terurut: " << nim << endl;
                break;
            case 7:
                cout << "Exiting program." << endl;
                break;
        }
    } while(menu != 7);
    return 0;
}