// AtCoder Beginner Contest 057
// D - Maximum Average Sets

#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#define MAX_N 50
#define EPS 1e-10
using namespace std;
typedef long long int ll;


ll N, A, B;
map<ll, ll> count;
ll c[MAX_N + 1][MAX_N + 1];
ll ans;

int main() {

  ll v, sum, p_count, used, diff;

  scanf("%lld%lld%lld", &N, &A, &B);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &v);
    count[v] = count[v] + 1;
  }

  memset(c, 0, sizeof(c));
  for (int i = 0; i <= N; i++) {
    c[i][0] = 1;
    c[i][i] = 1;
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j < i; j++) {
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
  }

  sum = 0;
  used = 0;
  auto itr = count.rbegin();
  for (; itr != count.rend(); itr++) {
    p_count = itr->second;
    if (used < A) {
      diff = min(itr->second, A - used);
      sum += itr->first * diff;
      used += diff;
      itr->second -= diff;
    }
    if (A <= used && used < B && (itr->first - ((double)sum / used)) >= EPS) {
      diff = min(itr->second, B - used);
      sum += itr->first * diff;
      used += diff;
      itr->second -= diff;
    }
    if (A <= used && used <= B && itr->first - ((double)sum / used) < EPS) {
      break;
    }
  }

  if (abs(itr->first - ((double)sum / used)) < EPS) {
    diff = min(itr->second, B - used);
    ans = 0;
    for (int i = 0; i <= diff; i++) {
      ans += c[p_count][itr->second - i];
    }
    sum += itr->first * diff;
    used += diff;
    itr->second -= diff;
  } else {
    ans = c[p_count][itr->second];
  }

  printf("%lf\n", (double)sum / used);
  printf("%lld\n", ans);

  return 0;

}


