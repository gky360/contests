// Bellman-Ford 法

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_V = 1e5;
const int MAX_E = 1e5;
const ll INF = 1e18;

struct edge {
    int from, to, cost;
};

edge es[MAX_E];
ll d[MAX_V];

void bellman_ford(int s, int V, int E) {
    fill(d, d + V, INF);
    d[s] = 0;
    while (true) {
        bool updated = false;
        for (int j = 0; j < E; j++) {
            edge &e = es[j];
            if (d[e.from] < INF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                updated = true;
            }
        }
        if (!updated) {
            break;
        }
    }
}

bool detect_negative_circuit(int s, int V, int E) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < E; j++) {
            edge &e = es[j];
            if (d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                if (i == V - 1) {
                    return true;
                }
            }
        }
    }
    return false;
}
