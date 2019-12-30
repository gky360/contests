/*
[abc130] F - Minimum Bounding Box
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;
const int MAX_XY = 1e8;
const ll INF = 1e18;

int dxy[2][4] = {{0, 1, 0, -1}, {1, 0, -1, 0}};

int N;
int xy[2][MAX_N];
int d[MAX_N];

ll solve() {
    int l[2][3], r[2][3];
    for (int c = 0; c < 2; c++) {
        for (int k = 0; k < 3; k++) {
            l[c][k] = MAX_XY + 1;
            r[c][k] = -MAX_XY - 1;
            for (int i = 0; i < N; i++) {
                if (dxy[c][d[i]] + 1 == k) {
                    l[c][k] = min(l[c][k], xy[c][i]);
                    r[c][k] = max(r[c][k], xy[c][i]);
                }
            }
        }
    }

    vector<int> ts = {0};
    for (int c = 0; c < 2; c++) {
        ts.push_back((l[c][0] - l[c][1]) * 2);
        ts.push_back((l[c][1] - l[c][2]) * 2);
        ts.push_back(l[c][0] - l[c][2]);
        ts.push_back((r[c][0] - r[c][1]) * 2);
        ts.push_back((r[c][1] - r[c][2]) * 2);
        ts.push_back(r[c][0] - r[c][2]);
    }

    ll ans = INF;
    for (int t : ts) {
        if (t < 0 || INF <= t) {
            continue;
        }
        int xmax = max(max(2 * r[0][0] - t, 2 * r[0][1]), 2 * r[0][2] + t);
        int xmin = min(min(2 * l[0][0] - t, 2 * l[0][1]), 2 * l[0][2] + t);
        int ymax = max(max(2 * r[1][0] - t, 2 * r[1][1]), 2 * r[1][2] + t);
        int ymin = min(min(2 * l[1][0] - t, 2 * l[1][1]), 2 * l[1][2] + t);
        ans = min(ans, (ll)(xmax - xmin) * (ll)(ymax - ymin));
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        char d_raw;
        cin >> xy[0][i] >> xy[1][i] >> d_raw;
        switch (d_raw) {
            case 'U':
                d[i] = 0;
                break;
            case 'R':
                d[i] = 1;
                break;
            case 'D':
                d[i] = 2;
                break;
            case 'L':
                d[i] = 3;
                break;
        }
    }

    ll ans = solve();
    ll m = ans % 4;
    cout << ans / 4 << "." << setfill('0') << setw(2) << m * 25
         << "00000000000000" << endl;

    return 0;
}
