/*
[agc039] C - Division by Two with Something
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MOD = 998244353;

class gf {
public:
    int n;
    gf() : n(0) {}
    gf(int n) : n(n % MOD) {}
    gf operator+(gf x) { return gf((n + x.n) % MOD); }
    gf operator-(gf x) { return gf((n - x.n + MOD) % MOD); }
    gf operator*(gf x) { return gf((1LL * n * x.n) % MOD); }
    gf& operator+=(gf x) { return *this = (*this + x); }
    gf& operator-=(gf x) { return *this = (*this - x); }
    gf& operator*=(gf x) { return *this = (*this * x); }
};

int N;
string X;

gf calc(int l) {
    gf cnt = 0;
    for (int i = 0; i < l; i++) {
        cnt = cnt * 2 + (X[i] - '0');
    }
    string y = X;
    for (int i = l; i < N; i++) {
        y[i] = y[i - l] ^ 1;
    }
    if (y <= X) {
        cnt += 1;
    }

    return cnt;
}

ll solve() {
    vector<int> ls;
    for (int i = 1; i <= N; i++) {
        if (N % i == 0 && (N / i) % 2 == 1) {
            ls.push_back(i);
        }
    }

    vector<gf> coeffs(ls.size());
    for (int i = (int)ls.size() - 1; i >= 0; i--) {
        coeffs[i] = 2 * ls[i];
        for (int j = i + 1; j < (int)ls.size(); j++) {
            if (ls[j] % ls[i] == 0 && (ls[j] / ls[i]) % 2 == 1) {
                coeffs[i] -= coeffs[j];
            }
        }
    }

    gf ans = 0;
    for (int i = 0; i < (int)ls.size(); i++) {
        ans += calc(ls[i]) * coeffs[i];
    }

    return ans.n;
}

int main() {
    cin >> N;
    cin >> X;

    cout << solve() << endl;

    return 0;
}
