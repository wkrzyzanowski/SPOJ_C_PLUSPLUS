#include <iostream>
using namespace std;

int TRN_Start() {

    int m, n;
    int input;
    cin >> m >> n;
    int matrix[m][n];

    for (int i = 0; i < m; i++) {
        if (m < 1 || m > 200 || n < 1 || n > 200)
            break;
        for (int j = 0; j < n; j++) {
            cin >> input;
            matrix[i][j] = input;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}