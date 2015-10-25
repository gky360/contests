// code thanks festival 2014 予選A D - 定期券

#include <cstdio>
#include <algorithm>
using namespace std;


int N, Q;

int main() {

  int a, b, s, t;

  scanf("%d%d", &N, &Q);
  for (int i = 0; i < Q; i++) {
    scanf("%d%d%d%d", &a, &b, &s, &t);
    printf("%d\n", (max(a - s, 0) + max(t - b, 0) - max(s - b, 0) - max(a - t, 0)) * 100);
  }

  return 0;
}
