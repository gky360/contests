// ABC109
// D - Make Them Even

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_H = 500;
const int MAX_W = 500;

int H, W;
int a[MAX_H][MAX_W];

struct mv {
    int ya, xa, yb, xb;
};

void solve(vector<mv> &res) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W - 1; j++) {
            if (a[i][j] % 2 > 0) {
                res.push_back((mv){i + 1, j + 1, i + 1, j + 2});
                a[i][j]--;
                a[i][j + 1]++;
            }
        }
    }
    for (int i = 0; i < H - 1; i++) {
        if (a[i][W - 1] % 2 > 0) {
            res.push_back((mv){i + 1, W, i + 2, W});
            a[i][W - 1]--;
            a[i + 1][W - 1]++;
        }
    }
}

int main() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> a[i][j];
        }
    }

    vector<mv> ans;
    solve(ans);
    cout << ans.size() << endl;
    for (auto m : ans) {
        cout << m.ya << " " << m.xa << " " << m.yb << " " << m.xb << endl;
    }

    return 0;
}
