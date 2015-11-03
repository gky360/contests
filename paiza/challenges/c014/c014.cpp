// Paiza learning
// プログラミングスキルチェック
// C014:ボールが入る箱

#include <cstdio>
#include <algorithm>
using namespace std;

#define EPS 1e-10


int N;
double R;

int main() {

  double h, w, d;

  scanf("%d%lf", &N, &R);
  for (int i = 1; i <= N; i++) {
    scanf("%lf%lf%lf", &h, &w, &d);
    if (R * 2 < min(h, min(w, d)) + EPS) {
      printf("%d\n", i);
    }
  }

  return 0;

}


