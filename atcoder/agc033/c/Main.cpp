/*
[agc033] C - Removing Coins
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 2e5;

int N;
vector<int> g[MAX_N];

// pii<distance, v>
pii dfs(int v, int par = -1) {
    pii r = {0, v};
    for (int to : g[v]) {
        if (to == par) {
            continue;
        }
        pii t = dfs(to, v);
        t.first += 1;
        if (t.first > r.first) {
            r = t;
        }
    }
    return r;
}

int diameter() {
    pii s = dfs(0);
    pii t = dfs(s.second);
    return t.first;
}

bool solve() { return diameter() % 3 != 1; }

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    cout << (solve() ? "First" : "Second") << endl;

    return 0;
}
