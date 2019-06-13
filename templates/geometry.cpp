// geometry.cpp
// geometric algorithms

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#include <complex>

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

int main() { return 0; }
