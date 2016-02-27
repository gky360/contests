#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;


int L[3];

int main() {

  int r0 = 300;
  int r1 = 0;
  int max_l = 0;
  int max_i = 0;

  for (int i = 0; i < 3; i++) {
    scanf("%d", &L[i]);
    r1 += L[i];
    if (max_l < L[i]) {
      max_l = L[i];
      max_i = i;
    }
  }

  if (max_l <= r1 - L[max_i]) {
    // 三角形作れる
    r0 = 0;
  } else {
    // 三角形作れない
    for (int i = -1; i <= 1; i += 2) {
      for (int j = -1; j <= 1; j += 2) {
        r0 = min(r0, (int)abs(L[0] + i * L[1] + j * L[2] + 0.0));
      }
    }
  }

  printf("%.10lf\n", M_PI * (r1 * r1 - r0 * r0));

  return 0;
}

