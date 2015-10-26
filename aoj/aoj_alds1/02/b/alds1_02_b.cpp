// Algorithms and Data Structures I
// 2 - Sort I
// B - Selection Sort

#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 100


int N;
int a[MAX_N];
int cnt;

int main() {

  int mini;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  cnt = 0;
  for (int i = 0; i < N; i++) {
    mini = i;
    for (int j = i + 1; j < N; j++) {
      if (a[j] < a[mini]) {
        mini = j;
      }
    }
    if (i != mini) {
      swap(a[i], a[mini]);
      cnt++;
    }
    printf("%d%c", a[i], (i == N - 1) ? '\n' : ' ');
  }
  printf("%d\n", cnt);

  return 0;

}


