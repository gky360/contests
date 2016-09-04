// AtCoder Regular Contest 051
// A - 塗り絵

#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;


int cx, cy, r;
int x[2], y[2];

bool rec_in_cir() {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      if ((x[i] - cx) * (x[i] - cx) + (y[j] - cy) * (y[j] - cy) > r * r) {
        return false;
      }
    }
  }
  return true;
}

bool cir_in_rec() {
  return (x[0] + r <= cx) && (cx <= x[1] - r) && (y[0] + r <= cy) && (cy <= y[1] - r);
}

int main() {

  scanf("%d%d%d", &cx, &cy, &r);
  scanf("%d%d%d%d", &x[0], &y[0], &x[1], &y[1]);

  if (rec_in_cir()) {
    printf("YES\nNO\n");
  } else if (cir_in_rec()) {
    printf("NO\nYES\n");
  } else {
    printf("YES\nYES\n");
  }

  return 0;

}


