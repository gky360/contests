// AtCoder Grand Contest 014
// C - Closed Rooms

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_H = 800;
const int MAX_W = 800;
const int INF = 1e8;

int H, W, K;
bool rooms[MAX_H][MAX_W];
queue<pii> q;
int dist[MAX_H][MAX_W];
int dh[4] = { -1, 0, 1, 0 };
int dw[4] = { 0, 1, 0, -1 };

int main() {

    string s;
    int ans;

    cin >> H >> W >> K;
    for (int i = 0; i < H; i++) {
        cin >> s;
        for (int j = 0; j < W; j++) {
            rooms[i][j] = (s[j] != '#');
            dist[i][j] = INF;
            if (s[j] == 'S') {
                q.push(pii(i, j));
                dist[i][j] = 0;
            }
        }
    }

    ans = INF;
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int h = p.first;
        int w = p.second;
        int d = min(min(h, w), min(H - 1 - h, W - 1 - w));

        if (dist[h][w] <= K) {
            ans = min(ans, (d + K - 1) / K + 1);
            for (int k = 0; k < 4; k++) {
                int i = h + dh[k];
                int j = w + dw[k];
                if (0 <= i && i < H && 0 <= j && j < W && rooms[i][j] && dist[i][j] > dist[h][w] + 1) {
                    dist[i][j] = dist[h][w] + 1;
                    q.push(pii(i, j));
                }
            }
        }
    }

    cout << ans << endl;

    return 0;

}



