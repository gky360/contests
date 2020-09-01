/*
[abc151] F - Enclose All
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 50;
const int MAX_X = 1000;
const double EPS = 1e-9;

int N;
int x[MAX_N], y[MAX_N];

double dist(double x0, double y0, double x1, double y1) {
    return sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
}

bool is_in(double cx, double cy, double r) {
    for (int i = 0; i < N; i++) {
        if (dist(cx, cy, x[i], y[i]) >= r + EPS) {
            return false;
        }
    }
    return true;
}

bool can(double r) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double s = dist(x[i], y[i], x[j], y[j]);
            if (s > 2 * r) return false;
            double mx = (x[i] + x[j]) * 0.5, my = (y[i] + y[j]) * 0.5;
            double h = sqrt(r * r - s * s * 0.25);
            double vx = (x[i] - x[j]) / s, vy = (y[i] - y[j]) / s;
            if (is_in(mx - vy * h, my + vx * h, r) ||
                is_in(mx + vy * h, my - vx * h, r)) {
                return true;
            }
        }
    }
    return false;
}

double solve() {
    double ng = 0, ok = MAX_X;
    for (int i = 0; i < 100; i++) {
        double m = (ng + ok) / 2;
        if (can(m)) {
            ok = m;
        } else {
            ng = m;
        }
    }

    return ok;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    cout << setprecision(15) << solve() << endl;

    return 0;
}
