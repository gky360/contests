// Algorithms and Data Structures I
// 1 - Getting Started
// A - Insertion Sort

#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 100


int N;
int num[MAX_N];

int main() {

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &num[i]);
  }
  for (int i = 0; i < N; i++) {
    int j = i - 1;
    while (j >= 0 && num[j] > num[j + 1]) {
      swap(num[j], num[j + 1]);
      j--;
    }
    for (j = 0; j < N; j++) {
      printf("%d%c", num[j], (j == N - 1) ? '\n' : ' ');
    }
  }

  return 0;

}


