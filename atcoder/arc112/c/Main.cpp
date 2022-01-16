/*
[arc112] C - DFS Game
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

const int MAX_N = 1e5;

int N;
int p[MAX_N];
int dp[MAX_N], sz[MAX_N];
vector<int> g[MAX_N];

void dfs(int v) {
    int sum = 0;
    vector<int> seq;
    dp[v] = 1;
    sz[v] = 1;
    for (int to : g[v]) {
        dfs(to);
        sz[v] += sz[to];
        if (sz[to] % 2 == 0) {
            if (dp[to] < 0) {
                dp[v] -= -dp[to];
            } else {
                sum += -dp[to];
            }
        } else {
            seq.push_back(-dp[to]);
        }
    }
    sort(ALL(seq), greater{});
    seq.push_back(sum);
    REP(i, seq.size()) dp[v] += (i % 2) ? seq[i] : -seq[i];
}

int solve() {
    for (int i = 1; i < N; i++) g[p[i]].push_back(i);
    dfs(0);
    int ans = (N + dp[0]) / 2;
    return ans;
}

int main() {
    cin >> N;
    for (int i = 1; i < N; i++) cin >> p[i], p[i]--;

    cout << solve() << endl;

    return 0;
}
