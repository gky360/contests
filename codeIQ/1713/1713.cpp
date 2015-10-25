// CodeIQ 1713
// 平方数で表す平方数

#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_N 100000


int n;
int table[MAX_N + 1];
int sq[4];
int ans;

int sum_sq() {
  int sum;
  int i;

  sum = 0;
  for (i = 0; i < 4; i++) {
    sum += sq[i] * sq[i];
  }

  return sum;
}

int main () {

  int i;

  scanf("%d", &n);

  memset(table, 0, sizeof(table));
  sq[0] = sq[1] = sq[2] = sq[3] = 1;
  for (sq[0] = 1; sum_sq() <= n; sq[0]++) {
    for (sq[1] = sq[0]; sum_sq() <= n; sq[1]++) {
      for (sq[2] = sq[1]; sum_sq() <= n; sq[2]++) {
        for (sq[3] = sq[2]; sum_sq() <= n; sq[3]++) {
          table[sum_sq()]++;
        }
        sq[3] = 1;
      }
      sq[2] = 1;
    }
    sq[1] = 1;
  }

  ans = 0;
  for (i = 1; i * i <= n; i++) {
    if (table[i * i] == 1) {
      ans++;
    }
  }

  printf("%d\n", ans);

  return 0;

}


