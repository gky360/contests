// AtCoder Regular Contest 062
// E - AtCoDeerくんと立方体づくり / Building Cubes with AtCoDeer

#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#define MAX_N 400
using namespace std;

typedef long long int ll;
typedef vector<int> Tile;


int N;
vector<Tile> tiles;
multiset<Tile> used;
ll ans;

Tile rotate(Tile t) {
  return { t[1], t[2], t[3], t[0] };
}

int main() {

  Tile t1, t2;
  int c;
  ll cnt, tmp;
  vector<Tile>::iterator itr1, itr2;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    Tile t;
    for (int j = 0; j < 4; j++) {
      scanf("%d", &c);
      t.push_back(c);
    }
    tiles.push_back(t);
  }

  sort(tiles.begin(), tiles.end());

  ans = 0;
  for (itr1 = tiles.begin(); itr1 != tiles.end(); itr1++) {
    for (itr2 = itr1, itr2++; itr2 != tiles.end(); itr2++) {
      t1 = *itr1; t2 = *itr2;
      for (int d = 0; d < 4; d++, t2 = rotate(t2)) {
        used.clear();
        used.insert(t1);
        used.insert(t2);
        cnt = 1;
        for (int i = 0; i < 4; i++) {
          tmp = 0;
          Tile t = { t1[(1 + i) % 4], t1[(0 + i) % 4], t2[(4 - i) % 4], t2[(7 - i) % 4] };
          for (int j = 0; j < 4; j++, t = rotate(t)) {
            tmp += upper_bound(tiles.begin(), tiles.end(), t) - lower_bound(tiles.begin(), tiles.end(), t);
            tmp -= used.count(t);
          }
          tmp = max(tmp, 0LL);
          cnt *= tmp;
          used.insert(t);
        }
        ans += cnt;
      }
    }
  }

  ans /= 3;
  printf("%lld\n", ans);

  return 0;

}


