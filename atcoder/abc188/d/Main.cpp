/*
[abc188] D - Snuke Prime
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
const int MAX_A = 1e9 + 1;
const int MAX_K = 2 * MAX_N + 2;

int N;
ll C;
ll a[MAX_N], b[MAX_N], c[MAX_N];
ll s[MAX_K];

ll solve() {
    vector<ll> xi = {0, MAX_A};
    REP(i, N) xi.push_back(a[i]), xi.push_back(b[i] + 1);
    sort(ALL(xi));
    xi.erase(unique(ALL(xi)), xi.end());
    REP(i, N) {
        int ai = lower_bound(ALL(xi), a[i]) - xi.begin();
        int bi = lower_bound(ALL(xi), b[i] + 1) - xi.begin();
        s[ai] += c[i];
        s[bi] -= c[i];
    }
    ll ans = 0;
    REP(i, xi.size() - 1) {
        s[i + 1] += s[i];
        ans += min(C, s[i]) * (xi[i + 1] - xi[i]);
    }

    return ans;
}

int main() {
    cin >> N >> C;
    REP(i, N) cin >> a[i] >> b[i] >> c[i];

    cout << solve() << endl;

    return 0;
}
