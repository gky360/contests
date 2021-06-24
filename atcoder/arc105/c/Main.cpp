/*
[arc105] C - Camels and Bridge
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

const int MAX_N = 8;
const int MAX_M = 1e5;
const ll INF = 1e18;

int N, M;
vector<pli> wi;
pll vl[MAX_M];
ll ml[MAX_M + 1];

ll calc() {
    ll s[MAX_N + 1];
    ll d[MAX_N][MAX_N];

    s[0] = 0;
    REP(i, N) s[i + 1] = s[i] + wi[i].first;
    REP(i, N) {
        for (int j = i; j < N; j++) {
            int x = lower_bound(vl, vl + M, pll(s[j + 1] - s[i], 0)) - vl;
            d[i][j] = ml[x];
        }
    }

    ll l[MAX_N];
    l[0] = 0;
    REP(j, N) {
        l[j] = 0;
        for (int i = 0; i < j; i++) {
            l[j] = max(l[j], l[i] + d[i][j]);
        }
    }

    return l[N - 1];
}

ll solve() {
    ll max_w = 0;
    REP(i, N) max_w = max(max_w, wi[i].first);

    sort(vl, vl + M);
    ll min_v = INF;
    REP(i, M) {
        ml[i + 1] = max(ml[i], vl[i].second);
        min_v = min(min_v, vl[i].first);
    }

    if (max_w > min_v) return -1;

    ll ans = INF;
    do {
        ans = min(ans, calc());
    } while (next_permutation(ALL(wi)));
    return ans;
}

int main() {
    cin >> N >> M;
    wi.resize(N);
    REP(i, N) cin >> wi[i].first, wi[i].second = i;
    REP(j, M) cin >> vl[j].second >> vl[j].first;

    cout << solve() << endl;

    return 0;
}
