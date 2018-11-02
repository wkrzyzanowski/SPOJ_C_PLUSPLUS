#include <iostream>
using namespace std;

int RNO_DOD_Start() {

    int tests = 0;
    cin >> tests;
    for (int i = 0; i < tests; i++) {
        int numbers = 0;
        cin >> numbers;
        int result = 0;
        for (int j = 0; j < numbers; j++) {
            int input;
            cin >> input;
            result += input;
        }
        cout << result << endl;
    }

    return 0;
}