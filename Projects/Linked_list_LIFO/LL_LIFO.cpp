#include <iostream>
using namespace std;
#define WYPISZ 1
#define NIEWYPISUJ 0

class Lista {
public:
    int key;
    Lista* nastepnik;
    Lista* poprzednik;
};

void dodaj_na_koniec(Lista** poczatek,Lista**koniec, int nowy_key) {
    Lista* nowy_element = new Lista();

    nowy_element->key = nowy_key;

    nowy_element->nastepnik = NULL;

    if (*koniec == NULL) {
        nowy_element->poprzednik = NULL;
        *poczatek = nowy_element;
        nowy_element->nastepnik = NULL;
        *koniec = nowy_element;
        return;
    }
    else {
        Lista* temp = *koniec;
        temp->nastepnik = nowy_element;
        nowy_element->poprzednik = temp;
        *koniec = nowy_element;
    }
    return;
}

void usun_ostatni(Lista** koniec,Lista** poczatek, int czywypisac) {
    Lista* temporary = *koniec;
    if (czywypisac) {
        cout << temporary->key << endl;
    }
    if (*koniec == *poczatek) {
        *koniec = NULL;
        free(temporary);
        return;
    }
    if (temporary->poprzednik != NULL) {
        Lista* temp = temporary->poprzednik;
        temp->nastepnik = NULL;
        *koniec = temporary->poprzednik;
    }
    free(temporary);
}

void szukaj(Lista** poczatek, int indeks) {
    Lista* obecny = *poczatek;
    for (int i = 0; i < indeks; i++) {
        if (obecny->nastepnik != NULL) {
            obecny = obecny->nastepnik;
        }
        else break;
    }
    cout << obecny->key << endl;
}

int main() {
    Lista* poczatek = NULL;
    Lista* koniec = NULL;
    char komenda='d';
    while (komenda != 'q') {
        cin >> komenda;
        switch (komenda) {
        case 'i':
            int key;
            cin >> key;
            dodaj_na_koniec(&poczatek,&koniec, key);
            break;
        case 'd':
            usun_ostatni(&koniec,&poczatek, WYPISZ);
            break;
        case 'g':
            int indeks;
            cin >> indeks;
            szukaj(&poczatek, indeks);
            break;
        case 'q':
            while (koniec != NULL) {
                usun_ostatni(&koniec,&poczatek, NIEWYPISUJ);
            }
            break;
        }
    }
    return 0;
}
