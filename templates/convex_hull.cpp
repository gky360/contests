// convex_hull.cpp
// 凸包

#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> P;  // real: x, imag: y

namespace std {
bool operator<(const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
}
};  // namespace std
double cross(const P& a, const P& b) { return imag(conj(a) * b); }
double dot(const P& a, const P& b) { return real(conj(a) * b); }
int ccw(P a, P b, P c) {
    b -= a;
    c -= a;
    if (cross(b, c) > 0) return +1;    // counter clockwise
    if (cross(b, c) < 0) return -1;    // clockwise
    if (dot(b, c) < 0) return +2;      // c--a--b on line
    if (norm(b) < norm(c)) return -2;  // a--b--c on line
    return 0;
}

void convex_hull(vector<P>& ps, vector<P>& ch) {
    int n = ps.size(), k = 0;
    sort(ps.begin(), ps.end());
    ch.resize(2 * n);
    for (int i = 0; i < n; ch[k++] = ps[i++]) {  // lower-hull
        assert(0 <= i && i < n);
        while (k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) {
            k--;
        }
    }
    for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--]) {  // upper-hull
        assert(0 <= i && i < n);
        while (k >= t && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) {
            k--;
        }
    }
    ch.resize(k - 1);
}
