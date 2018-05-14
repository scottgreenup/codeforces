

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;


map<int,bool> solved;

int fours = 0;
int sevens = 0;

bool solve(int n) {
    if (solved.find(n) != solved.end()) {
        return solved[n];
    }

    if (n == 7) {
        sevens++;
        return true;
    }
    
    if (n == 4) {
        fours++;
        return true;
    }

    if (n < 7 && n != 4) {
        solved[n] = false;
        return false;
    }

    if (solve(n - 7)) {
        sevens++;
        return true;
    } else {
        solved[n] = false;
    }

    if (solve(n - 4)) {
        fours++;
        return true;
    } else {
        solved[n] = false;
    }

    return false;
}


int main() {
    int n;
    cin >> n;

    if (solve(n)) {
        for (int i = 0; i < fours; i++) {
            cout << "4";
        }
        for (int i = 0; i < sevens; i++) {
            cout << "7";
        }
        cout << endl;
    } else {

        cout << "-1" << endl;
    }

    
}
