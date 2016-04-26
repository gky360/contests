// AtCoder Indeed internship 2016 0426
// D - 色付きボール

#include <cstdio>
#include <cmath>
#define MAX_K 10
#define MAX_A 1000
#define MAX_N (MAX_K * MAX_A)
#define EPS 1e-8
using namespace std;


int K, N;
int A[MAX_K];
double dp[(1 << MAX_K)][MAX_N + 1];
double ans;

double calc(int b, int n) {
  int k = 0;
  for (int i = 0; i < K; i++) {
    if (b & (1 << i)) {
      k++;
    }
  }
  if (n < k) {
    dp[b][n % 2] = 0.0;
    return dp[b][n % 2];
  }
  if (k == 1) {
    int i;
    for (i = 0; i < K; i++) {
      if (b & (1 << i)) {
        break;
      }
    }
    dp[b][n % 2] = pow((double)A[i] / N, n);
    return dp[b][n % 2];
  }

  double sum = 0.0;
  dp[b][n % 2] = 0.0;
  for (int i = 0; i < K; i++) {
    if ((b & (1 << i)) == 0) {
      continue;
    }
    sum += A[i];
    int sub = b - (b & (1 << i));
    dp[b][n % 2] += dp[sub][(n - 1) % 2] * (double)A[i] / N;
  }
  dp[b][n % 2] += dp[b][(n - 1) % 2] * sum / N;
  return dp[b][n % 2];
}

int main() {

  scanf("%d", &K);
  N = 0;
  for (int i = 0; i < K; i++) {
    scanf("%d", &A[i]);
    N += A[i];
  }

  ans = 0.0;
  for (int n = 1; ; n++) {
    double pre_ans = ans;
    for (int b = 0; b < (1 << K); b++) {
      calc(b, n - 1);
    }
    for (int i = 0; i < K; i++) {
      ans += n * calc((1 << K) - 1 - (1 << i), n - 1) * (double)A[i] / N;
    }
    if (ans - pre_ans < EPS && n > K) {
      break;
    }
  }

  printf("%.8lf\n", ans);

  return 0;

}


