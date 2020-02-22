/*
[abc133] E - Virus Tree 2
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;
const int MOD = 1e9 + 7;

class gf {
public:
    int n;
    gf() : n(0) {}
    gf(int n) : n(n % MOD) {}
    gf operator+(const gf x) const { return gf((n + x.n) % MOD); }
    gf operator*(const gf x) const { return gf((1LL * n * x.n) % MOD); }
    gf& operator+=(const gf x) { return *this = (*this + x); }
    gf& operator*=(const gf x) { return *this = (*this * x); }
};

int N, K;
vector<int> g[MAX_N];

gf dfs(int v, int par = -1) {
    if ((int)g[v].size() >= K) {
        return 0;
    }

    gf ret = 1;
    int k = (par == -1 ? K - 1 : K - 2);
    for (int to : g[v]) {
        if (to == par) {
            continue;
        }
        ret *= k;
        k--;
        ret *= dfs(to, v);
    }
    return ret;
}

ll solve() { return (dfs(0) * K).n; }

int main() {
    cin >> N >> K;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cout << solve() << endl;

    return 0;
}
