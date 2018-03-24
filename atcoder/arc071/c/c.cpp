// AtCoder Regular Contest 071
// C - 怪文書 / Dubious Document

#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX_N 50
#define ALPHABETS 26
using namespace std;
typedef long long int ll;


int N;
int cnt[ALPHABETS];

int main() {

  char s[MAX_N + 2];
  int tmp_count[ALPHABETS];

  scanf("%d", &N);
  fill(cnt, cnt + ALPHABETS, MAX_N);
  for (int i = 0; i < N; i++) {
    scanf("%*c%s", s);
    memset(tmp_count, 0, sizeof(tmp_count));
    for (int j = 0; j < strlen(s); j++) {
      tmp_count[s[j] - 'a']++;
    }
    for (int j = 0; j < ALPHABETS; j++) {
      cnt[j] = min(cnt[j], tmp_count[j]);
    }
  }

  for (int i = 0; i < ALPHABETS; i++) {
    for (int j = 0; j < cnt[i]; j++) {
      printf("%c", i + 'a');
    }
  }
  printf("\n");

  return 0;

}


