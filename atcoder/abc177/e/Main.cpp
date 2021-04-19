/*
[abc177] E - Coprime
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

const int MAX_N = 1e6;
const int MAX_A = 1e6;

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

ll gcd(ll a, ll b) {
    while (b > 0) {
        swap(b, a %= b);
    }
    return a;
}

bool is_pw() {
    set<int> s;
    auto prms = eratos(MAX_A);
    REP(i, N) {
        auto f = factorize(A[i], prms);
        for (auto [p, x] : f) {
            if (s.count(p) > 0) return false;
            s.insert(p);
        }
    }
    return true;
}

bool is_sw() {
    ll g = A[0];
    REP(i, N) g = gcd(g, A[i]);
    return g == 1;
}

void solve() {
    if (is_pw()) {
        cout << "pairwise coprime" << endl;
    } else if (is_sw()) {
        cout << "setwise coprime" << endl;
    } else {
        cout << "not coprime" << endl;
    }
}

int main() {
    cin >> N;
    REP(i, N) cin >> A[i];

    solve();

    return 0;
}
