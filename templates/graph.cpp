// graph.cpp
// graph related algorithms

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_V = 1e5;

vector<int> g[MAX_V];

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

ll solve() {}

int main() {
    cout << solve() << endl;

    return 0;
}
