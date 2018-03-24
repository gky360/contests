// AtCoder Regular Contest 073
// E - Ball Coloring

#include <cstdio>
#include <set>
#include <algorithm>
#define MAX_N 200000
#define INF ((ll)1e10)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;


int N;
pll xy[MAX_N];
multiset<ll> s;
ll ans;

int main() {

  ll s_s, s_l, l_s, l_l;

  scanf("%d", &N);
  s_s = s_l = INF;
  l_s = l_l = 0;
  for (int i = 0; i < N; i++) {
    scanf("%lld%lld", &xy[i].first, &xy[i].second);
    if (xy[i].first > xy[i].second) {
      swap(xy[i].first, xy[i].second);
    }
    s_s = min(s_s, xy[i].first);
    s_l = min(s_l, xy[i].second);
    l_s = max(l_s, xy[i].first);
    l_l = max(l_l, xy[i].second);
  }
  sort(xy, xy + N);

  ans = (l_s - s_s) * (l_l - s_l);

  for (int i = 0; i < N; i++) {
    s.insert(xy[i].first);
  }
  ans = min(ans, (l_l - s_s) * (*(s.rbegin()) - *(s.begin())));
  for (int i = 0; i < N; i++) {
    s.erase(s.find(xy[i].first));
    s.insert(xy[i].second);
    ans = min(ans, (l_l - s_s) * (*(s.rbegin()) - *(s.begin())));
  }

  printf("%lld\n", ans);

  return 0;

}


