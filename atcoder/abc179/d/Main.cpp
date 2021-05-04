/*
[abc179] D - Leaping Tak
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double DD;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 2e5;
const int MAX_K = 10;
const int MOD = 998244353;

class gf {
public:
    int n;
    gf() : n(0) {}
    gf(ll n) : n(n < 0 ? n % MOD + MOD : n % MOD) {}
    gf operator+(gf x) { return gf((n + x.n) % MOD); }
    gf operator-(gf x) { return gf((n - x.n + MOD) % MOD); }
    gf operator*(gf x) { return gf((1LL * n * x.n) % MOD); }
    gf& operator+=(gf x) { return *this = (*this + x); }
    gf& operator-=(gf x) { return *this = (*this - x); }
    gf& operator*=(gf x) { return *this = (*this * x); }
};

int N, K;
int L[MAX_K], R[MAX_K];

ll solve() {
    gf s[MAX_N + 1];
    s[1] = 1;

    for (int i = 1; i < N; i++) {
        s[i + 1] = s[i];
        REP(j, K) { s[i + 1] += s[max(0, i - L[j] + 1)] - s[max(0, i - R[j])]; }
    }

    ll ans = (s[N] - s[N - 1]).n;
    return ans;
}

int main() {
    cin >> N >> K;
    REP(i, K) cin >> L[i] >> R[i];

    cout << solve() << endl;

    return 0;
}
