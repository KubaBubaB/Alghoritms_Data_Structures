#include <iostream>
#include <string>
using namespace std;
#define ALFABET 26


class trie {
public:
    string tlumaczenie = "";
    trie* dzieci[ALFABET];
};

trie* inicjalizuj() {
    trie* wezel = new trie;

    wezel->tlumaczenie = "";

    for (int i = 0; i < ALFABET; i++)
        wezel->dzieci[i] = nullptr;

    return wezel;
}

void dodaj(trie* korzen, string klucz_slowo, string translation) {
    trie* galaz = korzen;

    for (int i = 0; i < klucz_slowo.length(); i++) {
        int index = klucz_slowo[i] - 'a';
        if (!galaz->dzieci[index])
            galaz->dzieci[index] = inicjalizuj();

        galaz = galaz->dzieci[index];
    }

    galaz->tlumaczenie = translation;
}

void szukaj(trie* root, string klucz_slowo) {
    trie* galaz = root;

    for (int i = 0; i < klucz_slowo.length(); i++) {
        int index = klucz_slowo[i] - 'a';
        if (!galaz->dzieci[index]) {
            cout << "-" << endl;
            return;
        }
        galaz = galaz->dzieci[index];
    }
    if (galaz != nullptr && galaz->tlumaczenie != "") {
        cout << galaz->tlumaczenie << endl;
    }
    else cout << "-" << endl;
}

void Wypisz_wszystkie(trie* root) {
    if (root->tlumaczenie != "") {
        cout << root->tlumaczenie << endl;
    }
    for (int i = 0; i < ALFABET; i++) {
        if (root->dzieci[i] != nullptr) {
            Wypisz_wszystkie(root->dzieci[i]);
        }
    }
}

void Zczytaj_input() {
    trie* korzen = inicjalizuj();
    string komenda;
    while (cin >> komenda) {
        if (komenda == "+") {
            string slowo, tlumaczenie;
            cin >> slowo;
            cin >> tlumaczenie;
            dodaj(korzen, slowo, tlumaczenie);
        }
        else if (komenda == "?") {
            string szukany;
            cin >> szukany;
            szukaj(korzen, szukany);
        }
        else if (komenda == "*") {
            string prefix;
            bool flaga = true;
            cin >> prefix;
            trie* galaz = korzen;
            for (int i = 0; i < prefix.length(); i++) {
                int index = prefix[i] - 'a';
                if (!galaz->dzieci[index]) {
                    flaga = false;
                    break;
                }
                galaz = galaz->dzieci[index];
            }
            if (flaga) {
                Wypisz_wszystkie(galaz);
            }
            else cout << "-" << endl;
        }
    }
}

int main() {
    Zczytaj_input();
    return 0;
}
