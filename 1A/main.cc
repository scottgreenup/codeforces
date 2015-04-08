
#include <iostream>
#include <cmath>

int main() {

    unsigned long long n, m, a;
    std::cin >> n >> m >> a;

    unsigned long long size = n * m;
    unsigned long long pave = a * a;

    // how many to cover m
    // how many to cover n

    double coverN = ceil(n / (double)a);
    double coverM = ceil(m / (double)a);

    unsigned long long amount = (unsigned long long)(coverN * coverM);

    //int amount = (int)ceil(size / (double)pave);

    std::cout << amount << std::endl;

    return 0;
}
