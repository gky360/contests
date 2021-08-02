/*
[abc181] C - Collinearity
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double DD;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e2;

struct Point : public complex<DD> {
    DD x() const { return real(); }
    void x(DD val) { real(val); }
    DD y() const { return imag(); }
    void y(DD val) { imag(val); }
    Point() {}
    Point(DD a, DD b) {
        x(a);
        y(b);
    }
    Point(const complex<DD> &p) {
        x(p.real());
        y(p.imag());
    }
};

const DD EPS = 1e-8;

DD cross(const Point &a, const Point &b) { return imag(conj(a) * b); }

int N;
int x[MAX_N], y[MAX_N];

bool solve() {
    REP(k, N) REP(j, k) REP(i, j) {
        Point a(x[i], y[i]);
        Point b(x[j], y[j]);
        Point c(x[k], y[k]);
        if (abs(cross(a - b, a - c)) < EPS) return true;
    }

    return false;
}

int main() {
    cin >> N;
    REP(i, N) cin >> x[i] >> y[i];

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
