/*
[abc157] F - Yakiniku Optimization Problem
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

#include <complex>
typedef long double DD;

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
const DD INF = 1LL << 60;

bool operator<(const Point &a, const Point &b) {
    return a.x() != b.x() ? a.x() < b.x() : a.y() < b.y();
}
DD cross(const Point &a, const Point &b) { return imag(conj(a) * b); }
DD dot(const Point &a, const Point &b) { return real(conj(a) * b); }
bool eq(const Point &p, const Point &q) { return abs(p - q) < EPS; }

struct Line : public vector<Point> {
    Line(const Point &a, const Point &b) {
        push_back(a);
        push_back(b);
    }
};

typedef vector<Point> Poly;

struct Circle {
    Point p;
    DD r;
    Circle(const Point &p, DD r) : p(p), r(r) {}
};

int ccw(Point a, Point b, Point c) {
    b -= a;
    c -= a;
    if (cross(b, c) > 0) return +1;    // counter clockwise
    if (cross(b, c) < 0) return -1;    // clockwise
    if (dot(b, c) < 0) return +2;      // c--a--b on line
    if (norm(b) < norm(c)) return -2;  // a--b--c on line
    return 0;
}

bool intersectLL(const Line &l, const Line &m) {
    return abs(cross(l[1] - l[0], m[1] - m[0])) > EPS ||  // non-parallel
           abs(cross(l[1] - l[0], m[0] - l[0])) < EPS;    // same line
}
bool intersectLS(const Line &l, const Line &s) {
    return cross(l[1] - l[0], s[0] - l[0]) *  // s[0] is left of l
               cross(l[1] - l[0], s[1] - l[0]) <
           EPS;  // s[1] is right of l
}
bool intersectLP(const Line &l, const Point &p) {
    return abs(cross(l[1] - p, l[0] - p)) < EPS;
}
bool intersectSS(const Line &s, const Line &t) {
    return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
           ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0;
}
bool intersectSP(const Line &s, const Point &p) {
    return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) <
           EPS;  // triangle inequality
}

Point projection(const Line &l, const Point &p) {
    DD t = dot(p - l[0], l[0] - l[1]) / norm(l[0] - l[1]);
    return l[0] + t * (l[0] - l[1]);
}
Point reflection(const Line &l, const Point &p) {
    return p + 2.0L * (projection(l, p) - p);
}
DD distanceLP(const Line &l, const Point &p) {
    return abs(p - projection(l, p));
}
DD distanceLL(const Line &l, const Line &m) {
    return intersectLL(l, m) ? 0 : distanceLP(l, m[0]);
}
DD distanceLS(const Line &l, const Line &s) {
    if (intersectLS(l, s)) return 0;
    return min(distanceLP(l, s[0]), distanceLP(l, s[1]));
}
DD distanceSP(const Line &s, const Point &p) {
    const Point r = projection(s, p);
    if (intersectSP(s, r)) return abs(r - p);
    return min(abs(s[0] - p), abs(s[1] - p));
}
DD distanceSS(const Line &s, const Line &t) {
    if (intersectSS(s, t)) return 0;
    return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
               min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}
Point crosspoint(const Line &l, const Line &m) {
    DD A = cross(l[1] - l[0], m[1] - m[0]);
    DD B = cross(l[1] - l[0], l[1] - m[0]);
    if (abs(A) < EPS && abs(B) < EPS) return m[0];  // same line
    if (abs(A) < EPS) assert(false);  // !!!PRECONDITION NOT SATISFIED!!!
    return m[0] + B / A * (m[1] - m[0]);
}
vector<Point> crosspoint(const Circle &e, const Circle &f) {
    vector<Point> res;
    DD d = abs(e.p - f.p);
    if (d < EPS) return vector<Point>();
    if (d > e.r + f.r + EPS) return vector<Point>();
    if (d < abs(e.r - f.r) - EPS) return vector<Point>();
    DD rcos = (d * d + e.r * e.r - f.r * f.r) / (2.0 * d), rsin;
    if (e.r - abs(rcos) < EPS)
        rsin = 0;
    else
        rsin = sqrt(e.r * e.r - rcos * rcos);
    Point dir = (f.p - e.p) / d;
    Point p1 = e.p + dir * Point(rcos, rsin);
    Point p2 = e.p + dir * Point(rcos, -rsin);
    res.push_back(p1);
    if (!eq(p1, p2)) res.push_back(p2);
    return res;
}

const int MAX_N = 60;

int N, K;
DD x[MAX_N], y[MAX_N], c[MAX_N];

int cnt(DD a, DD b, DD t) {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        if (((a - x[i]) * (a - x[i]) + (b - y[i]) * (b - y[i])) <=
            t * t / c[i] / c[i] + EPS) {
            ret++;
        }
    }
    return ret;
}

bool can(DD t) {
    for (int i = 0; i < N; i++) {
        if (cnt(x[i], y[i], t) >= K) {
            return true;
        }
    }

    for (int i = 0; i < N; i++) {
        Circle c0(Point(x[i], y[i]), t / c[i]);
        for (int j = i + 1; j < N; j++) {
            Circle c1(Point(x[j], y[j]), t / c[j]);
            auto ps = crosspoint(c0, c1);
            for (Point &p : ps) {
                if (cnt(p.x(), p.y(), t) >= K) {
                    return true;
                }
            }
        }
    }

    return false;
}

DD solve() {
    DD ng = 0, ok = INF;
    while (ok - ng > EPS) {
        DD m = (ok + ng) * 0.5;
        if (can(m)) {
            ok = m;
        } else {
            ng = m;
        }
    }
    return ok;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> c[i];
    }

    cout << setprecision(25) << solve() << endl;

    return 0;
}
