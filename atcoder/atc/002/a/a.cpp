// AtCoder Typical Contenst 002
// A - 幅優先探索

#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

#define MAX_R 50
#define MAX_C 50


typedef struct {
  int x;
  int y;
  int count;
} te;

int C, R;
int sx, sy;
int gx, gy;
char board[MAX_C][MAX_R];
bool visited[MAX_C][MAX_R];
queue<te> q;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0};

int main() {

  te current_te, next_te;

  scanf("%d%d", &R, &C);
  scanf("%d%d", &sy, &sx);
  scanf("%d%d", &gy, &gx);
  sx--;
  sy--;
  gx--;
  gy--;
  for (int j = 0; j < R; j++) {
    scanf("%*c");
    for (int i = 0; i < C; i++) {
      scanf("%c", &board[i][j]);
    }
  }
  memset(visited, 0, sizeof(visited));

  current_te.x = sx;
  current_te.y = sy;
  current_te.count = 0;
  q.push(current_te);
  while (!q.empty()) {
    current_te = q.front();
    q.pop();
    if (current_te.x == gx && current_te.y == gy) {
      break;
    }
    if (visited[current_te.x][current_te.y]) {
      continue;
    }
    visited[current_te.x][current_te.y] = true;

    for (int k = 0; k < 4; k++) {
      next_te.x = current_te.x + dx[k];
      next_te.y = current_te.y + dy[k];
      next_te.count = current_te.count + 1;
      if (board[next_te.x][next_te.y] != '#') {
        q.push(next_te);
      }
    }
  }

  printf("%d\n", current_te.count);

  return 0;

}


