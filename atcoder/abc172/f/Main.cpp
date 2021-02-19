/*
[abc172] F - Unfair Nim
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

const int MAX_N = 300;
const ll INF = 1e17;

int N;
ll A[MAX_N];
map<tuple<ll, ll, ll>, ll> m;

ll f(ll a, ll b, ll c) {
    auto args = tuple(a, b, c);
    if (m.count(tuple(a, b, c))) return m[args];
    if (((a ^ b) & 1) != (c & 1)) return m[args] = INF;
    if (c == 0) return a < b ? INF : (a - b) / 2;
    return m[args] = min(INF, min(f(a / 2, b / 2, c / 2) * 2,
                                  f((a - 1) / 2, (b + 1) / 2, c / 2) * 2 + 1));
}

ll solve() {
    ll x = 0;
    for (int i = 2; i < N; i++) x ^= A[i];
    ll ans = f(A[0], A[1], x);
    return ans == INF || ans >= A[0] ? -1 : ans;
}

int main() {
    cin >> N;
    REP(i, N) cin >> A[i];

    cout << solve() << endl;

    return 0;
}
