#include <iostream>

using namespace std;

int VSR_Start() {

    int t, input1, input2;
    int i = 1;
    cin >> t;
    while (i <= t) {
        if (t < 1 || t > 1000)
            break;
        cin >> input1 >> input2;

        if (input1 < 1 || input1 > 10000 || input2 < 1 || input2 > 10000)
            break;
        int wynik = (2 * input1 * input2) / (input1 + input2);
        cout << wynik << endl;
        i++;
    }
    return 0;


    return 0;
}