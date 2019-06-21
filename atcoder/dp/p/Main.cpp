/*
[dp] P - Independent Set
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;
const ll MOD = 1e9 + 7;

int N;
int x[MAX_N], y[MAX_N];
vector<int> g[MAX_N];
bool visited[MAX_N];

pll dfs(int v) {
    if (visited[v]) {
        return {-1, -1};
    }
    visited[v] = true;

    pll ret = {1, 1};
    for (int to : g[v]) {
        pll p = dfs(to);
        if (p == pll{-1, -1}) {
            continue;
        }
        (ret.first *= ((p.first + p.second) % MOD)) %= MOD;
        (ret.second *= (p.first)) %= MOD;
    }

    return ret;
}

ll solve() {
    for (int i = 0; i < N - 1; i++) {
        g[x[i]].push_back(y[i]);
        g[y[i]].push_back(x[i]);
    }

    pll ans = dfs(0);
    return (ans.first + ans.second) % MOD;
}

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }

    cout << solve() << endl;

    return 0;
}
