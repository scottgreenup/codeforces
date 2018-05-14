// n candies of two types
// i-th candy hangs at h(i) centimetres with m(i) centimetres
// start at x centimetres for jumping
// mass increases jump height
// can't eat same candy twice

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Candy {
    int type;
    int height;
    int mass;
};

typedef vector<Candy> vv;

bool sorter(Candy a, Candy b) {
    return (a.height < b.height);
}

int main() {
    int n, x;
    cin >> n >> x;

    vv candies(n);

    for (auto it = candies.begin(); it != candies.end(); ++it) {
        cin >> it->type >> it->height >> it->mass;
    }

    sort(candies.begin(), candies.end(), sorter);

    for (auto it = candies.begin(); it != candies.end(); ++it) {
        cout << it->type << ", " << it->height << ", " << it->mass << endl;
    }



    return 0;
}

