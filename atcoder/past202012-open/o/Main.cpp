/*
[past202012-open] O - Notification
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
const int MAX_M = 2e5;
const int MAX_Q = 2e5;
const int R = 450;

int N, M;
int a[MAX_M], b[MAX_M];
int Q;
int T[MAX_Q], x[MAX_Q];
vector<int> g[MAX_N], gh[MAX_N];
ll rx[MAX_N], tx[MAX_N];
ll pre[MAX_N];

void solve() {
    REP(i, M) {
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    REP(i, N) {
        for (int v : g[i])
            if (g[v].size() >= R) gh[i].push_back(v);
    }
    REP(q, Q) {
        if (T[q] == 1) {
            if (g[x[q]].size() < R) {
                for (int v : g[x[q]]) rx[v]++;
            } else {
                tx[x[q]]++;
            }
        } else {
            ll ret = rx[x[q]];
            for (int v : gh[x[q]]) ret += tx[v];
            cout << ret - pre[x[q]] << endl;
            pre[x[q]] = ret;
        }
    }
}

int main() {
    cin >> N >> M;
    REP(i, M) cin >> a[i] >> b[i], a[i]--, b[i]--;
    cin >> Q;
    REP(q, Q) cin >> T[q] >> x[q], x[q]--;

    solve();

    return 0;
}
