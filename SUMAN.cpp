#include <iostream>

using namespace std;

int SUMAN_Start() {

    int j, n, sum, i = 1;
    while (i <= 10) {
        cin >> n;
        sum = 0;
        if (n < 0 || n > 1000)
            break;
        for (j = 1; j <= n; j++) {
            sum = sum + j;
        }
        cout << sum << endl;
        i++;
    }

    return 0;
}