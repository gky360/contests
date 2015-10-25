// 京都大学プログラミングコンテスト 2015 

#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 30
#define INF 100000000

int N;
int g[MAX_N][MAX_N];
bool ans;

int main() {

  int t;

  for (scanf("%d", &t); t > 0; t--) {
    scanf("%d", &N);
    ans = true;

    for (int j = 0; j < N; j++) {
      for (int i = 0; i < N; i++) {
        scanf("%d", &g[i][j]);
        if (g[i][j] == -1) {
          g[i][j] = INF;
        }
      }
      if (g[j][j] > 0) {
        ans = false;
      }
    }

    for (int k = 0; k < N; k++) {
      if (!ans) {
        break;
      }
      for (int j = 0; j < N; j++) {
        if (!ans) {
          break;
        }
        for (int i = 0; i < N; i++) {
          if (g[i][j] > g[i][k] + g[k][j]) {
            ans = false;
            break;
          }
        }
      }
    }

    printf("%s\n", ans ? "YES" : "NO");
  }

  return 0;

}


