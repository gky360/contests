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
const double INF = 1e18;

int dxy[2][4] = {{0, 1, 0, -1}, {1, 0, -1, 0}};

int N;
int xy[2][MAX_N];
int d[MAX_N];

double calc(double t) {
    double m[2][2];
    for (int c = 0; c < 2; c++) {
        m[c][0] = INF;
        m[c][1] = -INF;
        for (int i = 0; i < N; i++) {
            m[c][0] = min(m[c][0], xy[c][i] + dxy[c][d[i]] * t);
            m[c][1] = max(m[c][1], xy[c][i] + dxy[c][d[i]] * t);
        }
    }

    return (m[0][1] - m[0][0]) * (m[1][1] - m[1][0]);
}

double solve() {
    double l = 0, r = 2 * MAX_XY + 1;
    for (int i = 0; i < 100; i++) {
        double m1 = (2 * l + r) / 3.0, m2 = (l + 2 * r) / 3.0;
        if (calc(m1) < calc(m2)) {
            r = m2;
        } else {
            l = m1;
        }
    }

    return calc(l);
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

    cout << setprecision(16) << fixed << solve() << endl;

    return 0;
}
