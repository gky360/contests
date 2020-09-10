/*
[abc152] E - Flatten
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e4;
const int MAX_P = 1e3;
const int MOD = 1e9 + 7;

class gf {
public:
    int n;
    gf() : n(0) {}
    gf(int n) : n(n < 0 ? n % MOD + MOD : n % MOD) {}
    gf operator+(gf x) { return gf((n + x.n) % MOD); }
    gf operator-(gf x) { return gf((n - x.n + MOD) % MOD); }
    gf operator*(gf x) { return gf((1LL * n * x.n) % MOD); }
    gf& operator+=(gf x) { return *this = (*this + x); }
    gf& operator-=(gf x) { return *this = (*this - x); }
    gf& operator*=(gf x) { return *this = (*this * x); }
};

int N;
int A[MAX_N];

vector<int> eratos(int n) {
    vector<int> prm;
    vector<bool> p(n + 1, true);

    for (int i = 2; i <= n; i++) {
        if (!p[i]) continue;
        prm.push_back(i);
        for (int j = 2 * i; j <= n; j += i) {
            p[j] = false;
        }
    }
    return prm;
}

map<int, int> factorize(ll n, vector<int>& prm) {
    map<int, int> ret;
    for (int p : prm) {
        if (1LL * p * p > n) break;
        while (n % p == 0) {
            ret[p]++;
            n /= p;
        }
    }
    if (n > 1) ret[n] = 1;

    return ret;
}

gf mod_pow(gf a, ll n) {
    gf ret = 1;
    for (; n > 0; n >>= 1) {
        if (n & 1) {
            ret *= a;
        }
        a *= a;
    }
    return ret;
}

ll solve() {
    vector<int> primes = eratos(MAX_P);
    map<int, int> f[MAX_N];
    for (int i = 0; i < N; i++) {
        f[i] = factorize(A[i], primes);
    }

    map<int, int> mf;
    for (int i = 0; i < N; i++) {
        for (auto p : f[i]) {
            int n = p.first, k = p.second;
            mf[n] = max(mf[n], k);
        }
    }

    gf l = 1;
    for (auto p : mf) {
        int n = p.first, k = p.second;
        l *= mod_pow(n, k);
    }

    gf ans = 0;
    for (int i = 0; i < N; i++) {
        ans += l * mod_pow(A[i], MOD - 2);
    }

    return ans.n;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
