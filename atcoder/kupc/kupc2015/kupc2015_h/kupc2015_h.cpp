// 京都大学プログラミングコンテスト 2015 H - Bit Count

#include <cstdio>
#include <algorithm>
using namespace std;

typedef unsigned long long int ull;

ull n;
ull ans;

int main() {

  int t;

  for (scanf("%d", &t); t > 0; t--) {
    scanf("%lld", &n);


    for (int i = 63; i >= 0; i--) {
      printf("%d", (int)((n >> i) & 1));
    }
    printf("\n");

    for (int x = 1; x < 1000000; x++) {
      int count_x = 0;
      for (int i = 31; i >= 0; i--) {
        count_x += ((x >> i) & 1) ? 1 : 0;
      }

      int count_nx = 0;
      for (int i = 31; i >= 0; i--) {
        count_nx += (((x + n) >> i) & 1) ? 1 : 0;
      }

      if (count_x == count_nx) {
        printf("%d\n", x);

        for (int i = 63; i >= 0; i--) {
          printf("%d", (int)((x >> i) & 1));
        }
        printf("\n");
        break;
      }
    }



    ans = 0;
    for (ull i = (ull)1 << 63; i > 0; i = i >> 1) {
      if ((n & i) && !(n & (i >> 1))) {
        ans += i;
      }
    }





    printf("%lld\n", ans);

    for (int i = 63; i >= 0; i--) {
      printf("%d", (int)((ans >> i) & 1));
    }
    printf("\n");
  }

  return 0;

}


