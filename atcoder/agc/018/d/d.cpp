// AtCoder Grand Contest 018
// D - Tree and Hamilton Path

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_N = 100000;
const int INF = (int)1e8;

struct edge {
    int to;
    ll cost;
};

int N;
vector<edge> G[MAX_N];
int size[MAX_N];

void calc_subtree_size(int v, int p = -1) {
    size[v] = 1;
    for (edge &e : G[v]) {
        if (e.to == p) {
            continue;
        }
        calc_subtree_size(e.to, v);
        size[v] += size[e.to];
    }
    return;
}

pii search_centroid(int v, int p = -1) {
    pii res(INF, -1);
    int s = 1, m = 0;
    for (edge &e : G[v]) {
        if (e.to == p) {
            continue;
        }
        res = min(res, search_centroid(e.to, v));
        m = max(m, size[e.to]);
        s += size[e.to];
    }
    m = max(m, N - s);
    res = min(res, pii(m, v));
    return res;
}

ll calc_ans(int v, int p = -1) {
    ll res = 0;
    for (edge &e : G[v]) {
        if (e.to == p) {
            continue;
        }
        res += calc_ans(e.to, v);
        res += e.cost * size[e.to] * 2;
    }
    return res;
}

int main() {

    int a, b;
    ll c, d;
    int cent;
    ll ans;

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back((edge){ b, c });
        G[b].push_back((edge){ a, c });
    }

    calc_subtree_size(0);
    cent = search_centroid(0).second;
    calc_subtree_size(cent);
    ans = calc_ans(cent);

    d = INF;
    for (edge &e : G[cent]) {
        if (N % 2 == 0 && size[e.to] == N / 2) {
            d = e.cost;
            break;
        }
        d = min(d, e.cost);
    }
    ans -= d;

    cout << ans << endl;

    return 0;

}



