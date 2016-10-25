// CODE FESTIVAL 2016 qual C
// D - Friction

#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX_H 300
#define MAX_W 300
#define INF 100000000
using namespace std;


int H, W;
char c[MAX_H + 1][MAX_W + 3];
int f[MAX_H + 1][MAX_H + 1];
int dp[MAX_H + 1][MAX_H + 1];
int ans = 0;

int main() {

  scanf("%d%d", &H, &W);
  for (int i = H; i > 0; i--) {
    scanf("%s", &c[i][1]);
    c[i][0] = c[i][W + 1] = '*';
    c[i][W + 2] = '\0';
  }

  memset(f, 0, sizeof(f));
  ans = 0;
  for (int x = 0; x <= W; x++) {
    for (int y0 = 1; y0 <= H; y0++) {
      for (int y1 = 1; y1 <= H; y1++) {
        f[y0][y1] = f[y0 - 1][y1 - 1] + (c[H - y0 + 1][x] == c[H - y1 + 1][x + 1] ? 1 : 0);
      }
    }

    for (int y0 = H; y0 >= 0; y0--) {
      for (int y1 = H; y1 >= 0; y1--) {
        if (y0 == H && y1 == H) {
          dp[y0][y1] = 0;
          continue;
        }
        dp[y0][y1] = INF;
        if (y0 + 1 <= H) {
          dp[y0][y1] = min(dp[y0][y1], dp[y0 + 1][y1] + f[y0 + 1][y1]);
        }
        if (y1 + 1 <= H) {
          dp[y0][y1] = min(dp[y0][y1], dp[y0][y1 + 1] + f[y0][y1 + 1]);
        }
      }
    }
    ans += dp[0][0];
  }

  printf("%d\n", ans);

  return 0;

}


