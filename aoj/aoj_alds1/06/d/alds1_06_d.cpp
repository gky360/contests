// Algorithms and Data Structures I
// 06 - Sort II
// D - Minimum Cost Sort

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_N 1000
#define MAX_W 10000


int N;
int w[MAX_N], c[MAX_W + 1];
int ans;

int main() {

  int min_all, min_cycle;
  int element_count;
  int cycle_sum;
  bool visited[MAX_N];

  scanf("%d", &N);

  // 読み込みながら分布数えソート
  memset(c, 0, sizeof(c));
  min_all = MAX_W;
  for (int i = 0; i < N; i++) {
    scanf("%d", &w[i]);
    min_all = min(min_all, w[i]);
    c[w[i]]++;
  }
  for (int j = 0; j < MAX_W; j++) {
    c[j + 1] += c[j];
    c[j]--;
  }
  c[MAX_W]--;

  ans = 0;
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < N; i++) {
    if (visited[i]) {
      continue;
    }

    min_cycle = MAX_W;
    element_count = 0;
    cycle_sum = 0;
    int j = i;
    do {
      visited[j] = true;
      min_cycle = min(min_cycle, w[j]);
      element_count++;
      cycle_sum += w[j];
      j = c[w[j]];
    } while (j != i);

    ans += cycle_sum + (element_count - 2) * min_cycle;
    ans += min(0, -(element_count - 1) * (min_cycle - min_all) + 2 * (min_cycle + min_all));
  }

  printf("%d\n", ans);

  return 0;

}


