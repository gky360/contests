// gcd.cpp
#include <algorithm>
using namespace std;
typedef long long int ll;

ll gcd(ll a, ll b) {
    while (b > 0) {
        swap(b, a %= b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    ll d = gcd(a, b);
    return (ll)a * b / d;
}

ll extgcd(ll a, ll b, ll& x, ll& y) {
    ll d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

ll mod_inv(ll a, ll m) {
    ll x, y;
    extgcd(a, m, x, y);
    return (m + x) % m;
}

int main() { return 0; }
