#include <iostream>
#include <deque>

using namespace std;

void start() {
    deque<int> kolejka;
    string input;


    while (cin >> input) {
        if (input == "Enqueue") {
            if (kolejka.size() < 10) {
                int tmp;
                cin >> tmp;
                kolejka.push_back(tmp);
                cout << "--->" << endl;
            } else {
                cout << "Error: queue is full" << endl;
            }
        } else if (input == "Dequeue") {
            if (!kolejka.empty()) {
                cout << kolejka.front() << endl;
                kolejka.pop_front();
            } else if (kolejka.empty()) {
                cout << "Error: queue is empty" << endl;
            }
        } else if (input == "Print") {
            if (!kolejka.empty()) {
                cout << "Print: ";
                for (int i : kolejka) {
                    cout << i << " ";
                }
                cout << "\n";
            } else if (kolejka.empty()) {
                cout << "Print: Queue is empty" << endl;
            }
        }
    }

}