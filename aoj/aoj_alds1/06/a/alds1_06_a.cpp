// Algorithms and Data Structures I
// 06 - Sort II
// A - Counting Sort

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_N 2000000
#define MAX_A 10000


int A[MAX_N], B[MAX_N], C[MAX_A + 1];
int N;

int main() {

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  memset(C, 0, sizeof(C));

  for (int i = 0; i < N; i++) {
    C[A[i]]++;
  }
  for (int i = 0; i < MAX_A; i++) {
    C[i + 1] += C[i];
  }
  for (int i = 0; i < N; i++) {
    B[C[A[i]] - 1] = A[i];
    C[A[i]]--;
  }

  for (int i = 0; i < N; i++) {
    printf("%d%c", B[i], (i == N - 1) ? '\n' : ' ');
  }

  return 0;

}


