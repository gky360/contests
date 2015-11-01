// Algorithms and Data Structures I
// 05 - Recursion / Divide and Conquer
// C - Koch Curve

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;


typedef pair<double, double> P;

int N;
vector<P> points;

P operator+(P p1, P p2) {
  return P(p1.first + p2.first, p1.second + p2.second);
}

P operator-(P p1, P p2) {
  return P(p1.first - p2.first, p1.second - p2.second);
}

P operator*(P p, double a) {
  return P(p.first * a, p.second * a);
}

P operator/(P p, double a) {
  return P(p.first / a, p.second / a);
}

void koch(int n, P l, P r) {
  if (n <= 0) {
    return;
  }
  P v = (r - l) / 3;
  P l_child = (l * 2 + r) / 3;
  P m_child = P(v.first - v.second * sqrt(3), v.first * sqrt(3) + v.second) * 0.5 + l_child;
  P r_child = (l + r * 2) / 3;

  koch(n - 1, l, l_child);
  points.push_back(l_child);
  koch(n - 1, l_child, m_child);
  points.push_back(m_child);
  koch(n - 1, m_child, r_child);
  points.push_back(r_child);
  koch(n - 1, r_child, r);
  return;
}

int main() {

  P s = P(0, 0);
  P t = P(100, 0);

  scanf("%d", &N);
  points.push_back(s);
  koch(N, s, t);
  points.push_back(t);

  for (vector<P>::iterator itr = points.begin(); itr != points.end(); itr++) {
    printf("%.8lf %.8lf\n", itr->first, itr->second);
  }

  return 0;

}


