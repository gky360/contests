// AtCoder Grand Contest 015
// C - Nuske vs Phantom Thnook

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;


const int MAX_N = 2000;
const int MAX_M = 2000;

int N, M, Q;
int nodes[MAX_N + 1][MAX_M + 1];
int edges[2][MAX_N + 1][MAX_M + 1];

int main() {

    char c;
    int x1, y1, x2, y2;
    int q_nodes, q_edges;

    cin >> N >> M >> Q;
    memset(nodes, 0, sizeof(nodes));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> c;
            nodes[i + 1][j + 1] = (c == '0' ? 0 : 1);
        }
    }

    memset(edges, 0, sizeof(edges));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (nodes[i][j] == 1 && nodes[i - 1][j] == 1) {
                edges[0][i][j] = 1;
            }
            if (nodes[i][j] == 1 && nodes[i][j - 1] == 1) {
                edges[1][i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            nodes[i][j] += nodes[i][j - 1];
            edges[0][i][j] += edges[0][i][j - 1];
            edges[1][i][j] += edges[1][i][j - 1];
        }
    }
    for (int j = 1; j <= M; j++) {
        for (int i = 1; i <= N; i++) {
            nodes[i][j] += nodes[i - 1][j];
            edges[0][i][j] += edges[0][i - 1][j];
            edges[1][i][j] += edges[1][i - 1][j];
        }
    }

    for (int q = 0; q < Q; q++) {
        cin >> x1 >> y1 >> x2 >> y2;
        q_nodes = nodes[x2][y2] - nodes[x2][y1 - 1] - nodes[x1 - 1][y2] + nodes[x1 - 1][y1 - 1];
        q_edges = edges[0][x2][y2] - edges[0][x2][y1 - 1] - edges[0][x1][y2] + edges[0][x1][y1 - 1];
        q_edges += edges[1][x2][y2] - edges[1][x2][y1] - edges[1][x1 - 1][y2] + edges[1][x1 - 1][y1];
        cout << q_nodes - q_edges << endl;
    }

    return 0;

}



