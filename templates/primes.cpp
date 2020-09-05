#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

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
