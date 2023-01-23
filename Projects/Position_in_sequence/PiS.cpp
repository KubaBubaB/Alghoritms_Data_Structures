#include <iostream>
#define ROSNACA 1
#define MALEJACA 0
using namespace std;

int BinarySearch(int poczatek, int koniec, int* tab, int szukana,int monotonicznosc) {
	int srodek = (poczatek + koniec) / 2;
	if (szukana == tab[srodek]) {
		return srodek;
	}
	else if (poczatek >= koniec) {
		return -1;
	}
	if (((szukana < tab[srodek]) && (monotonicznosc == ROSNACA)) || ((szukana > tab[srodek]) && (monotonicznosc == MALEJACA))) {
		return BinarySearch(poczatek, srodek-1, tab, szukana, monotonicznosc);
	}
	else if (((szukana > tab[srodek]) && (monotonicznosc == ROSNACA)) || ((szukana < tab[srodek]) && (monotonicznosc == MALEJACA))) {
		return BinarySearch(srodek+1, koniec, tab, szukana, monotonicznosc);
	}
	return -1;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int wielkosc_tablicy;
		cin >> wielkosc_tablicy;
		int *tab = new int[wielkosc_tablicy];
		for (int j = 0; j < wielkosc_tablicy; j++) {
			int element;
			cin >> element;
			tab[j] = element;
		}
		int l_ele_do_wyszukania;
		cin >> l_ele_do_wyszukania;
		for (int k = 0; k < l_ele_do_wyszukania; k++) {
			int szukany;
			cin >> szukany;
			if (tab[0] < tab[1]) {
				cout << BinarySearch(0, wielkosc_tablicy, tab, szukany, ROSNACA)<<endl;
			}
			else cout << BinarySearch(0, wielkosc_tablicy, tab, szukany,MALEJACA)<<endl;
		}
		delete[] tab;
	}
	return 0;
}