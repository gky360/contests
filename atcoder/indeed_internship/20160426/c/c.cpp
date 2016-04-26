// AtCoder Indeed internship 2016 0426
// C - マス目と駒

#include <cstdio>
#include <cstring>
#define W 6
#define H 6
using namespace std;


typedef long long int ll;

int patt[H], comb[H];
ll ans;

ll calc(int y) {
  if (y > 3) {
    for (int i = 0; i < W; i++) {
      int sum = 0;
      for (int j = 0; j < y; j++) {
        if (comb[j] & (1 << i)) {
          sum++;
        }
      }
      if (sum != 3) {
        if (y == H || sum > 3) {
          return 0;
        }
      }
    }
    if (y == H) {
      return 1;
    }
  }

  ll ret = 0;
  comb[y] = (1 << 3) - 1;
  while (comb[y] < (1 << W)) {
    if ((patt[y] & comb[y]) == patt[y]) {
      ret += calc(y + 1);
    }
    int a = comb[y] & -comb[y];
    int b = comb[y] + a;
    comb[y] = ((comb[y] & ~b) / a >> 1) | b;
  }

  return ret;
}

int main() {

  char c;

  memset(patt, 0, sizeof(patt));
  for (int j = 0; j < H; j++) {
    for (int i = 0; i < W; i++) {
      scanf("%c", &c);
      if (c == 'o') {
        patt[j] += 1 << i;
      }
    }
    scanf("%*c");
  }

  printf("%lld\n", calc(0));

  return 0;

}


