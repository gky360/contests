/*
[abc119] D - Lazy Faith
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_A = 1e5;
const int MAX_B = 1e5;
const int MAX_Q = 1e5;
const ll INF = 1e18;

int A, B, Q;
ll s[MAX_A + 2], t[MAX_B + 2], x[MAX_Q];

ll solve_q(ll xq) {
    int a = upper_bound(s, s + A + 2, xq) - s;
    int b = upper_bound(t, t + B + 2, xq) - t;

    ll ans = INF;
    for (int pat = 0; pat < 4; pat++) {
        int pa = pat & 1, pb = (pat >> 1) & 1;
        ll la = abs(s[a - pa] - xq), lb = abs(t[b - pb] - xq);
        ll dist = (pa == pb) ? max(la, lb) : (min(la, lb) * 2 + max(la, lb));
        ans = min(ans, dist);
    }

    return ans;
}

void solve() {
    s[A] = -INF, s[A + 1] = INF;
    t[B] = -INF, t[B + 1] = INF;
    sort(s, s + A + 2);
    sort(t, t + B + 2);

    for (int i = 0; i < Q; i++) {
        cout << solve_q(x[i]) << endl;
    }
}

int main() {
    cin >> A >> B >> Q;
    for (int i = 0; i < A; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < B; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < Q; i++) {
        cin >> x[i];
    }

    solve();

    return 0;
}
