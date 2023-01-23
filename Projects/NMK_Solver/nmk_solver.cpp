#include <iostream>
#include <string.h>
using namespace std;
#define DLUGOSC_KOMENDY 33

class plansza{
public:
    int Wysokosc;
    int Szerokosc;
    char** pola;
    int Active_Player;
    int Ile_kolo_sie;
};

int Sprawdz_czy_wygrana(plansza *dowypisania){
    int ile_sprawdzen=dowypisania->Ile_kolo_sie;
    //sprawdz poziom
    for (int i=0;i<dowypisania->Wysokosc;i++){
        int kolo_siebie1=0;
        int kolo_siebie2=0;
        for(int j=0;j<dowypisania->Szerokosc;j++){
            char symbol=dowypisania->pola[i][j];
            if(symbol=='1'){
                kolo_siebie1++;
                if(kolo_siebie2!=0){
                    kolo_siebie2=0;
                }
            }
            else if(symbol=='2'){
                kolo_siebie2++;
                if(kolo_siebie1!=0){
                    kolo_siebie1=0;
                }
            }
            else{
                kolo_siebie2=0;
                kolo_siebie1=0;
            }
            if(kolo_siebie1==ile_sprawdzen){
                return 1;
            }
            else if(kolo_siebie2==ile_sprawdzen){
                return 2;
            }
        }
    }
    //sprawdz pion
    for (int i=0;i<dowypisania->Szerokosc;i++){
        int kolo_siebie1=0;
        int kolo_siebie2=0;
        for(int j=0;j<dowypisania->Wysokosc;j++){
            char symbol=dowypisania->pola[j][i];
            if(symbol=='1'){
                kolo_siebie1++;
                if(kolo_siebie2!=0){
                    kolo_siebie2=0;
                }
            }
            else if(symbol=='2'){
                kolo_siebie2++;
                if(kolo_siebie1!=0){
                    kolo_siebie1=0;
                }
            }
            else{
                kolo_siebie2=0;
                kolo_siebie1=0;
            }
            if(kolo_siebie1==ile_sprawdzen){
                return 1;
            }
            else if(kolo_siebie2==ile_sprawdzen){
                return 2;
            }
        }
    }
    //sprawdz skos idac od 0,0 do sizeY,sizeX
    for (int i=1;i<dowypisania->Wysokosc;i++){
        int kolo_siebie1=0;
        int kolo_siebie2=0;
        for(int j=0;j<i+1;j++){
            if(dowypisania->Wysokosc-1-i+j<dowypisania->Wysokosc && j<dowypisania->Szerokosc){//upewnienie sie ze nie bedzie memory leaka
                if(dowypisania->pola[dowypisania->Wysokosc-1-i+j][j]=='1'){
                    kolo_siebie1++;
                    if(kolo_siebie2!=0){
                        kolo_siebie2=0;
                    }
                }
                else if(dowypisania->pola[dowypisania->Wysokosc-1-i+j][j]=='2'){
                    kolo_siebie2++;
                    if(kolo_siebie1!=0){
                        kolo_siebie1=0;
                    }
                }
                else{
                    kolo_siebie2=0;
                    kolo_siebie1=0;
                }
                if(kolo_siebie1==ile_sprawdzen){
                    return 1;
                }
                else if(kolo_siebie2==ile_sprawdzen){
                    return 2;
                }
            }
        }
    }
    for(int i=1;i<dowypisania->Szerokosc;i++){
        int kolo_siebie1=0;
        int kolo_siebie2=0;
        for(int j=0;j<i+1;j++){
            if(j<dowypisania->Wysokosc && dowypisania->Szerokosc-1-i+j<dowypisania->Szerokosc){//upewnienie sie ze nie bedzie memory leaka
                if(dowypisania->pola[j][dowypisania->Szerokosc-1-i+j]=='1'){
                    kolo_siebie1++;
                    if(kolo_siebie2!=0){
                        kolo_siebie2=0;
                    }
                }
                else if(dowypisania->pola[j][dowypisania->Szerokosc-1-i+j]=='2'){
                    kolo_siebie2++;
                    if(kolo_siebie1!=0){
                        kolo_siebie1=0;
                    }
                }
                else{
                    kolo_siebie2=0;
                    kolo_siebie1=0;
                }
                if(kolo_siebie1==ile_sprawdzen){
                    return 1;
                }
                else if(kolo_siebie2==ile_sprawdzen){
                    return 2;
                }
            }
        }
    }
    //sprawdz skos idac od sizeY,0 do 0,sizeX
    for (int i=1;i<dowypisania->Wysokosc;i++){
        int kolo_siebie1=0;
        int kolo_siebie2=0;
        for(int j=0;j<i+1;j++){
            if(dowypisania->Wysokosc-1-i+j<dowypisania->Wysokosc && dowypisania->Szerokosc-j<dowypisania->Szerokosc){//upewnienie sie ze nie bedzie memory leaka
                if(dowypisania->pola[dowypisania->Wysokosc-1-i+j][dowypisania->Szerokosc-j]=='1'){
                    kolo_siebie1++;
                    if(kolo_siebie2!=0){
                        kolo_siebie2=0;
                    }
                }
                else if(dowypisania->pola[dowypisania->Wysokosc-1-i+j][dowypisania->Szerokosc-j]=='2'){
                    kolo_siebie2++;
                    if(kolo_siebie1!=0){
                        kolo_siebie1=0;
                    }
                }
                else{
                    kolo_siebie2=0;
                    kolo_siebie1=0;
                }
                if(kolo_siebie1==ile_sprawdzen){
                    return 1;
                }
                else if(kolo_siebie2==ile_sprawdzen){
                    return 2;
                }
            }
        }
    }
    for(int i=1;i<dowypisania->Szerokosc;i++){
        int kolo_siebie1=0;
        int kolo_siebie2=0;
        for(int j=0;j<i+1;j++){
            if(j<dowypisania->Wysokosc && i-j<dowypisania->Szerokosc){//upewnienie sie ze nie bedzie memory leaka
                if(dowypisania->pola[j][i-j]=='1'){
                    kolo_siebie1++;
                    if(kolo_siebie2!=0){
                        kolo_siebie2=0;
                    }
                }
                else if(dowypisania->pola[j][i-j]=='2'){
                    kolo_siebie2++;
                    if(kolo_siebie1!=0){
                        kolo_siebie1=0;
                    }
                }
                else{
                    kolo_siebie2=0;
                    kolo_siebie1=0;
                }
                if(kolo_siebie1==ile_sprawdzen){
                    return 1;
                }
                else if(kolo_siebie2==ile_sprawdzen){
                    return 2;
                }
            }
        }
    }
    return 0;//brak wygranej
}

void Skopiuj_plansze(plansza* ctrlc,plansza* ctrlv){
    ctrlv->Wysokosc=ctrlc->Wysokosc;
    ctrlv->Szerokosc=ctrlc->Szerokosc;
    ctrlv->Active_Player=ctrlc->Active_Player;
    ctrlv->Ile_kolo_sie=ctrlc->Ile_kolo_sie;
    ctrlv->pola=new char*[ctrlv->Wysokosc];
    for(int i=0;i<ctrlv->Wysokosc;i++){
        ctrlv->pola[i]=new char[ctrlv->Szerokosc];
    }
    for(int i=0;i<ctrlv->Wysokosc;i++){
        for(int j=0;j<ctrlv->Szerokosc;j++){
            ctrlv->pola[i][j]=ctrlc->pola[i][j];
        }
    }
}

void debug_wypisz(plansza *dowypisania){
    for(int i=0;i<dowypisania->Wysokosc;i++){
        for(int j=0;j<dowypisania->Szerokosc;j++){
            char wypisz=dowypisania->pola[i][j];
            printf("%c ",wypisz);
        }
        printf("\n");
    }
}

int Ilosc_Mozliwych_Ruchow(plansza *dowypisania){
    int ile_zer=0;
    for(int i=0;i<dowypisania->Wysokosc;i++){
        for(int j=0;j<dowypisania->Szerokosc;j++){
            if(dowypisania->pola[i][j]=='0'){
                ile_zer++;
            }
        }
    }
    return ile_zer;
}

void Generuj_Wypisz(plansza *dowypisania){
    int ile=Ilosc_Mozliwych_Ruchow(dowypisania);
    printf("%i",ile);
    printf("\n");
    for(int i=0;i<dowypisania->Wysokosc;i++){
        for(int j=0;j<dowypisania->Szerokosc;j++){
            plansza* tmp = new plansza;
            Skopiuj_plansze(dowypisania,tmp);
            if(dowypisania->Active_Player==1 && dowypisania->pola[i][j]=='0'){
                tmp->pola[i][j]='1';
                debug_wypisz(tmp);
            }
            else if( dowypisania->pola[i][j]=='0'){
                tmp->pola[i][j]='2';
                debug_wypisz(tmp);
            }
            delete tmp;
        }
    }
}

void Generuj_do_wygranej(plansza *dowypisania){
    int ile=Ilosc_Mozliwych_Ruchow(dowypisania);
    int licznik=0;
    plansza** Zbior_mozliwosci= new plansza*[ile];
    for(int i=0;i<dowypisania->Wysokosc;i++){
        for(int j=0;j<dowypisania->Szerokosc;j++){
            plansza* tmp = new plansza;
            Skopiuj_plansze(dowypisania,tmp);
            if(dowypisania->Active_Player==1 && dowypisania->pola[i][j]=='0'){
                tmp->pola[i][j]='1';
                Zbior_mozliwosci[licznik]=tmp;
                licznik++;
            }
            else if( dowypisania->pola[i][j]=='0'){
                tmp->pola[i][j]='2';
                Zbior_mozliwosci[licznik]=tmp;
                licznik++;
            }
            if(Sprawdz_czy_wygrana(tmp)){
                printf("1");
                printf("\n");
                debug_wypisz(tmp);
                for(int k=0;k<licznik;k++){
                    for(int l=0;l<dowypisania->Wysokosc;l++){
                        delete [] Zbior_mozliwosci[k]->pola[l];
                    }
                    delete [] Zbior_mozliwosci[k];
                }
                delete [] Zbior_mozliwosci;
                return;
            }
        }
    }
    printf("%i",ile);
    printf("\n");
    for(int i=0;i<licznik;i++){
        debug_wypisz(Zbior_mozliwosci[i]);
    }
    for(int i=0;i<ile;i++){
        for(int j=0;j<dowypisania->Wysokosc;j++){
            delete [] Zbior_mozliwosci[i]->pola[j];
        }
        delete [] Zbior_mozliwosci[i];
    }
    delete [] Zbior_mozliwosci;
}

int Rozwiaz_stan(plansza* dowypisania){
    int ile=Ilosc_Mozliwych_Ruchow(dowypisania);
    int licznik=0;
    plansza** Zbior_mozliwosci= new plansza*[ile];
    for(int i=0;i<dowypisania->Wysokosc;i++){//generacja wszystkich mozliwych ruchow
        for(int j=0;j<dowypisania->Szerokosc;j++){
            plansza* tmp = new plansza;
            Skopiuj_plansze(dowypisania,tmp);
            if(dowypisania->Active_Player==1 && dowypisania->pola[i][j]=='0'){
                tmp->pola[i][j]='1';
                Zbior_mozliwosci[licznik]=tmp;
                licznik++;
            }
            else if( dowypisania->pola[i][j]=='0'){
                tmp->pola[i][j]='2';
                Zbior_mozliwosci[licznik]=tmp;
                licznik++;
            }
            int wygral=Sprawdz_czy_wygrana(tmp);
            if(wygral!=0){//jezeli danych ruch jest wygrywajacy
                for(int k=0;k<licznik;k++){
                    for(int l=0;l<dowypisania->Wysokosc;l++){
                        delete [] Zbior_mozliwosci[k]->pola[l];
                    }
                    delete [] Zbior_mozliwosci[k]->pola;
                    delete Zbior_mozliwosci[k];
                }
                delete [] Zbior_mozliwosci;
                return wygral;
            }
            else if(ile==0){//jezeli plansza jest zapelniona i nie ma wygranej
                for(int k=0;k<licznik;k++){
                    for(int l=0;l<dowypisania->Wysokosc;l++){
                        delete [] Zbior_mozliwosci[k]->pola[l];
                    }
                    delete [] Zbior_mozliwosci[k]->pola;
                    delete Zbior_mozliwosci[k];
                }
                delete [] Zbior_mozliwosci;
                return 0;//TIE
            }
        }
    }
    for(int i=0;i<licznik;i++){//zmiana kolejnosci posuniec
        if(dowypisania->Active_Player==1){
            Zbior_mozliwosci[i]->Active_Player=2;
        }
        else{
            Zbior_mozliwosci[i]->Active_Player=1;
        }
    }
    //MINIMAX
    int* tab_wynikow= new int[ile];
    for(int i=0;i<licznik;i++){
        tab_wynikow[i]= Rozwiaz_stan(Zbior_mozliwosci[i]);
        if(dowypisania->Active_Player==1 && tab_wynikow[i]==1){
            for(int j=0;j<ile;j++){
                for(int l=0;l<dowypisania->Wysokosc;l++){
                    delete [] Zbior_mozliwosci[j]->pola[l];
                }
                delete [] Zbior_mozliwosci[j]->pola;
                delete Zbior_mozliwosci[j];
            }
            delete [] Zbior_mozliwosci;
            delete [] tab_wynikow;
            return 1;//wybierz wygrana dla 1 gracza, nie szukaj dalej
        }
        else if(dowypisania->Active_Player==2 && tab_wynikow[i]==2){
            for(int j=0;j<ile;j++){
                for(int l=0;l<dowypisania->Wysokosc;l++){
                    delete [] Zbior_mozliwosci[j]->pola[l];
                }
                delete [] Zbior_mozliwosci[j]->pola;
                delete Zbior_mozliwosci[j];
            }
            delete [] Zbior_mozliwosci;
            delete [] tab_wynikow;
            return 2; //wybierz wygrana dla 2 gracza, nie szukaj dalej
        }
    }
    for(int j=0;j<ile;j++){
        for(int l=0;l<dowypisania->Wysokosc;l++){
            delete [] Zbior_mozliwosci[j]->pola[l];
        }
        delete [] Zbior_mozliwosci[j]->pola;
        delete Zbior_mozliwosci[j];
    }
    delete [] Zbior_mozliwosci;
    for(int i=0;i<licznik;i++){//wybierz remis
        if(dowypisania->Active_Player==1 && tab_wynikow[i]==0){
            delete [] tab_wynikow;
            return 0;
        }
        else if(dowypisania->Active_Player==2 && tab_wynikow[i]==0){
            delete [] tab_wynikow;
            return 0;
        }
    }
    if(dowypisania->Active_Player==1){//jesli nie ma wygranej ani remisu wybierz przegrana
        delete [] tab_wynikow;
        return 2;
    }
    delete [] tab_wynikow;
    return 1;
}

void Przemiel_wyniki(int kto_wygral){
    switch(kto_wygral){
        case 0:
            printf("BOTH_PLAYERS_TIE\n");
            break;
        case 1:
            printf("FIRST_PLAYER_WINS\n");
            break;
        case 2:
            printf("SECOND_PLAYER_WINS\n");
            break;
        default:
            printf("cos sie zepsulo\n");
            break;
    }
}

void Zadanie_1_2_3(int numer_zad){
    int n,m,k,ap;
    cin >> n >> m >> k >> ap;
    plansza* tablica=new plansza;
    tablica->Szerokosc=m;
    tablica->Wysokosc=n;
    tablica->Ile_kolo_sie=k;
    tablica->Active_Player=ap;
    tablica->pola=new char*[n];
    for(int i=0;i<n;i++){
        tablica->pola[i]=new char [m];
    }
    for(int i=0;i<tablica->Wysokosc;i++){
        for(int j=0;j<tablica->Szerokosc;j++){
            char wartosc='0';
            cin >> wartosc;
            tablica->pola[i][j]=wartosc;
        }
    }
    int kto_wygral= Sprawdz_czy_wygrana(tablica);
    if(Ilosc_Mozliwych_Ruchow(tablica)!=0&& kto_wygral==0){
        if(numer_zad==1){
            Generuj_Wypisz(tablica);
        }
        else if(numer_zad==2){
            Generuj_do_wygranej(tablica);
        }
        else if(numer_zad==3){
            Przemiel_wyniki(Rozwiaz_stan(tablica));
        }
    }
    else if(numer_zad==3){
        Przemiel_wyniki(kto_wygral);
    }
    else{
        cout<<"0"<<endl;
    }
    for(int i=0;i<n;i++){
        delete [] tablica->pola[i];
    }
    delete [] tablica->pola;
    delete tablica;
}

void Zczytaj_input(){
    char komenda[DLUGOSC_KOMENDY]="";
    while(cin>>komenda){
        if(strcmp(komenda,"GEN_ALL_POS_MOV")==0){
            Zadanie_1_2_3(1);
        }
        else if (strcmp(komenda,"GEN_ALL_POS_MOV_CUT_IF_GAME_OVER")==0){
            Zadanie_1_2_3(2);
        }
        else if(strcmp(komenda,"SOLVE_GAME_STATE")==0){
            Zadanie_1_2_3(3);
        }
    }
}

int main() {
    Zczytaj_input();
    return 1;
}