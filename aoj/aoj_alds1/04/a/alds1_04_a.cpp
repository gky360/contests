// Algorithms and Data Structures I
// 04 - Search
// A - Linear Search

#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 10000
#define MAX_Q 500

int N, Q;
int S[MAX_N];
int ans;

int main() {

  int t;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &S[i]);
  }

  scanf("%d", &Q);
  for (int j = 0; j < Q; j++) {
    scanf("%d", &t);
    for (int i = 0; i < N; i++) {
      if (S[i] == t) {
        ans++;
        break;
      }
    }
  }

  printf("%d\n", ans);

  return 0;

}


