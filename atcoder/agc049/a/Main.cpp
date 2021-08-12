/*
[agc049] A - Erasing Vertices
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

const int MAX_N = 100;

int N;
string S[MAX_N];
bool visited[MAX_N];
int cnt[MAX_N];

int dfs(int v) {
    if (visited[v]) return 0;
    visited[v] = true;
    int ret = 1;
    REP(to, N) {
        if (S[to][v] == '1') ret += dfs(to);
    }
    return ret;
}

double solve() {
    REP(i, N) {
        memset(visited, false, sizeof(visited));
        cnt[i] = dfs(i);
    }
    double ans = 0;
    REP(i, N) ans += 1.0 / cnt[i];
    return ans;
}

int main() {
    cin >> N;
    REP(i, N) cin >> S[i];

    cout << fixed << setprecision(20) << solve() << endl;

    return 0;
}
