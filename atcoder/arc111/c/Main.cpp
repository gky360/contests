/*
[arc111] C - Too Heavy
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

const int MAX_N = 200000;

int N;
pii a[MAX_N];
int b[MAX_N], p[MAX_N];
int pi[MAX_N];
vector<pii> ans;

void solve() {
    REP(i, N) pi[p[i]] = i;

    sort(a, a + N);

    REP(i, N) {
        int x = a[i].second, y = pi[x];
        if (p[x] == x) continue;
        if (a[i].first <= b[p[x]]) {
            cout << -1 << endl;
            return;
        }

        ans.push_back({x, y});
        swap(pi[p[x]], pi[p[y]]);
        assert(pi[p[x]] == y);
        assert(pi[p[y]] == x);
        swap(p[x], p[y]);
        assert(p[x] == x);
    }

    cout << ans.size() << endl;
    for (auto [x, y] : ans) cout << x + 1 << " " << y + 1 << endl;
}

int main() {
    cin >> N;
    REP(i, N) cin >> a[i].first, a[i].second = i;
    REP(i, N) cin >> b[i];
    REP(i, N) cin >> p[i], p[i]--;

    solve();

    return 0;
}
