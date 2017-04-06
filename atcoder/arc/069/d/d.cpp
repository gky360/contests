// AtCoder Regular Contest 069
// D - Menagerie

#include <cstdio>
#define MAX_N 100000
using namespace std;
typedef long long int ll;


int N;
bool s[MAX_N];
bool ans[MAX_N];

int main() {

  char c;

  scanf("%d", &N);
  scanf("%*c");
  for (int i = 0; i < N; i++) {
    scanf("%c", &c);
    s[i] = (c == 'o');
  }

  for (int j0 = 0; j0 < 2; j0++) {
    for (int j1 = 0; j1 < 2; j1++) {
      ans[0] = j0;
      ans[1] = j1;
      for (int i = 2; i < N; i++) {
        ans[i] = (ans[i - 2] != (ans[i - 1] != s[i - 1]));
      }
      if (
        ans[0] == (ans[N - 2] != (ans[N - 1] != s[N - 1])) &&
        ans[1] == (ans[N - 1] != (ans[0] != s[0]))
      ) {
        for (int i = 0; i < N; i++) {
          printf("%c", ans[i] ? 'S' : 'W');
        }
        printf("\n");
        return 0;
      }
    }
  }

  printf("-1\n");

  return 0;

}


