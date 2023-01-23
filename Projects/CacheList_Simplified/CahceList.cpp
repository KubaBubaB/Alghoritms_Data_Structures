#include <iostream>
#include <string.h>
using namespace std;
#define WLICZBA 10
#define POCZATEK 10
#define KONIEC 11
#define WSZYSTKO 12

struct Lista {
    unsigned long long int klucz;
    Lista* nastepnik;
    Lista* poprzednik;
};

struct WLista{
    Lista* poczatek=nullptr;
    Lista* koniec=nullptr;
    Lista* Iteratory[WLICZBA]={nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr};
};

int sprawdz_pozycje(char numerek[]) {
    if (strcmp(numerek, "BEG") == 0) {
        //wskaznik na poczatek listy
        return POCZATEK;
    }
    else if (strcmp(numerek, "END") == 0) {
        //wskaznik na koniec listy
        return KONIEC;
    }
    else if (strcmp(numerek, "ALL") == 0) {
        return WSZYSTKO;
    }
    else if (strcmp(numerek, "0") == 0) {
        return 0;
    }
    else if (strcmp(numerek, "1") == 0) {
        return 1;
    }
    else if (strcmp(numerek, "2") == 0) {
        return 2;
    }
    else if (strcmp(numerek, "3") == 0) {
        return 3;
    }
    else if (strcmp(numerek, "4") == 0) {
        return 4;
    }
    else if (strcmp(numerek, "5") == 0) {
        return 5;
    }
    else if (strcmp(numerek, "6") == 0) {
        return 6;
    }
    else if (strcmp(numerek, "7") == 0) {
        return 7;
    }
    else if (strcmp(numerek, "8") == 0) {
        return 8;
    }
    else if (strcmp(numerek, "9") == 0) {
        return 9;
    }
    return -1;
}

void dodaj_przed(WLista* wskazniki, int iterator, unsigned long long int key) {
    Lista* nowy_element = new Lista;
    nowy_element->klucz = key;

    if (wskazniki->koniec!=nullptr) {
        if ((iterator == POCZATEK) || (wskazniki->Iteratory[iterator]==wskazniki->poczatek)) {
            Lista* temp = wskazniki->poczatek;
            nowy_element->nastepnik = temp;
            nowy_element->poprzednik = nullptr;
            temp->poprzednik = nowy_element;
            wskazniki->poczatek = nowy_element;
            return;
        }
        Lista* temp = nullptr;
        if (iterator == KONIEC) {
            temp = wskazniki->koniec;
        }
        else {
            temp = wskazniki->Iteratory[iterator];
        }
        nowy_element->poprzednik = temp->poprzednik;
        nowy_element->nastepnik = temp;
        Lista* temp2 = temp->poprzednik;
        temp2->nastepnik = nowy_element;
        temp->poprzednik = nowy_element;
    }
    else {
        nowy_element->poprzednik = nullptr;
        wskazniki->poczatek = nowy_element;
        nowy_element->nastepnik = nullptr;
        wskazniki->koniec = nowy_element;
    }
}

void dodaj_za(WLista* wskazniki, int iterator, unsigned long long int key) {
    Lista* nowy_element = new Lista;
    nowy_element->klucz = key;

    if (wskazniki->koniec != nullptr) {
        if ((iterator == KONIEC) || (wskazniki->Iteratory[iterator]==wskazniki->koniec)) {
            Lista* temp = wskazniki->koniec;
            nowy_element->nastepnik = nullptr;
            nowy_element->poprzednik = temp;
            temp->nastepnik = nowy_element;
            wskazniki->koniec = nowy_element;
            return;
        }
        Lista* temp = nullptr;
        if (iterator == POCZATEK) {
            temp = wskazniki->poczatek;
        }
        else {
            temp = wskazniki->Iteratory[iterator];
        }
        nowy_element->poprzednik = temp;
        nowy_element->nastepnik = temp->nastepnik;
        Lista* temp2 = temp->nastepnik;
        temp2->poprzednik = nowy_element;
        temp->nastepnik = nowy_element;
    }
    else{
        nowy_element->poprzednik = nullptr;
        wskazniki->koniec = nowy_element;
        nowy_element->nastepnik = nullptr;
        wskazniki->poczatek = nowy_element;
    }
}

void zainicjuj_iterator(WLista* wskazniki, int iterator) {
    char pozycja[3];
    cin >> pozycja;
    int numer_iteratora = sprawdz_pozycje(pozycja);
    if (numer_iteratora < POCZATEK) {
        wskazniki->Iteratory[iterator] = wskazniki->Iteratory[numer_iteratora];
    }
    else if (numer_iteratora == POCZATEK) {
        wskazniki->Iteratory[iterator] = wskazniki->poczatek;
    }
    else if (numer_iteratora ==KONIEC){
        wskazniki->Iteratory[iterator] = wskazniki->koniec;
    }
}

void usun(WLista* wskazniki, int pozycja) {
    Lista* temporary = wskazniki->koniec;
    if (pozycja== POCZATEK) {
        temporary = wskazniki->poczatek;
    }
    else if (pozycja < POCZATEK) {
        temporary = wskazniki->Iteratory[pozycja];
    }
    if (wskazniki->koniec == wskazniki->poczatek) {
        wskazniki->koniec = nullptr;
        wskazniki->poczatek = nullptr;
        for (int i = 0; i < WLICZBA; i++) {
            wskazniki->Iteratory[i] = nullptr;
        }
        free(temporary);
        return;
    }
    for (int i = 0; i < WLICZBA; i++) {//przesuwanie iteratorow
        if (wskazniki->Iteratory[i] == temporary) {
            if (temporary == wskazniki->koniec) {
                wskazniki->Iteratory[i] = temporary->poprzednik;
            }
            else {
                wskazniki->Iteratory[i] = temporary->nastepnik;
            }
        }
    }

    if (temporary == wskazniki->poczatek) {
        Lista* temp2 = temporary->nastepnik;
        temp2->poprzednik = nullptr;
        wskazniki->poczatek = temp2;
    }
    else if (temporary == wskazniki->koniec) {
        Lista* temp2 = temporary->poprzednik;
        temp2->nastepnik = nullptr;
        wskazniki->koniec = temp2;
    }
    else {
        Lista* temp2 = temporary->poprzednik;
        Lista* temp3 = temporary->nastepnik;
        temp3->poprzednik = temp2;
        temp2->nastepnik = temp3;
    }

    free(temporary);
}

void wypisz(WLista* wskazniki, int pozycja) {
    if (pozycja == WSZYSTKO && (wskazniki->poczatek!=nullptr)) {
        Lista* temp = wskazniki->poczatek;
        while (temp != nullptr) {
            cout << temp->klucz<<" ";
            temp = temp->nastepnik;
        }
    }
    else if (wskazniki->poczatek != nullptr) {
        Lista* temp = wskazniki->Iteratory[pozycja];
        cout << temp->klucz;
    }
    cout<<endl;
}

void przesun_do_przodu(WLista* wskazniki, int numer_iteratora) {
    if (wskazniki->Iteratory[numer_iteratora] == wskazniki->koniec) {
        return;
    }
    Lista* temp = wskazniki->Iteratory[numer_iteratora];
    wskazniki->Iteratory[numer_iteratora] = temp->nastepnik;
}

void przesun_do_tylu(WLista* wskazniki, int numer_iteratora) {
    if (wskazniki->Iteratory[numer_iteratora] == wskazniki->poczatek) {
        return;
    }
    Lista* temp = wskazniki->Iteratory[numer_iteratora];
    wskazniki->Iteratory[numer_iteratora] = temp->poprzednik;
}

void Zczytaniekomendy() {
    WLista wskazniki;
    char command[3];
    while (cin>>command) {
        if (strcmp("I", command) == 0) {
            int i;
            cin >> i;
        }
        else if (strcmp("i", command) == 0) {
            int iterator;
            cin >> iterator;
            zainicjuj_iterator(&wskazniki, iterator);
        }
        else if (strcmp("+", command) == 0) {
            int numer_iteratora;
            cin >> numer_iteratora;
            przesun_do_przodu(&wskazniki,numer_iteratora);
        }
        else if (strcmp("-", command) == 0) {
            int numer_iteratora;
            cin >> numer_iteratora;
            przesun_do_tylu(&wskazniki, numer_iteratora);
        }
        else if (strcmp(".A", command) == 0) {
            char iterator[3];
            cin >> iterator;
            int numer_iteratora = sprawdz_pozycje(iterator);
            unsigned long long int key;
            cin >> key;
            dodaj_przed(&wskazniki,numer_iteratora,key);
        }
        else if (strcmp("A.", command) == 0) {
            char iterator[3];
            cin >> iterator;
            int numer_iteratora = sprawdz_pozycje(iterator);
            unsigned long long int key;
            cin >> key;
            dodaj_za(&wskazniki,numer_iteratora,key);
        }
        else if (strcmp("R", command) == 0) {
            char pozycja[3];
            cin >> pozycja;
            int numer_iteratora = sprawdz_pozycje(pozycja);
            usun(&wskazniki, numer_iteratora);
        }
        else if (strcmp("P", command) == 0) {
            char pozycja[3];
            cin >> pozycja;
            int numer_iteratora = sprawdz_pozycje(pozycja);
            wypisz(&wskazniki, numer_iteratora);
        }
    }
}



int main() {
    Zczytaniekomendy();
    return 0;
}