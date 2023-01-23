#include <iostream>
#include <string>
using namespace std;


void zamien_elementy(string array[], int i, int j) {
    string tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

int porownaj(string array[], int i1, int i2) {
    string liczba1 = array[i1];
    string liczba2 = array[i2];
    if (liczba1.length() > liczba2.length()) {
        return i1;
    }
    else if (liczba1.length() < liczba2.length()) {
        return i2;
    }
    return -1;//sa rowne
}

int partition(string array[], int low, int high) {
    string pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (porownaj(array, j, high) == -1) {
            if (array[j] <= pivot) {
                i++;
                zamien_elementy(array, i,j);
            }
        }
        else if (porownaj(array, j, high) == high){
            i++;
            zamien_elementy(array, i, j);
        }
    }
    zamien_elementy(array, i + 1,high);
    return (i + 1);
}

void wypisz_wymaluj(string* array, int dlugosc) {
    for (int i = 0; i < dlugosc; i++) {
        cout << array[i] << endl;
    }
}

void quickSort(string* array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int main() {
	int liczba_elementow;
	cin >> liczba_elementow;
	string* tablica = new string[liczba_elementow];
	for (int i = 0; i < liczba_elementow; i++) {
		cin >> tablica[i];
	}
    quickSort(tablica, 0, liczba_elementow-1);
    wypisz_wymaluj(tablica, liczba_elementow);
    return 0;
}