// Lucky numbers contain 4 and 7
// Nearly lucky if the number of lucky digits in a number is lucky


#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {

    string n;
    cin >> n;


    int count = 0;

    for (auto it = n.begin(); it != n.end(); ++it) {
        char c = (*it);
        if (c == '4' || c == '7') {
            ++count;
        }
    }

    stringstream ss;
    ss << count;
    string cs = ss.str();

    for (auto it = cs.begin(); it != cs.end(); ++it) {
        char c = (*it);
        if (c != '4' && c != '7') {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}

