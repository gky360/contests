// CODE FESTIVAL 2016 qual A
// B - 仲良しうさぎ / Friendly Rabbits

#include <cstdio>
#define MAX_N 100000
using namespace std;


int N;
int a[MAX_N];
int ans;

int main() {

  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &a[i]);
    a[i]--;
  }

  ans = 0;
  for (int i = 0; i < N; i++) {
    if (a[a[i]] == i) {
      ans++;
    }
  }
  ans /= 2;

  printf("%d\n", ans);

  return 0;

}


