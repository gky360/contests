/*
[abc169] D - Div Game
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

const int MAX_P = 1e6;

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

ll N;

ll solve() {
    auto primes = eratos(MAX_P);
    auto facts = factorize(N, primes);

    ll ans = 0;
    for (auto& fact : facts) {
        int e = fact.second;
        REP(i, 12 + 1) {
            if (e < i * (i + 1) / 2) {
                ans += i - 1;
                break;
            }
        }
    }
    return ans;
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
