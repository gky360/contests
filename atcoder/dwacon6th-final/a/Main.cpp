/*
[dwacon6th-final] A - 2525敷き詰め
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_H = 2525;
const int MAX_W = 2525;

int H, W;
char ans[MAX_H][MAX_W];

string pat1[1] = {"2255555"};
string pat2[2] = {
    "2555255",
    "2552555",
};
string pat3[3] = {
    "255",
    "252",
    "552",
};

bool solve() {
    bool is_reverse = false;
    if (H > W) {
        swap(H, W);
        is_reverse = true;
    }

    if (H == 1) {
        int offset;
        if (W % 7 == 0 || W % 7 == 2) {
            offset = 0;
        } else if (W % 7 == 5) {
            offset = 2;
        } else {
            return false;
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                ans[i][j] = pat1[i % 1][(j + offset) % 7];
            }
        }
    } else if (H == 2) {
        int offset;
        if (W % 7 == 0 || W % 7 == 1) {
            offset = 0;
        } else if (W % 7 == 6) {
            offset = 1;
        } else {
            return false;
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                ans[i][j] = pat2[i % 2][(j + offset) % 7];
            }
        }
    } else if (H == 3) {
        if (W != 3) {
            return false;
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                ans[i][j] = pat3[i][j];
            }
        }
    } else {
        return false;
    }

    if (is_reverse) {
        for (int i = 0; i < H; i++) {
            for (int j = i + 1; j < W; j++) {
                swap(ans[i][j], ans[j][i]);
            }
        }
        swap(H, W);
    }

    return true;
}

int main() {
    cin >> H >> W;

    bool can = solve();
    cout << (can ? "Yes" : "No") << endl;

    if (can) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cout << ans[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
