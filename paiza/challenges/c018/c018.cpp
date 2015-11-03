// Paiza learning
// プログラミングスキルチェック
// C018:何人前作れる？

#include <cstdio>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

#define MAX_N 100
#define MAX_M 100
#define INF 100000000


typedef pair<string, int> P;

P recipe[MAX_N];
P my[MAX_M];
int N, M;
int ans;

int main() {

  char buf[16];
  int num;
  int i, j;

  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%s%d", buf, &num);
    recipe[i].first = buf;
    recipe[i].second = num;
  }
  scanf("%d", &M);
  for (j = 0; j < M; j++) {
    scanf("%s%d", buf, &num);
    my[j].first = buf;
    my[j].second = num;
  }

  sort(recipe, recipe + N);
  sort(my, my + M);

  j = 0;
  ans = INF;
  for (i = 0; i < N; i++) {
    while (j < M && my[j].first != recipe[i].first) {
      j++;
    }
    if (j == M) {
      ans = 0;
      break;
    }
    ans = min(ans, my[j].second / recipe[i].second);
  }

  printf("%d\n", ans);

  return 0;

}


