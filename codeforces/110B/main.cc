

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int x = 0;

    for (int i = 0; i < n; i++) {
        switch(x) {
        case 0:
            cout << 'a';
            break;
        case 1:
            cout << 'b';
            break;
        case 2:
            cout << 'c';
            break;
        case 3:
            cout << 'd';
            break;
        }

        x++;

        if (x == 4) { x = 0; }
    }

    cout << endl;
    return 0;
}
