// AtCoder Regular Contest 070
// F - HonestOrUnkind

#include <cstdio>
#include <vector>
#define MAX_N 4000
using namespace std;
typedef long long int ll;


int A, B, N;
vector<int> path;
bool is_honest[MAX_N];

bool ask(int a, int b) {
  char c;

  printf("? %d %d\n", a, b);
  fflush(stdout);
  scanf("%*c%c", &c);
  return (c == 'Y');
}

int main() {

  scanf("%d%d", &A, &B);
  if (A <= B) {
    printf("Impossible\n");
    return 0;
  }
  N = A + B;

  for (int i = 0; i < N; i++) {
    if (path.empty()) {
      path.push_back(i);
      continue;
    }
    if (ask(path.back(), i)) {
      path.push_back(i);
    } else {
      path.pop_back();
    }
  }

  for (int i = 0; i < N; i++) {
    is_honest[i] = ask(path.back(), i);
  }

  printf("!");
  for (int i = 0; i < N; i++) {
    printf("%d", is_honest[i]);
  }
  printf("\n");


  return 0;

}


