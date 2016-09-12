// AtCoder Regular Contest 061
// D - すぬけ君の塗り絵 / Snuke's Coloring

#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef long long int ll;

ll W, H;
int N;
map<pii, int> m;
ll ans[10];


bool is_in_range(int x, int y) {
  return (0 <= x) && (x < W) && (0 <= y) && (y < H);
}

int main() {

  int x, y;
  pii p;

  scanf("%lld%lld%d", &H, &W, &N);
  for (int n = 0; n < N; n++) {
    scanf("%d%d", &y, &x);
    x--;
    y--;
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        p.first = x + i;
        p.second = y + j;
        if (is_in_range(p.first - 1, p.second - 1) && is_in_range(p.first + 1, p.second + 1)) {
          m[p] = m[p] + 1;
        }
      }
    }
  }

  for (auto itr = m.begin(); itr != m.end(); itr++) {
    ans[itr->second]++;
  }
  ans[0] = (H - 2) * (W - 2) - accumulate(ans + 1, ans + 10, (ll)0);

  for (int i = 0; i < 10; i++) {
    printf("%lld\n", ans[i]);
  }

}


