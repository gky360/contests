// code thanks festival 2014 予選A E - 儀式

#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_R 50
#define MAX_C 50
#define MAX_N 5000


int R, C, M, N;
int flag[MAX_R + 1][MAX_C + 1];
int sum[MAX_R + 1][MAX_C + 1];
int r[2][MAX_N];
int c[2][MAX_N];
int dr[2] = {1, 0};
int dc[2] = {0, 1};

int main() {

  int count;

  scanf("%d%d%d%d", &R, &C, &M, &N);

  memset(flag, 0, sizeof(flag));
  for (int n = 0; n < N; n++) {
    scanf("%d%d%d%d", &r[0][n], &r[1][n], &c[0][n], &c[1][n]);
    r[0][n]--;
    c[0][n]--;
    flag[r[0][n]][c[0][n]]++;
    flag[r[0][n]][c[1][n]]--;
    flag[r[1][n]][c[0][n]]--;
    flag[r[1][n]][c[1][n]]++;
  }

  for (int rem = 0; rem < N; rem++) {
    flag[r[0][rem]][c[0][rem]]--;
    flag[r[0][rem]][c[1][rem]]++;
    flag[r[1][rem]][c[0][rem]]++;
    flag[r[1][rem]][c[1][rem]]--;

    memcpy(sum, flag, sizeof(sum));
    for (int k = 0; k < 2; k++) {
      for (int i = dr[k]; i <= R; i++) {
        for (int j = dc[k]; j <= C; j++) {
          sum[i][j] += sum[i - dr[k]][j - dc[k]];
        }
      }
    }

    count = 0;
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (sum[i][j] % 4 == 0) {
          count++;
        }
      }
    }

    if (count == M) {
      printf("%d\n", rem + 1);
    }

    flag[r[0][rem]][c[0][rem]]++;
    flag[r[0][rem]][c[1][rem]]--;
    flag[r[1][rem]][c[0][rem]]--;
    flag[r[1][rem]][c[1][rem]]++;
  }

  return 0;
}
