/*
[abc137] F - Polynomial Construction
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_P = 2999;
int MOD;

class gf {
public:
    int n;
    gf() : n(0) {}
    gf(int n) : n(n % MOD) {}
    gf operator+(const gf x) const { return gf((n + x.n) % MOD); }
    gf operator-(const gf x) const { return gf((n - x.n + MOD) % MOD); }
    gf operator*(const gf x) const { return gf((1LL * n * x.n) % MOD); }
    gf& operator+=(const gf x) { return *this = (*this + x); }
    gf& operator-=(const gf x) { return *this = (*this - x); }
    gf& operator*=(const gf x) { return *this = (*this * x); }
};

int p;
int a[MAX_P];
gf c[MAX_P];
gf b[MAX_P];

void solve() {
    c[0] = 1;
    for (int i = 1; i <= p - 1; i++) {
        for (int j = i; j > 0; j--) {
            c[j] += c[j - 1];
        }
    }

    for (int i = 0; i < p; i++) {
        if (a[i] == 0) {
            continue;
        }
        b[0] += 1;
        gf pi = 1;
        for (int j = p - 1; j >= 0; j--) {
            b[j] -= c[j] * pi;
            pi *= -i;
        }
    }

    for (int i = 0; i < p; i++) {
        cout << b[i].n << " ";
    }
    cout << endl;
}

int main() {
    cin >> p;
    MOD = p;
    for (int i = 0; i < p; i++) {
        cin >> a[i];
    }

    solve();

    return 0;
}
