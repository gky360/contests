/*
[agc039] B - Graph Partition
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 200;
const int INF = 1e9;

int N;
string S[MAX_N];
int color[MAX_N];
int dist[MAX_N][MAX_N];

bool is_bipartite(int v, int c) {
    bool ret = true;
    if (color[v] != 0) {
        return (color[v] == c);
    }
    color[v] = c;
    for (int to = 0; to < N; to++) {
        if (S[v][to] != '1') {
            continue;
        }
        ret = ret && is_bipartite(to, -color[v]);
    }
    return ret;
}

void warshall_floyd() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else if (S[i][j] == '1') {
                dist[i][j] = 1;
            } else {
                dist[i][j] = INF;
            }
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

ll solve() {
    if (!is_bipartite(0, 1)) {
        return -1;
    }

    warshall_floyd();

    int dia = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dia = max(dia, dist[i][j]);
        }
    }

    return dia + 1;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    cout << solve() << endl;

    return 0;
}
