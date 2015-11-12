// Algorithms and Data Structures I
// 06 - Sort II
// B - Partition

#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 100000


int a[MAX_N];
int N;

int main() {

  int x;
  int i, j;

  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  x = a[N - 1];
  i = 0;
  for (j = 0; j < N; j++) {
    if (a[j] <= x) {
      swap(a[i], a[j]);
      i++;
    }
  }
  i--;

  for (j = 0; j < N; j++) {
    printf("%s%d%s%c",
      (j == i) ? "[" : "",
      a[j],
      (j == i) ? "]" : "",
      (j == N - 1) ? '\n' : ' ');
  }

  return 0;

}


