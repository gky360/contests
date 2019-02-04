// gcd.cpp
#include <algorithm>
using namespace std;
typedef long long int ll;

int gcd(int a, int b) {
    while (b > 0) {
        swap(b, a %= b);
    }
    return a;
}

ll lcm(int a, int b) {
    int d = gcd(a, b);
    return (ll)a * b / d;
}

int extgcd(int a, int b, int& x, int& y) {
    int d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

int mod_inv(int a, int m) {
    int x, y;
    extgcd(a, m, x, y);
    return (m + x) % m;
}

int main() { return 0; }
