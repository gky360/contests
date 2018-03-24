// AtCoder Grand Contest 007
// E - Shik and Travel

#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX_N (1 << 17)
#define INF 1e18
using namespace std;
typedef long long int ll;


struct edge {
  int to;
  ll v;
};


int N;
vector<edge> g[MAX_N];
vector<vector<ll> > dp[MAX_N];

bool dfs(int n, ll max_v) {
  vector<vector<ll> > tmp_dp;
  int el, er;
  ll tmp_v1;

  if (g[n].empty()) {
    dp[n].push_back({ 0, 0 });
    return true;
  }
  if (!dfs(g[n][0].to, max_v) || !dfs(g[n][1].to, max_v)) {
    return false;
  }
  if (dp[g[n][0].to].size() < dp[g[n][1].to].size()) {
    el = 0; er = 1;
  } else {
    el = 1; er = 0;
  }
  for (vector<ll> vs0 : dp[g[n][el].to]) {
    for (int j0 = 0; j0 < 2; j0++) {
      ll new_vc1_min = INF;
      for (vector<ll> vs1 : dp[g[n][er].to]) {
        for (int j1 = 0; j1 < 2; j1++) {
          if (vs0[j0] + vs1[j1] + g[n][el].v + g[n][er].v <= max_v) {
            new_vc1_min = min(new_vc1_min, vs1[j1 ^ 1] + g[n][er].v);
          }
        }
      }
      if (new_vc1_min < INF) {
        tmp_dp.push_back({ vs0[j0 ^ 1] + g[n][el].v, new_vc1_min });
      }
    }
  }
  printf("dfs(%d, %lld)\n", n, max_v);
  sort(tmp_dp.begin(), tmp_dp.end());
  for (int i = 0; i < (int)tmp_dp.size(); i++) {
    printf("tmp_dp[%d] { %lld, %lld }\n", i, tmp_dp[i][0], tmp_dp[i][1]);
  }
  tmp_v1 = INF;
  for (int i = 0; i < (int)tmp_dp.size(); i++) {
    if (tmp_dp[i][1] < tmp_v1) {
      tmp_v1 = tmp_dp[i][1];
      dp[n].push_back(tmp_dp[i]);
    }
  }

  for (int i = 0; i < (int)dp[n].size(); i++) {
    printf(" dp[n][%d] { %lld, %lld }\n", i, dp[n][i][0], dp[n][i][1]);
  }

  return !dp[n].empty();
}


int main() {

  int a;
  ll l, r, m, v;

  scanf("%d", &N);
  for (int i = 1; i < N; i++) {
    scanf("%d%lld", &a, &v);
    g[a - 1].push_back((edge) { i, v });
  }

  l = -1;
  r = (ll)MAX_N * MAX_N;
  // (l, r]
  while (r - l > 1) {
    m = (r + l + 1) / 2;
    printf("%lld, %lld, %lld\n", l, r, m);
    for (int i = 0; i < N; i++) {
      dp[i].clear();
    }
    if (dfs(0, m)) {
      r = m;
    } else {
      l = m;
    }
  }

  printf("%lld\n", (r + l + 1) / 2);

  return 0;

}


