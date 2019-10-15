/*
[agc033] A - Darker and Darker
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_H = 1000;
const int MAX_W = 1000;

const int dh[4] = {-1, 0, 1, 0};
const int dw[4] = {0, 1, 0, -1};

int H, W;
string A[MAX_H];

ll solve() {
    queue<pair<int, pii>> q;
    bool visited[MAX_H][MAX_W];
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '#') {
                q.push({0, {i, j}});
            }
        }
    }

    int ans = 0;
    while (!q.empty()) {
        auto thw = q.front();
        q.pop();
        int t = thw.first;
        int h = thw.second.first;
        int w = thw.second.second;
        if (h < 0 || H <= h || w < 0 || W <= w) {
            continue;
        }
        if (visited[h][w]) {
            continue;
        }
        visited[h][w] = true;
        ans = max(ans, t);

        for (int i = 0; i < 4; i++) {
            q.push({t + 1, {h + dh[i], w + dw[i]}});
        }
    }

    return ans;
}

int main() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
