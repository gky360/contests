// AtCoder Regular Contest 069
// E - Frequency

#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX_N 100000
using namespace std;
typedef long long int ll;
typedef pair<ll, int> PLI;


int N;
PLI m[MAX_N + 1];
ll ans[MAX_N];

int main() {

  ll cnt;
  int min_i;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &m[i].first);
    m[i].second = i;
  }
  m[N] = PLI(0, -1);
  memset(ans, 0, sizeof(ans));
  sort(m, m + N + 1);

  min_i = N;
  cnt = 0;
  for (int i = N; i > 0; i--) {
    min_i = min(min_i, m[i].second);
    ans[min_i] += (m[i].first - m[i - 1].first) * (cnt + 1);
    cnt++;
  }

  for (int i = 0; i < N; i++) {
    printf("%lld\n", ans[i]);
  }

  return 0;

}


