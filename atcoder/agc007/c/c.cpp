// AtCoder Grand Contest 007
// C - Pushing Balls

#include <cstdio>

#define EPS 1e-12;
using namespace std;


int N;
double l, r, x, s;

int main() {

  scanf("%d%lf%lf", &N, &l, &x);
  r = l + x * (2 * N - 1);

  s = 0.0;
  for (int i = 0; i < N; i++) {
    s += (l + r) * 0.5;
    l = (l * (2 * (N - i) + 2) + x * 5) / (2 * (N - i));
    r = (r * (2 * (N - i) + 2) - x * 5) / (2 * (N - i));
    x = (r - l) / (N - i);
  }

  printf("%.12lf\n", s);

  return 0;

}


