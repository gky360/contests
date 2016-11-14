// AtCoder Grand Contest 007
// A - Shik and Stone

#include <cstdio>
#include <cstring>
#define MAX_H 8
#define MAX_W 8
using namespace std;


int H, W;
bool visited[MAX_H + 1][MAX_W + 1];
int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };

int main() {

  char c;
  int x, y;
  int remain;

  scanf("%d%d", &H, &W);
  memset(visited, false, sizeof(visited));
  remain = 0;
  for (int j = 0; j < H; j++) {
    scanf("%*c");
    for (int i = 0; i < W; i++) {
      scanf("%c", &c);
      visited[j][i] = (c == '#');
      remain += (c == '#') ? 1 : 0;
    }
  }

  x = 0;
  y = 0;
  remain--;
  while (visited[y + dy[0]][x + dx[0]] != visited[y + dy[1]][x + dx[1]]) {
    if (visited[y + dy[0]][x + dx[0]]) {
      x += dx[0];
      y += dy[0];
    } else {
      x += dx[1];
      y += dy[1];
    }
    remain--;
  }

  if (x == W - 1 && y == H - 1 && remain == 0) {
    printf("Possible\n");
  } else {
    printf("Impossible\n");
  }

  return 0;

}


