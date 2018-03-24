// AtCoder Regular Contest 072
// C - Sequence

#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAX_N 100000
using namespace std;
typedef long long int ll;


int N;
ll a[MAX_N];
ll ans;

int main() {

  ll sum, tmp_ans;
  bool pm;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &a[i]);
  }

  ans = (ll)1e14;
  for (int j = 0; j < 2; j++) {
    sum = 0;
    tmp_ans = 0;
    pm = (j == 0);
    for (int i = 0; i < N; i++) {
      sum += a[i];
      if (sum == 0) {
        tmp_ans++;
        sum = pm ? 1 : -1;
      } else if ((sum > 0) == pm) {
        if (sum > 0) {
          tmp_ans += sum + 1;
          sum = -1;
        } else {
          tmp_ans += 1 - sum;
          sum = 1;
        }
      }
      pm = (sum > 0);
    }
    ans = min(ans, tmp_ans);
  }

  printf("%lld\n", ans);

  return 0;

}


