// Paiza learning
// プログラミングスキルチェック
// B006:ダーツゲーム

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define G 9.8

int main() {

  double o_y, s, th, x, y, a;
  double h;
  int tmp_th;

  scanf("%lf%lf%d%lf%lf%lf", &o_y, &s, &tmp_th, &x, &y, &a);
  if (tmp_th == 90) {
    printf("Miss\n");
    return 0;
  }
  th = tmp_th;

  h = o_y + x * tan(th * M_PI / 180) - (G * x * x) / (2 * s * s * cos(th * M_PI / 180) * cos(th * M_PI / 180));
  if (h - y <= a * 0.5) {
    printf("Hit %.1lf\n", abs(h - y));
  } else {
    printf("Miss\n");
  }

  return 0;

}


