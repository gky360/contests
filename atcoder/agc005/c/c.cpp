// AtCoder Grand Contest 005
// C - Tree Restoring

#include <cstdio>
#include <set>
#include <functional>
#define MAX_N 100
using namespace std;


int N;
multiset<int, greater<int> > A;

int main() {

  int a, r;

  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &a);
    A.insert(a);
  }

  r = *A.begin();
  for (int i = 0; i < r + 1; ++i) {
    if (A.find(r - (i / 2)) == A.end()) {
      printf("Impossible\n");
      return 0;
    }
    A.erase(A.find(r - (i / 2)));
  }

  if (A.size() > 0) {
    auto itr = A.end();
    itr--;
    if (*itr <= (r + 1) / 2) {
      printf("Impossible\n");
      return 0;
    }
  }

  printf("Possible\n");

  return 0;

}


