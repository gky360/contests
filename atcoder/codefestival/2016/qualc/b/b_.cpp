// CODE FESTIVAL 2016 qual C
// B - K個のケーキ / K Cakes

#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> PII;


int K, T;
priority_queue<PII> q;

int main() {

  int a, pre_t;
  PII p0, p1;

  scanf("%d%d", &K, &T);
  for (int i = 0; i < T; i++) {
    scanf("%d", &a);
    q.push(make_pair(a, i));
  }

  pre_t = -1;
  while (q.size() > 1) {
    p0 = q.top(); q.pop();
    p1 = q.top(); q.pop();
    if (pre_t == p0.second) {
      p1.first--;
      pre_t = p1.second;
    } else {
      p0.first--;
      pre_t = p0.second;
    }
    if (p0.first > 0) {
      q.push(p0);
    }
    if (p1.first > 0) {
      q.push(p1);
    }
  }

  printf("%d\n", (int)q.top().first - 1);

  return 0;

}


