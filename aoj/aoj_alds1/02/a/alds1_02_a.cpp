// Algorithms and Data Structures I
// 2 - Sort I
// A - Bubble Sort

#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 100


int N;
int num[MAX_N];
int cnt;

int main() {

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &num[i]);
  }

  cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = N - 1; j > i; j--) {
      if (num[j - 1] > num[j]) {
        swap(num[j - 1], num[j]);
        cnt++;
      }
    }
    printf("%d%c", num[i], (i == N - 1) ? '\n' : ' ');
  }

  printf("%d\n", cnt);

  return 0;

}


