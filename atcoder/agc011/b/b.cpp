// AtCoder Grand Contest 011
// B - Colorful Creatures

#include <cstdio>
#include <queue>
#define MAX_N 100000
using namespace std;
typedef long long int ll;
typedef pair<ll, int> PLI;


int N;
priority_queue<PLI, vector<PLI>, greater<PLI> > q;

int main() {

  ll a;
  PLI c1, c2;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &a);
    q.push(make_pair(a, 1));
  }

  for (int i = 1; i < N; i++) {
    c1 = q.top(); q.pop();
    c2 = q.top(); q.pop();
    if (c1.first * 2 >= c2.first) {
      c2.second += c1.second;
    }
    c2.first += c1.first;
    q.push(c2);
  }
  printf("%d\n", q.top().second);

  return 0;

}


