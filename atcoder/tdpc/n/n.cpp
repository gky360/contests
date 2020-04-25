// TDPC
// N - 木

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 1000;
const ll MOD = 1000000007;

int N;
vector<int> g[MAX_N];
ll fact[MAX_N + 1];

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int extgcd(int a, int b, int& x, int& y) {
    int d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

int mod_inv(int a, int m) {
    int x, y;
    extgcd(a, m, x, y);
    return (m + x) % m;
}

pli dfs(int u, int par = -1) {
    ll m = 1, s = 0, c = 1;
    for (int v : g[u]) {
        if (v == par) {
            continue;
        }
        auto p = dfs(v, u);
        m *= p.first;
        m %= MOD;
        s += p.second;
        c *= mod_inv(fact[p.second], MOD);
        c %= MOD;
    }
    return pli(((fact[s] * c) % MOD) * m % MOD, s + 1);
}

int main() {
    int a, b;
    ll ans;

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }

    ans = 0;
    for (int i = 0; i < N; i++) {
        pli p = dfs(i);
        ans += p.first;
        ans %= MOD;
    }
    ans *= mod_inv(2, MOD);
    ans %= MOD;

    cout << ans << endl;

    return 0;
}
