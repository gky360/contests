/*
[ddcc2019-final] C - 光の反射 (Reflection of Light)
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_K = 10;

struct Point : public complex<double> {
    double x() const { return real(); }
    void x(double val) { real(val); }
    double y() const { return imag(); }
    void y(double val) { imag(val); }
    Point() {}
    Point(double a, double b) {
        x(a);
        y(b);
    }
    Point(const complex<double> &p) {
        x(p.real());
        y(p.imag());
    }
};

const double EPS = 1e-8;
const double INF = 1e12;

bool operator<(const Point &a, const Point &b) {
    return a.x() != b.x() ? a.x() < b.x() : a.y() < b.y();
}
double cross(const Point &a, const Point &b) { return imag(conj(a) * b); }
double dot(const Point &a, const Point &b) { return real(conj(a) * b); }

struct Line : public vector<Point> {
    Line(const Point &a, const Point &b) {
        push_back(a);
        push_back(b);
    }
};

typedef vector<Point> Poly;

struct Circle {
    Point p;
    double r;
    Circle(const Point &p, double r) : p(p), r(r) {}
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
    double t = dot(p - l[0], l[0] - l[1]) / norm(l[0] - l[1]);
    return l[0] + t * (l[0] - l[1]);
}
Point reflection(const Line &l, const Point &p) {
    return p + 2.0 * (projection(l, p) - p);
}
double distanceLP(const Line &l, const Point &p) {
    return abs(p - projection(l, p));
}
double distanceLL(const Line &l, const Line &m) {
    return intersectLL(l, m) ? 0 : distanceLP(l, m[0]);
}
double distanceLS(const Line &l, const Line &s) {
    if (intersectLS(l, s)) return 0;
    return min(distanceLP(l, s[0]), distanceLP(l, s[1]));
}
double distanceSP(const Line &s, const Point &p) {
    const Point r = projection(s, p);
    if (intersectSP(s, r)) return abs(r - p);
    return min(abs(s[0] - p), abs(s[1] - p));
}
double distanceSS(const Line &s, const Line &t) {
    if (intersectSS(s, t)) return 0;
    return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
               min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}
Point crosspoint(const Line &l, const Line &m) {
    double A = cross(l[1] - l[0], m[1] - m[0]);
    double B = cross(l[1] - l[0], l[1] - m[0]);
    if (abs(A) < EPS && abs(B) < EPS) return m[0];  // same line
    if (abs(A) < EPS) assert(false);  // !!!PRECONDITION NOT SATISFIED!!!
    return m[0] + B / A * (m[1] - m[0]);
}

double X, Y, R;
double S_X, S_Y;
int K;
Point ls[MAX_K + 1], rs[MAX_K + 1];

Point calc(Point p, int dir) {
    double r = hypot(p.x() - X, p.y() - Y);
    double deg = atan2(Y - p.y(), X - p.x()) + dir * asin(R / r);
    double dx = cos(deg), dy = sin(deg);

    double di = 2.0;
    for (int i = 0; i < 100; i++) {
        double nx = p.x() + di * dx, ny = p.y() + di * dy;
        if (nx * nx + ny * ny <= 1) {
            p.x(nx);
            p.y(ny);
        }
        di /= 2.0;
    }

    return p;
}

double angle(Point p1, Point p2) {
    double ret = atan2(p2.y(), p2.x()) - atan2(p1.y(), p1.x());
    ret /= 8.0 * atan(1.0);
    return (ret < 0.0) ? ret + 1.0 : ret;
}

void solve() {
    Point a;

    a = calc(Point(S_X, S_Y), 1);
    ls[0] = a;
    a = calc(Point(S_X, S_Y), -1);
    rs[0] = a;

    double ans = angle(ls[0], rs[0]);
    cout << setprecision(15) << min(1.0, ans) << endl;
    for (int i = 0; i < K; i++) {
        a = calc(ls[i], 1);
        ls[i + 1] = a;
        a = calc(rs[i], -1);
        rs[i + 1] = a;
        ans += angle(ls[i + 1], ls[i]);
        ans += angle(rs[i], rs[i + 1]);
        cout << setprecision(15) << min(1.0, ans) << endl;
    }
}

int main() {
    cin >> X >> Y >> R;
    cin >> S_X >> S_Y;
    cin >> K;

    solve();

    return 0;
}
