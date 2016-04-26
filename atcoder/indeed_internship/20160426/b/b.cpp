// AtCoder Indeed internship 2016 0426
// B - 順列

#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX_N 100000
using namespace std;


int N;
pair<int, int> P[MAX_N];
bool visited[MAX_N];
int ans;

int main() {

  int p;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &p);
    P[i].first = p - 1;
    P[i].second = i;
  }
  sort(P, P + N);

  memset(visited, 0, sizeof(visited));
  ans = 0;
  for (int i = 0; i < N; i++) {
    if (visited[i]) {
      continue;
    }
    ans++;
    int j = i;
    while (!visited[j]) {
      visited[j] = true;
      j = P[j].second;
    }
  }

  printf("%d\n", ans);

  return 0;

}


