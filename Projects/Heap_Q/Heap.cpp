#include <iostream>
#include <string>
#define PO_DACIE 0
#define PO_NAZWIE 1
using namespace std;

class Kopiec {
public:
    string nazwa;
    string data;
};

void zamien(Kopiec* lewa, Kopiec *prawa){
    Kopiec temp= *lewa;
    *lewa=*prawa;
    *prawa=temp;
}

int porownaj(string lewy, string prawy) {//po dacie
    for (int i = 0; i < 4; i++) {
        if (lewy[6 + i] > prawy[6 + i]) {
            return 1;
        }
        else if (lewy[6 + i] < prawy[6 + i]) {
            return -1;
        }
    }
    for (int i = 0; i < 2; i++) {
        if (lewy[3 + i] > prawy[3 + i]) {
            return 1;
        }
        else if (lewy[3 + i] < prawy[3 + i]) {
            return -1;
        }
    }
    for (int i = 0; i < 2; i++) {
        if (lewy[i] > prawy[i]) {
            return 1;
        }
        else if (lewy[i] < prawy[i]) {
            return -1;
        }
    }
    return 0;
}

Kopiec* Dodaj(Kopiec* wskaznik, int dlugosc, int sortowanie,string imie, string date) {
    Kopiec* nowy = new Kopiec[dlugosc + 1];
    for (int i = 0; i < dlugosc; i++) {
        nowy[i] = wskaznik[i];
    }
    delete[] wskaznik;
    nowy[dlugosc].data = date;
    nowy[dlugosc].nazwa = imie;
    int j=dlugosc;
    if (sortowanie == PO_DACIE) {
        while (j != 0 && porownaj(nowy[(j-1)/2].data, nowy[j].data)==1){
            zamien(&nowy[j], &nowy[(j-1)/2]);
            j = (j-1)/2;
        }
    }
    if (sortowanie == PO_NAZWIE) {
        while (j != 0 && nowy[(j-1)/2].nazwa > nowy[j].nazwa){
            zamien(&nowy[j], &nowy[(j-1)/2]);
            j = (j-1)/2;
        }
    }
    return nowy;
}

Kopiec* Usun(Kopiec* wskaznik, int dlugosc){
    Kopiec* nowy = new Kopiec[dlugosc-1];
    for (int i=0;i<dlugosc-1;i++){
        nowy[i] = wskaznik[i];
    }
    delete[] wskaznik;
    return nowy;
}

void Sortuj_pod_dacie(Kopiec* wskaznik, int dlugosc, int i) {
    int lewy_dziec = 2*i + 1;
    int prawy_dziec = 2*i + 2;
    if(prawy_dziec<dlugosc){
        int ktory=porownaj(wskaznik[lewy_dziec].data,wskaznik[prawy_dziec].data);
        if(ktory<=0){
            if(porownaj(wskaznik[lewy_dziec].data,wskaznik[i].data)==-1){
                zamien(&wskaznik[i], &wskaznik[lewy_dziec]);
                Sortuj_pod_dacie(wskaznik,dlugosc,lewy_dziec);
            }
        }
        else{
            if(porownaj(wskaznik[prawy_dziec].data,wskaznik[i].data)==-1){
                zamien(&wskaznik[i], &wskaznik[prawy_dziec]);
                Sortuj_pod_dacie(wskaznik,dlugosc,prawy_dziec);
            }
        }
    }
    else if(lewy_dziec<dlugosc){
        if(porownaj(wskaznik[lewy_dziec].data,wskaznik[i].data)==-1){
            zamien(&wskaznik[i], &wskaznik[lewy_dziec]);
            Sortuj_pod_dacie(wskaznik,dlugosc,lewy_dziec);
        }
    }
}

void Sortuj_pod_nazwie(Kopiec* wskaznik,int dlugosc, int i) {
    int lewy_dziec = 2*i + 1;
    int prawy_dziec = 2*i + 2;
    if(prawy_dziec<dlugosc){
        if(wskaznik[lewy_dziec].nazwa<=wskaznik[prawy_dziec].nazwa){
            if(wskaznik[lewy_dziec].nazwa<wskaznik[i].nazwa){
                zamien(&wskaznik[i], &wskaznik[lewy_dziec]);
                Sortuj_pod_nazwie(wskaznik,dlugosc,lewy_dziec);
            }
        }
        else{
            if(wskaznik[prawy_dziec].nazwa<wskaznik[i].nazwa){
                zamien(&wskaznik[i], &wskaznik[prawy_dziec]);
                Sortuj_pod_nazwie(wskaznik,dlugosc,prawy_dziec);
            }
        }
    }
    else if(lewy_dziec<dlugosc){
        if(wskaznik[lewy_dziec].nazwa<wskaznik[i].nazwa){
            zamien(&wskaznik[i], &wskaznik[lewy_dziec]);
            Sortuj_pod_nazwie(wskaznik,dlugosc,lewy_dziec);
        }
    }
}

void Wypisz(Kopiec* heap, int dlugosc) {
    for (int i = 0; i < dlugosc+1; i++) {
        cout << heap[i].data << " " << heap[i].nazwa << endl;
    }
    cout<<endl;
}

void ExtractN(Kopiec* heap, int dlugosc) {
    heap[0] = heap[dlugosc-1];
    Sortuj_pod_nazwie(heap,dlugosc-1,0);
}

void ExtractD(Kopiec* heap, int dlugosc) {
    heap[0] = heap[dlugosc-1];
    Sortuj_pod_dacie(heap,dlugosc-1,0);
}

Kopiec* Przepisz(Kopiec* heap, int dlugosc, int sortowanie){
    Kopiec* nowy= new Kopiec[1];
    for(int i=0;i<dlugosc;i++){
        nowy= Dodaj(nowy,i,sortowanie,heap[i].nazwa,heap[i].data);
    }
    delete [] heap;
    return nowy;
}

void Zczytaj_wejscie() {
    int sortowanie = PO_NAZWIE;
    char wejscie[1];
    Kopiec* heap= new Kopiec[1];
    int dlugosc = 0;
    while (*wejscie != 'q') {
        cin >> *wejscie;
        switch (*wejscie) {
            case '+':
                int ile_elementow;
                cin >> ile_elementow;
                for (int i = 0; i < ile_elementow; i++) {
                    string imie;
                    string date;
                    cin >> date;
                    cin >> imie;
                    heap=Dodaj(heap, dlugosc,sortowanie,imie,date);
                    dlugosc++;
                }
                break;
            case '-':
                int ile_element;
                cin >> ile_element;
                for (int i = 0; i < ile_element; i++) {
                    cout << heap[0].data << " " << heap[0].nazwa << endl;
                    if(sortowanie==PO_DACIE){
                        ExtractD(heap,dlugosc);
                    }
                    else ExtractN(heap,dlugosc);
                    heap=Usun(heap,dlugosc);
                    dlugosc--;
                }
                cout<<endl;
                break;
            case 'p':
                Wypisz(heap, dlugosc - 1);
                break;
            case 'r':
                if (sortowanie == PO_DACIE) {
                    sortowanie = PO_NAZWIE;
                }
                else {
                    sortowanie = PO_DACIE;
                }
                heap= Przepisz(heap,dlugosc,sortowanie);
                break;
            case 'q':
                break;
        }
    }
    //tu zwolnic pamiec
    delete [] heap;
}


int main(){
    Zczytaj_wejscie();
    return 0;
}