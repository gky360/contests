// CODE FESTIVAL 2016 qual B
// C - Gr-idian MST

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#define MAX_W 100000
#define MAX_H 100000
using namespace std;

typedef long long int ll;


int W, H;
pair<int, int> costs[MAX_W + MAX_H];
int cnt[2];
ll ans;

int main() {

  scanf("%d %d", &W, &H);
  for (int x = 0; x < W; x++) {
    scanf("%d", &costs[x].first);
    costs[x].second = 0;
  }
  for (int y = 0; y < H; y++) {
    scanf("%d", &costs[W + y].first);
    costs[W + y].second = 1;
  }

  sort(costs, costs + W + H);

  cnt[0] = 0;
  cnt[1] = 0;
  ans = 0;
  for (int i = 0; i < W + H; i++) {
    if (costs[i].second == 0) {
      ans += (ll)(H + 1 - cnt[1]) * (ll)costs[i].first;
      cnt[0]++;
    } else {
      ans += (ll)(W + 1 - cnt[0]) * (ll)costs[i].first;
      cnt[1]++;
    }
  }
  printf("%lld\n", ans);

  return 0;

}


