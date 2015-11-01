// Algorithms and Data Structures I
// 05 - Recursion / Divide and Conquer
// A - Exhaustive Search

#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 20


int N, Q;
int A[MAX_N];

bool can_make(int n, int m) {
  if (m == 0) {
    return true;
  } else if (m < 0 || n == N) {
    return false;
  }

  return can_make(n + 1, m) || can_make(n + 1, m - A[n]);
}

int main() {

  int m;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  scanf("%d", &Q);
  for (int i = 0; i < Q; i++) {
    scanf("%d", &m);
    printf("%s\n", can_make(0, m) ? "yes" : "no");
  }

  return 0;

}


