// 京都大学プログラミングコンテスト 2015 E - マッサージチェア2015

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define EPS 1e-10


int h, w;
double ans;


double f(double x) {
  return x*x - 2*w*sqrt(x*x - h*h) - 2*h*sqrt(x*x-w*w);
}

int main() {

  int t;
  double a, b;

  for (scanf("%d", &t); t > 0; t--) {

    scanf("%d%d", &h, &w);
    if (w < h) {
      swap(w, h);
    }

    a = w;
    b = sqrt((w * 0.5) * (w * 0.5) + h * h);
    if (a < b) {
      double l ,r;
      l = a;
      r = b;
      while (r - l > EPS) {
        if (f((r + l) / 2) >= 0) {
          l = (r + l) / 2;
        } else {
          r = (r + l) / 2;
        }
      }
      ans = l;
    } else {
      ans = b;
    }

    printf("%.10lf\n", ans);

  }

  return 0;

}


