/*
[dwacon6th-final] B - Harvest Festival
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;
const int MAX_M = 2e5;
const int MAX_K = 20;
const int MOD = 998244353;

const ll INF = 1e18;

class Graph {
public:
    vector<ll> dist;
    vector<vector<pli>> g;  // cost, to
    Graph(int n) : dist(n), g(n) {}
    void add_edge(int from, int to, ll cost) {
        g[from].push_back(pli(cost, to));
        return;
    }
    void dijkstra(int s) {
        priority_queue<pli, vector<pli>, greater<pli>> q;
        pli p, e;

        fill(ALL(dist), INF);
        dist[s] = 0;
        q.push(pli(dist[s], s));
        while (!q.empty()) {
            p = q.top();
            q.pop();
            if (dist[p.second] < p.first) {
                continue;
            }
            for (int i = 0; i < (int)g[p.second].size(); i++) {
                e = g[p.second][i];
                if (dist[e.second] > dist[p.second] + e.first) {
                    dist[e.second] = dist[p.second] + e.first;
                    q.push(pli(dist[e.second], e.second));
                }
            }
        }
        return;
    }
};

class gf {
public:
    int n;
    gf() : n(0) {}
    gf(int n) : n(n < 0 ? n % MOD + MOD : n % MOD) {}
    gf operator+(gf x) { return gf((n + x.n) % MOD); }
    gf operator-(gf x) { return gf((n - x.n + MOD) % MOD); }
    gf operator*(gf x) { return gf((1LL * n * x.n) % MOD); }
    gf& operator+=(gf x) { return *this = (*this + x); }
    gf& operator-=(gf x) { return *this = (*this - x); }
    gf& operator*=(gf x) { return *this = (*this * x); }
};

gf mod_pow(gf a, ll n) {
    gf ret = 1;
    for (; n > 0; n >>= 1) {
        if (n & 1) ret *= a;
        a *= a;
    }
    return ret;
}

int N, M, K, D;
int a[MAX_K];
Graph g(MAX_N);
bool reachable[MAX_N][MAX_K];
gf zeta[1 << MAX_K];

ll solve() {
    for (int k = 0; k < K; k++) {
        g.dijkstra(a[k]);
        for (int i = 0; i < N; i++) {
            if (g.dist[i] <= D) {
                reachable[i][k] = true;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        int mask = 0;
        for (int k = 0; k < K; k++) {
            if (reachable[i][k]) mask |= (1 << k);
        }
        zeta[mask] += 1;
    }

    for (int k = 0; k < K; k++) {
        for (int b = 0; b < (1 << K); b++) {
            if (b & (1 << k)) {
                zeta[b ^ (1 << k)] += zeta[b];
            }
        }
    }
    for (int b = 0; b < (1 << K); b++) {
        zeta[b] = mod_pow(2, zeta[b].n) - 1;
    }
    for (int k = 0; k < K; k++) {
        for (int b = 0; b < (1 << K); b++) {
            if (b & (1 << k)) {
                zeta[b ^ (1 << k)] -= zeta[b];
            }
        }
    }

    ll ans = 0;
    for (int b = 0; b < (1 << K); b++) {
        ans ^= zeta[b].n;
    }
    return ans;
}

int main() {
    cin >> N >> M >> K >> D;
    for (int k = 0; k < K; k++) {
        cin >> a[k];
    }
    for (int j = 0; j < M; j++) {
        int x, y, d;
        cin >> x >> y >> d;
        g.add_edge(x, y, d);
        g.add_edge(y, x, d);
    }

    cout << solve() << endl;

    return 0;
}
