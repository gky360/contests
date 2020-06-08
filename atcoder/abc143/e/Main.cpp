/*
[abc143] E - Travel by Car
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 300;
const int MAX_Q = MAX_N * (MAX_N - 1);
const ll INF = 1e17;

int N, M;
ll L;
int Q;
int s[MAX_Q], t[MAX_Q];
vector<vector<ll>> g;

void warshal_floyd(vector<vector<ll>> &d) {
    int n = d.size();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void solve() {
    warshal_floyd(g);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            g[i][j] = g[i][j] <= L ? 1 : INF;
        }
    }

    warshal_floyd(g);

    for (int i = 0; i < Q; i++) {
        ll d = g[s[i]][t[i]];
        ll ans = d >= INF ? -1 : d - 1;
        cout << ans << endl;
    }
}

int main() {
    cin >> N >> M >> L;
    g = vector<vector<ll>>(N, vector<ll>(N, INF));
    for (int i = 0; i < N; i++) {
        g[i][i] = 0;
    }

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        A--, B--;
        g[A][B] = g[B][A] = C;
    }

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> s[i] >> t[i];
        s[i]--, t[i]--;
    }

    solve();

    return 0;
}
