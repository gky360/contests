// AtCoder Beginner Contest 070
// D - Transit Tree Path

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_N = 100000;

int N;
int Q, K;
vector<pli> G[MAX_N + 1];
ll d[MAX_N + 1];

void dfs(int v, ll dep = 0, int p = -1) {
    d[v] = dep;
    for (pli &e : G[v]) {
        if (e.second == p) {
            continue;
        }
        dfs(e.second, dep + e.first, v);
    }
}

int main() {

    int a, b, x, y;
    ll c;

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b >> c;
        G[a].push_back(pli(c, b));
        G[b].push_back(pli(c, a));
    }

    cin >> Q >> K;
    dfs(K);
    for (int i = 0; i < Q; i++) {
        cin >> x >> y;
        cout << d[x] + d[y] << endl;
    }


    return 0;

}



