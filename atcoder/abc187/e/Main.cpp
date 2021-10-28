/*
[abc187] E - Through Path
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
const int MAX_Q = 2e5;

int N;
int a[MAX_N - 1], b[MAX_N - 1];
int Q;
int t[MAX_Q], e[MAX_Q], x[MAX_Q];
vector<int> g[MAX_N];
int dep[MAX_N];
ll s[MAX_N];

void solve() {
    REP(i, N - 1) {
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    memset(dep, -1, sizeof(dep));
    vector<int> q = {0};
    dep[0] = 0;
    while (!q.empty()) {
        int v = q.back();
        q.pop_back();
        for (int to : g[v]) {
            if (dep[to] == -1) {
                dep[to] = dep[v] + 1;
                q.push_back(to);
            }
        }
    }

    REP(q, Q) {
        int v1 = a[e[q]], v2 = b[e[q]];
        if (t[q] == 2) swap(v1, v2);
        if (dep[v1] > dep[v2]) {
            s[v1] += x[q];
        } else {
            s[0] += x[q];
            s[v2] -= x[q];
        }
    }
    q = {0};
    while (!q.empty()) {
        int v = q.back();
        q.pop_back();
        for (int to : g[v]) {
            if (dep[to] > dep[v]) {
                s[to] += s[v];
                q.push_back(to);
            }
        }
    }

    REP(i, N) cout << s[i] << endl;
}

int main() {
    cin >> N;
    REP(i, N - 1) cin >> a[i] >> b[i], a[i]--, b[i]--;
    cin >> Q;
    REP(i, Q) cin >> t[i] >> e[i] >> x[i], e[i]--;

    solve();

    return 0;
}
