/*
[past202012-open] G - Snake
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

const int MAX_H = 4;

int H, W;
string S[MAX_H];
int N;
int dh[4] = {-1, 0, 1, 0}, dw[4] = {0, 1, 0, -1};

bool dfs(int p, int q, vector<vector<bool>> &visited, vector<pii> &ans) {
    if (p < 0 || H <= p || q < 0 || W <= q || visited[p][q] || S[p][q] == '.')
        return false;
    visited[p][q] = true;
    ans.push_back({p, q});
    if ((int)ans.size() == N) return true;
    REP(k, 4) {
        if (dfs(p + dh[k], q + dw[k], visited, ans)) return true;
    }
    ans.pop_back();
    visited[p][q] = false;
    return false;
}

void solve() {
    REP(i, H) REP(j, W) if (S[i][j] == '#') N++;
    REP(i, H) REP(j, W) {
        vector<vector<bool>> visited(H, vector<bool>(W));
        vector<pii> ans;
        if (dfs(i, j, visited, ans)) {
            cout << N << endl;
            for (auto [p, q] : ans) {
                cout << p + 1 << " " << q + 1 << endl;
            }
            return;
        }
    }
}

int main() {
    cin >> H >> W;
    REP(i, H) cin >> S[i];

    solve();

    return 0;
}
