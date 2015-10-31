// Algorithms and Data Structures I
// 04 - Search
// B - Binary Search

#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 100000


int N, Q;
int S[MAX_N];
int ans;

int main() {

  int t;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &S[i]);
  }
  sort(S, S + N);

  scanf("%d", &Q);
  for (int j = 0; j < Q; j++) {
    scanf("%d", &t);
    if (binary_search(S, S + N, t)) {
      ans++;
    }
  }

  printf("%d\n", ans);

  return 0;

}


