#include <iostream>


using namespace std;

void start() {
    double **macierz;
    double **transponowana;
    double *wektor;

    int ileKolumn;
    int ileWierszy;


    cin >> ileKolumn;
    cin >> ileWierszy;

    macierz = new double *[ileWierszy];
    transponowana = new double *[ileKolumn];
    for (int i = 0; i < ileWierszy; ++i) {
        macierz[i] = new double[ileKolumn];
    }
    for (int i = 0; i < ileKolumn; ++i) {
        transponowana[i] = new double[ileWierszy];
    }
    wektor = new double[ileWierszy]{};

    for (int i = 0; i < ileWierszy; i++) {
        for (int j = 0; j < ileKolumn; j++) {
            cin >> macierz[i][j];
        }
        cin >> wektor[i];
    }

    /*cout << "Macierz:" << endl;
    for (int k = 0; k < ileWierszy; k++) {
        for (int i = 0; i < ileKolumn; i++) {
            printf("%.6f ", macierz[k][i]);
        }
        cout << "\n";
    }*/

    /*cout << "Wektor:" << endl;
    for (int k = 0; k < ileWierszy; k++) {
        printf("%.6f \n", wektor[k]);
    }*/


    for (int l = 0; l < ileKolumn; l++) {
        for (int i = 0; i < ileWierszy; i++) {
            transponowana[l][i] = macierz[i][l];
        }
    }

    /* cout << "Macierz transponowana:" << endl;
     for (int k = 0; k < ileKolumn; k++) {
         for (int i = 0; i < ileWierszy; i++) {
             printf("%.6f ", transponowana[k][i]);
         }
         cout << "\n";
     }*/

    double *wyniki = new double[ileKolumn];

    double obliczenie = 0;
    for (int i = 0; i < ileKolumn; i++) {
        obliczenie = 0;
        for (int j = 0; j < ileWierszy; j++) {
            obliczenie += transponowana[i][j] * wektor[j];
        }
        wyniki[i] = obliczenie;
    }

    for (int m = 0; m < ileKolumn; m++) {
        printf("%.7g", wyniki[m]);
        cout << " ";
    }

    //system("pause");
}

