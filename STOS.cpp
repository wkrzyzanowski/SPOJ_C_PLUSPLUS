#include <iostream>
#include <deque>

using namespace std;

int STOS() {

    string input;
    int maxStosSize = 10;
    deque<string> stos;


    while (cin >> input) {


        if (input == "-") {
            if (!stos.empty()) {
                cout << stos.at(0) << endl;
                stos.erase(stos.begin());
            } else {
                cout << ":(" << endl;
            }
        }

        if (input == "+") {
            string nextItem;
            cin >> nextItem;
            if (stos.size() != maxStosSize) {
                cout << ":)" << endl;
                stos.push_front(nextItem);

            } else {
                cout << ":(" << endl;
            }
        }
    }

    return 0;
}
