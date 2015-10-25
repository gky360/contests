// CODE FESTIVAL 2015 予選B D - マスと駒と色塗り/Squares, Pieces and Coloring

#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;


typedef long long int ll;
typedef pair<ll, ll> P;

int N;
map<ll, ll> m;

int main() {

  map<ll, ll>::iterator itr;
  ll s, c, orig;

  scanf("%d", &N);
  m.insert(P(0, 0));
  for (int i = 0; i < N; i++) {
    scanf("%lld%lld", &s, &c);

    itr = m.upper_bound(s);
    itr--;
    if (s < itr->first + itr->second) {
      orig = itr->first;
      s = itr->first + itr->second;
      m.erase(itr);
    } else {
      orig = s;
    }
    while (true) {
      itr = m.lower_bound(s);
      if (itr == m.end() || c <= itr->first - s) {
        m.insert(P(orig, s + c - orig));
        break;
      } else {
        c -= itr->first - s;
        s = itr->first + itr->second;
        m.erase(itr);
      }
    }
    printf("%lld\n", s + c - 1);
  }

  return 0;

}


