// AtCoder Indeedなう（オープンコンテストB）
// C - Palindrome Concatenation

#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX_N 5000
#define MAX_C 100000
#define INF ((ll)MAX_C * MAX_N)
using namespace std;


typedef long long int ll;

int N;
char S[MAX_N + 2];
int C[MAX_N + 1];
bool kaibun[MAX_N + 1];
ll dp[MAX_N + 1];

int main() {

  scanf("%d", &N);
  scanf("%s", S + 1);
  C[0] = 0;
  for (int i = 1; i <= N; i++) {
    scanf("%d", &C[i]);
  }

  dp[0] = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i - 1; j++) {
      kaibun[j] = kaibun[j + 1] && (S[i] == S[j]);
    }
    kaibun[i - 1] = (S[i - 1] == S[i]);
    kaibun[i] = true;

    dp[i] = INF;
    for (int j = 1; j <= i; j++) {
      if (kaibun[j]) {
        dp[i] = min(dp[j - 1] + C[i - j + 1], dp[i]);
      }
    }
  }

  printf("%lld\n", dp[N]);

  return 0;

}


