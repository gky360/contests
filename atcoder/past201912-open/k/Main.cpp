/*
[past201912-open] K - 巨大企業 / Conglomerate
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 150000;
const int MAX_Q = 100000;

const int MAX_V = MAX_N;

int L[MAX_V], R[MAX_V];
vector<int> g[MAX_V];
int euler_idx = 0;

void euler_tour(int v, int par = -1) {
    L[v] = euler_idx++;
    for (int to : g[v]) {
        if (to == par) {
            continue;
        }
        euler_tour(to, v);
    }
    R[v] = euler_idx;
}

int N;
int p[MAX_N];
int Q;
int a[MAX_Q], b[MAX_Q];

void solve() {
    int root = -1;
    for (int i = 0; i < N; i++) {
        if (p[i] == -1) {
            root = i;
        } else {
            g[i].push_back(p[i]);
            g[p[i]].push_back(i);
        }
    }
    euler_tour(root);

    for (int q = 0; q < Q; q++) {
        bool ans = L[b[q]] <= L[a[q]] && R[a[q]] <= R[b[q]];
        cout << (ans ? "Yes" : "No") << endl;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> p[i];
        if (p[i] != -1) {
            p[i]--;
        }
    }
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        cin >> a[q] >> b[q];
        a[q]--, b[q]--;
    }

    solve();

    return 0;
}
