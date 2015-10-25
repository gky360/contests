// qualA_a.cpp
// CODE FESTIVAL 2014 予選A D - 壊れた電卓

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_D 15
#define INF ((long long int)1e16)

typedef long long int ll;

ll A;
int K;
int d[MAX_D + 1];
bool use[10];
int digits;
ll ans_l, ans_g;
ll ans;

int main() {

  ll tmp_a;
  int min_d, max_d;
  int second_idx_l, second_d_l;
  int second_idx_g, second_d_g;
  int i, j;

  scanf("%lld%d", &A, &K);

  memset(d, 0, sizeof(d));
  for (i = 0, tmp_a = A; tmp_a > 0; tmp_a /= 10, i++) {
    d[i] = tmp_a % 10;
  }
  digits = i;

  ans = INF;
  int comb = (1 << K) - 1;
  while (comb < (1 << 10)) {
    min_d = -1;
    for (i = 0; i < 10; i++) {
      if ((1 << i) & comb) {
        use[i] = true;
        if (min_d < 0) {
          min_d = i;
        }
        max_d = i;
      } else {
        use[i] = false;
      }
//      printf("%c", use[i] ? '0' + i : ' ');
    }
//    printf("\n");
//    printf("min_d: %d, max_d: %d\n", min_d, max_d);

    ans_l = 0; second_idx_l = digits - 1;
    if (digits > 1) {
      second_d_l = 0;
    } else {
      second_d_l = -1;
    }
    for (i = digits - 1; i >= 0; i--) {
      ans_l = min(ans_l * 10, INF);
      for (j = d[i] - 1; j >= 0; j--) {
        if (use[j]) {
          second_idx_l = i;
          second_d_l = j;
          break;
        }
      }

      if (use[d[i]]) {
        continue;
      }

      if (ans_l > 0) {
        ans_l += d[i] - max_d;
      } else {
        if (second_d_l >= 0) {
          i = second_idx_l;
          ans_l = d[i] - second_d_l;
        } else {
          ans_l = INF;
        }
      }
    }

    ans_g = 0; second_idx_g = digits;
    second_d_g = -1;
    for (i = 1; i < 10; i++) {
      if ((1 << i) & comb) {
        second_d_g = i;
        break;
      }
    }
    for (i = digits - 1; i >= 0; i--) {
      ans_g = min(ans_g * 10, INF);
      for (j = d[i] + 1; j < 10; j++) {
        if (use[j]) {
          second_idx_g = i;
          second_d_g = j;
          break;
        }
      }

      if (use[d[i]]) {
        continue;
      }

      if (ans_g > 0) {
        ans_g += min_d - d[i];
      } else {
        if (second_d_g >= 1) {
          i = second_idx_g;
          ans_g = second_d_g - d[i];
        } else {
          ans_g = INF;
        }
      }
    }

//    printf("l: %lld, g: %lld\n", ans_l, ans_g);
    ans = min(ans, min(ans_l, ans_g));

    int x = comb & -comb;
    int y = comb + x;
    comb = ((comb & ~y) / x >> 1) | y;
  }

  printf("%lld\n", ans);

  return 0;

}


