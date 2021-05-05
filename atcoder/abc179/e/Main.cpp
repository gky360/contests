/*
[abc179] E - Sequence Sum
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

const int MAX_M = 1e5;

ll N, X, M;

ll f[MAX_M];
ll s[MAX_M + 2];
int visited[MAX_M];

ll solve() {
    REP(i, M) f[i] = 1LL * i * i % M;

    s[0] = 0;
    memset(visited, -1, sizeof(visited));
    ll v = X;
    REP(i, M + 1) {
        if (visited[v] != -1) {
            int t = visited[v], l = i - visited[v];
            ll ss = s[i] - s[t];
            ll ans = ss * ((N - t) / l) + s[(N - t) % l + t];
            return ans;
        }
        visited[v] = i;
        s[i + 1] = s[i] + v;
        v = f[v];
    }

    return -1;
}

int main() {
    cin >> N >> X >> M;
    cout << solve() << endl;

    return 0;
}
