// AtCoder Regular Contest 073
// D - Simple Knapsack

#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX_WD 3
using namespace std;
typedef long long int ll;


int N;
ll W, W1;
vector<int> vs[MAX_WD + 1];
ll ans;

void sel(int *cnt, int wd, ll w_sum) {
  ll v_sum;
  if (w_sum > W) {
    return;
  }
  if (wd > MAX_WD) {
    v_sum = 0;
    for (int j = 0; j <= MAX_WD; j++) {
      if (cnt[j] == 0) {
        continue;
      }
      v_sum += vs[j][cnt[j] - 1];
    }
    ans = max(ans, v_sum);
    return;
  }

  for (int i = 0; i <= (int)vs[wd].size(); i++) {
    cnt[wd] = i;
    sel(cnt, wd + 1, w_sum + (W1 + wd) * cnt[wd]);
  }
  return;
}

int main() {

  ll w;
  int v;
  int cnt[MAX_WD + 1];

  scanf("%d%lld", &N, &W);
  for (int i = 0; i < N; i++) {
    scanf("%lld%d", &w, &v);
    if (i == 0) {
      W1 = w;
    }
    vs[w - W1].push_back(v);
  }
  for (int j = 0; j <= MAX_WD; j++) {
    sort(vs[j].rbegin(), vs[j].rend());
    for (int i = 1; i < (int)vs[j].size(); i++) {
      vs[j][i] += vs[j][i - 1];
    }
  }

  ans = 0;
  sel(cnt, 0, 0);

  printf("%lld\n", ans);

  return 0;

}


