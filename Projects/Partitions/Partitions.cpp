#include <iostream>
#define ZAMALO 0
#define PASUJE 1
#define ZADUZO 2
using namespace std;

bool Sprawdz_czy_pierwsza(const int n){
        if (n==2||n==3||n==5||n==7||n==0){
            return true;
        }
        else if (n%2==0||n%3==0||n==1){
            return false;
        }
        else for (int j=5;(j*j)<=n;j=j+6){
            if (n%j==0||n%j+2==0){
                return false;
            }
        }
    return true;
}
int Suma_tablicy(const int tablica[],int dlugosc){
    int suma=0;
    for (int i=0;i<dlugosc;i++){
        suma=suma+tablica[i];
    }
    return suma;
}
void zeruj_tablice(int *tab, int dlugosc, int zachowaj){
    if (zachowaj==0) return;
    for (int i=zachowaj;i<dlugosc;i++){
        tab[i]=0;
    }
}

void drukuj(int *tab, int dlugosc,int limitpierwszej){
    cout<<limitpierwszej<<"+";
    for(int i=0;i<dlugosc;i++){
        if(i!=dlugosc-1){
            if(tab[i+1]==0){
                cout<<tab[i]<<endl;
                return;
            }
            else cout<<tab[i]<<"+";
        }
        else cout<<tab[i]<<endl;
    }
}

int Znajdz_pozycje(const int *tab, const int dlugosc, int pozycja){
    int szukana=tab[pozycja];
    for(int indeks=0;indeks<dlugosc;indeks++){
        if(tab[indeks]==szukana) return indeks;
    }
    return 0;//nie powinien byc uzywany ten return
}

int Zwieksz(int *tab,int pozycja,int *obecnasuma,const int dlugosc,const int Suma,const int limitpierwszej) {//zwieksza czynnik na danej pozycji do kolejnej liczby pierwszej
        if(tab[pozycja]>4){
            tab[pozycja]=tab[pozycja]+2;
            obecnasuma[0]=obecnasuma[0]+2;
        }
        else{
            tab[pozycja]++;
            obecnasuma[0]++;
        }
        if(Sprawdz_czy_pierwsza(tab[pozycja])&&(tab[pozycja]<=limitpierwszej)){
            if(obecnasuma[0]==Suma){
                drukuj(tab,dlugosc,limitpierwszej);
                int indeks=Znajdz_pozycje(tab,dlugosc,pozycja);
                zeruj_tablice(tab,dlugosc,indeks+1);
                obecnasuma[0]= Suma_tablicy(tab,dlugosc);
                return indeks;
            }
            else if(obecnasuma[0]>Suma||(pozycja==dlugosc-1)){
                int indeks=Znajdz_pozycje(tab,dlugosc,pozycja);
                zeruj_tablice(tab,dlugosc,indeks+1);
                obecnasuma[0]= Suma_tablicy(tab,dlugosc);
                return indeks;
            }

            else if (pozycja!=dlugosc-1){
                return pozycja+1;
            }
        }
        return pozycja;
}

int main() {
    int j;
    cin >> j;
    for (int i=0;i<j;i++){
        int rozkladana, najwieksza;
        cin>>rozkladana>>najwieksza;
        if(Sprawdz_czy_pierwsza(najwieksza)){
            if(rozkladana==najwieksza){
                cout<<najwieksza<<endl;
            }
            else{
                int Suma=rozkladana-najwieksza;
                int miejsce=(Suma+1)/2;
                int* tab= new int[miejsce];
                for(int h=0;h<miejsce;h++){
                    tab[h]=0;
                }
                int indeks=0;
                int obecnasuma[1];
                obecnasuma[0]=0;
                while(tab[0]<=najwieksza){
                    indeks=Zwieksz(tab,indeks,obecnasuma,miejsce,Suma,najwieksza);
                }
                delete[] tab;
            }
        }
    }
    return 0;
}