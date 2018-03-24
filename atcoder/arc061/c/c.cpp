// AtCoder Regular Contest 061
// C - たくさんの数式 / Many Formulas

#include <cstdio>
#define MAX_S 10
using namespace std;

typedef long long int ll;


ll S;
int nums[MAX_S];
int length;
ll ans;

int main() {

  ll d;

  scanf("%lld", &S);

  d = 1;
  for (int i = 0; S / d > 0; d *= 10, i++) {
    nums[i] = (S / d) % 10;
    length = i + 1;
  }

  ans = 0;
  for (int b = 0; b < (1 << length); b += 2) { // 0 ビット目は常に 0
    for (int i = 0; i < length; i++) {
      d = (b & (1 << i)) ? (d * 10) : 1;
      ans += nums[i] * d;
    }
  }

  printf("%lld\n", ans);

}


