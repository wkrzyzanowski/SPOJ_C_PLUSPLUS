#include <iostream>

using namespace std;


bool czyZwrotna(int macierz[][100], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        if (macierz[i][i] == 0) {
            return false;
        }
    }
    return true;
}

bool czyPrzeciwZwrotna(int macierz[][100], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        if (macierz[i][i] == 1) {
            return false;
        }
    }
    return true;
}

bool czySymetryczna(int macierz[][100], int rozmiar) {
    int transponowana[rozmiar][rozmiar];

    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < rozmiar; j++) {
            transponowana[j][i] = macierz[i][j];
        }
    }

    /*cout << "\n\nTransponowana: " << endl;
    for (int k = 0; k < rozmiar; k++) {
        for (int i = 0; i < rozmiar; i++) {
            cout << transponowana[k][i] << " ";
        }
        cout << endl;
    }*/


    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < rozmiar; j++) {
            if (macierz[i][j] != transponowana[i][j]) {
                return false;
            }
        }
    }

    return true;
}

bool czyAntysymetryczna(int macierz[][100], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < rozmiar; j++) {
            if (i != j) {
                if (macierz[i][j] == 1 & macierz[j][i] == 1) {
                    return false;
                }
            }
        }
    }

    return true;
}

bool czyPrzechodnia(int macierz[][100], int rozmiar) {
    int tmp[rozmiar][rozmiar];

    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < rozmiar; j++) {
            tmp[i][j] = 0;
        }
    }

    int obliczenie;
    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < rozmiar; j++) {
            obliczenie = 0;
            for (int l = 0; l < rozmiar; l++) {
                obliczenie += macierz[i][l] * macierz[l][j];
            }
            tmp[i][j] = obliczenie;
        }
    }

    /*cout << "\n\nMnozona: " << endl;
    for (int k = 0; k < rozmiar; k++) {
        for (int i = 0; i < rozmiar; i++) {
            cout << tmp[k][i] << " ";
        }
        cout << endl;
    }*/


    for (int m = 0; m < rozmiar; m++) {
        for (int i = 0; i < rozmiar; i++) {
            if (macierz[m][i] == 0 & tmp[m][i] >= 1) {
                return false;
            }
        }
    }

    return true;
}


bool czySpojna(int macierz[][100], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < rozmiar; j++) {
            if (i != j) {
                if (macierz[i][j] == 0 & macierz[j][i] == 0) {
                    return false;
                }
            }
        }
    }
    return true;
}


bool czyRownowaznosci(bool zwrotnosc, bool symetrycznosc, bool przechodniosc) {
    return zwrotnosc & symetrycznosc & przechodniosc;
}

bool czyPorzadekCzesciowy(bool zwrotnosc, bool antysymetria, bool przechodniosc) {
    return zwrotnosc & antysymetria & przechodniosc;
}

bool czyPozadekLiniowy(bool porzadekCzesciowy, bool spojnosc) {
    return porzadekCzesciowy & spojnosc;
}


int RELACJA() {


    bool zwrotna;
    bool przeciwzwrotna;
    bool symetria;
    bool antysymetria;
    bool przechodniosc;
    bool spojnosc;


    bool rownowazosci;
    bool porzadku_liniowego;
    bool porzadku_czesciowego;


    int macierz[100][100];

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            macierz[i][j] = 0;
        }
    }

    // tutaj zmien input
    int iteracje = 0;
    int najwiekszaLiczba = 0;
    while (iteracje < 100) {

        int lewa;
        cin >> lewa;
        int prawa;
        cin >> prawa;
        macierz[lewa - 1][prawa - 1] = 1;
        if (lewa > najwiekszaLiczba || prawa > najwiekszaLiczba) {
            if (lewa > prawa) {
                najwiekszaLiczba = lewa;
            } else {
                najwiekszaLiczba = prawa;
            }
        }
        iteracje++;
    }

    //cout << "NAJWIEKSZA LICZBA:  " << najwiekszaLiczba << endl;

    //DRUKUJ MACIERZ
    /*cout << "\n\nWejsciowa: " << endl;
    for (int k = 0; k < najwiekszaLiczba; k++) {
        for (int i = 0; i < najwiekszaLiczba; i++) {
            cout << macierz[k][i] << " ";
        }
        cout << endl;
    }*/

    string odpowiedz_gora = "";


    zwrotna = czyZwrotna(macierz, najwiekszaLiczba);
    //cout << "ZW: " << zwrotna << endl;
    if (zwrotna) {
        odpowiedz_gora += " Z ";
        cout << "Z ";
    }

    przeciwzwrotna = czyPrzeciwZwrotna(macierz, najwiekszaLiczba);
    //cout << "PZ: " << przeciwzwrotna << endl;
    if (przeciwzwrotna) {
        odpowiedz_gora += " PZ ";
        cout << "PZ ";
    }

    symetria = czySymetryczna(macierz, najwiekszaLiczba);
    //cout << "S: " << symetria << endl;
    if (symetria) {
        odpowiedz_gora += " S ";
        cout << "S ";
    }

    antysymetria = czyAntysymetryczna(macierz, najwiekszaLiczba);
    //cout << "AS: " << antysymetria << endl;
    if (antysymetria) {
        odpowiedz_gora += " AS ";
        cout << "AS ";
    }

    przechodniosc = czyPrzechodnia(macierz, najwiekszaLiczba);
    //cout << "P: " << przechodniosc << endl;
    if (przechodniosc) {
        odpowiedz_gora += " P ";
        cout << "P ";
    }

    spojnosc = czySpojna(macierz, najwiekszaLiczba);
    //cout << "SP: " << spojnosc << endl;
    if (spojnosc) {
        odpowiedz_gora += " SP ";
        cout << "SP";
    }

    if (odpowiedz_gora == "") {
        //odpowiedz_gora += "X";
        cout << "X";
        return 0;
    }

    cout << "\n";


    string odpowiedz_dol = "";

    rownowazosci = czyRownowaznosci(zwrotna, symetria, przechodniosc);
    porzadku_czesciowego = czyPorzadekCzesciowy(zwrotna, antysymetria, przechodniosc);
    porzadku_liniowego = czyPozadekLiniowy(porzadku_czesciowego, spojnosc);


    //cout << "RR: " << rownowazosci << endl;
    if (rownowazosci) {
        odpowiedz_dol += " RR ";
        cout << "RR ";
    }
    //cout << "RPL: " << porzadku_liniowego << endl;
    if (porzadku_liniowego) {
        odpowiedz_dol += " RPL ";
        cout << "RPL ";
    }

    //cout << "RPCz: " << porzadku_czesciowego << endl;
    if (porzadku_czesciowego & !porzadku_liniowego) {
        odpowiedz_dol += " RPCz ";
        cout << "RPCz ";
    }

    if (odpowiedz_dol == "") {
        odpowiedz_dol += "X";
        cout << "X";
    }

    cout << "\n";


    //cout << odpowiedz_gora << endl;
    //cout << odpowiedz_dol << endl;


    return 0;
}



