// CODE FESTIVAL 2016 qual B
// B - Qualification simulator

#include <cstdio>
#define MAX_S 100000
using namespace std;


int N, A, B;
char s[MAX_S + 2];
int cnt_pass, cnt_b;

int main() {

  scanf("%d%d%d", &N, &A, &B);
  scanf("%s", s);
  cnt_pass = 0;
  cnt_b = 0;
  for (int i = 0; i < N; i++) {
    if (s[i] == 'a' && cnt_pass < A + B) {
      cnt_pass++;
      printf("Yes\n");
    } else if (s[i] == 'b' && cnt_pass < A + B && cnt_b < B) {
      cnt_pass++;
      cnt_b++;
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }

  return 0;

}


