// AtCoder Grand Contest 016
// D - XOR Replace

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_N = 100000;

int N;
ll ab[2][MAX_N + 1];
multiset<ll> ms;
map<ll, vector<ll>> G;
map<ll, bool> visited;

void dfs(int v) {
    if (visited[v]) {
        return;
    }
    visited[v] = true;
    for (ll to : G[v]) {
        dfs(to);
    }
}

int main() {

    ll x;
    int ans;

    cin >> N;
    for (int j = 0; j < 2; j++) {
        x = 0;
        for (int i = 0; i < N; i++) {
            cin >> ab[j][i];
            x = x ^ ab[j][i];
        }
        ab[j][N] = x;
    }

    for (int i = 0; i <= N; i++) {
        ms.insert(ab[0][i]);
    }
    for (int i = 0; i <= N; i++) {
        auto itr = ms.find(ab[1][i]);
        if (itr == ms.end()) {
            cout << -1 << endl;
            return 0;
        }
        ms.erase(itr);
    }

    ans = 0;
    for (int i = 0; i <= N; i++) {
        if (i != N && ab[0][i] == ab[1][i]) {
            continue;
        }
        ans++;
        G[ab[0][i]].push_back(ab[1][i]);
    }

    for (auto &kv : G) {
        ll v = kv.first;
        if (visited[v]) {
            continue;
        }
        ans++;
        dfs(v);
    }
    ans = max(0, ans - 2);
    cout << ans << endl;

    return 0;

}



