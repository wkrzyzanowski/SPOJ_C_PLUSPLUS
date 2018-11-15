#include <iostream>
#include "math.h"

using namespace std;

unsigned long long macierze(int n) {
    unsigned long long q11, q12, q21, q22,
            p11, p12, p21, p22,
            w11, w12, w21, w22;

    if (n < 2) return n;


    q11 = q12 = q21 = 1;
    q22 = 0;


    w11 = w22 = 1;
    w12 = w21 = 0;

    n--;

    while (n) {
        if (n & 1) {


            p11 = w11 * q11 + w12 * q21;
            p12 = w11 * q12 + w12 * q22;
            p21 = w21 * q11 + w22 * q21;
            p22 = w21 * q12 + w22 * q22;


            w11 = p11 % 1000000007;
            w12 = p12 % 1000000007;
            w21 = p21 % 1000000007;
            w22 = p22 % 1000000007;

        }

        n >>= 1;

        if (!n) break;


        p11 = q11 * q11 + q12 * q21;
        p12 = q11 * q12 + q12 * q22;
        p21 = q21 * q11 + q22 * q21;
        p22 = q21 * q12 + q22 * q22;


        q11 = p11 % 1000000007;
        q12 = p12 % 1000000007;
        q21 = p21 % 1000000007;
        q22 = p22 % 1000000007;

    }

    return w11;
}

int FIBOMACIERZE() {

    int ile_razy;
    cin >> ile_razy;

    for (int i = 0; i < ile_razy; i++) {
        unsigned long long n;
        cin >> n;

        if (n < 2) {
            unsigned long long wynik = n % 1000000007;
            cout << wynik << endl;
        } else {

            unsigned long long wynik = macierze(n) % 1000000007;
            cout << wynik << endl;

        }
    }


    return 0;
}