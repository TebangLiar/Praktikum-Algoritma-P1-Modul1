#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

void insertionSort(string &arr) {
    int n = arr.length();
    for (int i = 1; i < n; i++) {
        char key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(string &arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    string L = arr.substr(l, n1);
    string R = arr.substr(m + 1, n2);
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { arr[k] = L[i]; i++; }
        else { arr[k] = R[j]; j++; }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
}

void mergeSort(string &arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void shellSort(string &arr) {
    int n = arr.length();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            char temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

void bubbleSort(string &arr) {
    int n = arr.length();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(string &arr) {
    int n = arr.length();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

int partition(string &arr, int low, int high) {
    char pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(string &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int pilihan;
    // Variabel menggunakan Nama dan NIM praktikan
    string namaAsli = "AhmadRiyadhi"; 
    string nimAsli = "2510817110004";
    string dataNama;
    string dataNim;

    do {
        system("cls");
        dataNama = namaAsli;
        dataNim = nimAsli;

        cout << "SORTING" << endl;
        cout << "=======================" << endl;
        cout << "1. Insertion Sort (Nama)" << endl;
        cout << "2. Merge Sort (Nama)" << endl;
        cout << "3. Shell Sort (Nama)" << endl;
        cout << "4. Quick Sort (NIM)" << endl;
        cout << "5. Bubble Sort (NIM)" << endl;
        cout << "6. Selection Sort (NIM)" << endl;
        cout << "7. Exit" << endl;
        cout << "Masukkan Pilihan : ";
        cin >> pilihan;

        cout << "\n--- HASIL EKSEKUSI ---" << endl;
        switch (pilihan) {
            case 1:
                cout << "Data Awal Nama : " << dataNama << endl;
                insertionSort(dataNama);
                cout << "Hasil Insertion Sort : " << dataNama << endl;
                break;
            case 2:
                cout << "Data Awal Nama : " << dataNama << endl;
                mergeSort(dataNama, 0, dataNama.length() - 1);
                cout << "Hasil Merge Sort : " << dataNama << endl;
                break;
            case 3:
                cout << "Data Awal Nama : " << dataNama << endl;
                shellSort(dataNama);
                cout << "Hasil Shell Sort : " << dataNama << endl;
                break;
            case 4:
                cout << "Data Awal NIM : " << dataNim << endl;
                quickSort(dataNim, 0, dataNim.length() - 1);
                cout << "Hasil Quick Sort : " << dataNim << endl;
                break;
            case 5:
                cout << "Data Awal NIM : " << dataNim << endl;
                bubbleSort(dataNim);
                cout << "Hasil Bubble Sort : " << dataNim << endl;
                break;
            case 6:
                cout << "Data Awal NIM : " << dataNim << endl;
                selectionSort(dataNim);
                cout << "Hasil Selection Sort : " << dataNim << endl;
                break;
            case 7:
                cout << "Program Selesai. Terima Kasih." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
        if(pilihan != 7) {
            cout << "\nPress any button untuk kembali ke menu...";
            getch();
        }
    } while (pilihan != 7);

    return 0;
}
