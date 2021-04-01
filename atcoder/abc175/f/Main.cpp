/*
[abc175] F - Making Palindrome
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

typedef pair<string, int> psi;

const int MAX_N = 50;
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

int N;
string S[MAX_N];
ll C[MAX_N];
map<psi, int> id;

psi cat(string l, string r) {
    int d = 0;
    if (l.length() < r.length()) {
        d = 1;
        reverse(ALL(l)), reverse(ALL(r));
        swap(l, r);
    }
    string rr = r;
    reverse(ALL(rr));
    if (l.substr(l.length() - r.length(), r.length()) != rr) return psi("", -1);
    psi ret(l.substr(0, l.length() - r.length()), d);
    if (d == 1) reverse(ALL(ret.first));
    return ret;
}

ll solve() {
    assert(cat("b", "a").second == -1);

    REP(i, N) {
        REP(j, S[i].length()) {
            psi sd(S[i].substr(0, j + 1), 0);
            if (!id.count(sd)) id[sd] = id.size();
            sd = psi(S[i].substr(j), 1);
            if (!id.count(sd)) id[sd] = id.size();
        }
    }

    Graph g(id.size() + 2);
    int vs = id.size() + 1, vt = id.size();
    id[psi("", 0)] = id.size();

    REP(i, N) {
        REP(j, S[i].length() + 1) {
            psi sd = cat(S[i].substr(0, j), S[i].substr(j));
            if (sd.second != -1) g.add_edge(vs, id[sd], C[i]);
        }
        REP(j, S[i].length()) {
            psi sd = cat(S[i].substr(0, j), S[i].substr(j + 1));
            if (sd.second != -1) g.add_edge(vs, id[sd], C[i]);
        }
    }
    for (auto &sdv : id) {
        string s = sdv.first.first;
        int d = sdv.first.second;
        int v = sdv.second;
        REP(i, N) {
            auto nsd = d == 0 ? cat(s, S[i]) : cat(S[i], s);
            if (id.count(nsd)) g.add_edge(v, id[nsd], C[i]);
        }
    }

    g.dijkstra(vs);

    ll ans = g.dist[vt];
    return ans == INF ? -1 : ans;
}

int main() {
    cin >> N;
    REP(i, N) cin >> S[i] >> C[i];

    cout << solve() << endl;

    return 0;
}
