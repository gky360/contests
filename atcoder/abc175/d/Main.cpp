/*
[abc175] D - Moving Piece
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

const int MAX_N = 5000;
const ll INF = 1e18;

int N;
ll K;
int P[MAX_N];
ll C[MAX_N];

ll solve() {
    ll ans = -INF;
    REP(n, N) {
        ll cs = 0;
        int cc = 0;
        for (int v = n; true;) {
            cc++;
            cs += C[v];
            v = P[v];
            if (v == n) break;
        }

        ll path = 0;
        int cnt = 0;
        for (int v = n; true;) {
            cnt++;
            path += C[v];
            if (cnt > K) break;

            ll r = (K - cnt) / cc;
            ll ret = path + max(0ll, cs) * r;
            ans = max(ans, ret);

            v = P[v];
            if (v == n) break;
        }
    };
    return ans;
}

int main() {
    cin >> N >> K;
    REP(i, N) cin >> P[i], P[i]--;
    REP(i, N) cin >> C[i];

    cout << solve() << endl;

    return 0;
}
