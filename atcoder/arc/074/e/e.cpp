// AtCoder Regular Contest 074
// E - RGB Sequence

#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<int, int> PII;

const int MAX_N = 300;
const int MAX_M = 300;
const ll MOD = 1e9 + 7;

int N, M;
ll dp[MAX_N + 1][MAX_N + 1][MAX_N + 1];
vector<PII> rules[MAX_N + 1];

ll f(int a, int b, int c) {
  int pos = max(max(a, b), c);
  if (dp[a][b][c] != -1) {
    return dp[a][b][c];
  }
  vector<int> w = {a, b, c};
  sort(w.begin(), w.end());
  for (PII &rule: rules[pos]) {
    for (int i = 0; i < 3; i++) {
      if (rule.first <= w[i]) {
        if (rule.second != 3 - i) {
          dp[a][b][c] = 0;
          return 0;
        }
        break;
      }
    }
  }
  if (pos == N) {
    dp[a][b][c] = 1;
    return 1;
  }
  dp[a][b][c] = (f(pos + 1, b, c) + f(a, pos + 1, c) + f(a, b, pos + 1)) % MOD;
  return dp[a][b][c];
}

int main() {

  int l, r, x;

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> l >> r >> x;
    rules[r].push_back(PII(l, x));
  }
  memset(dp, -1, sizeof(dp));

  cout << f(0, 0, 0) << endl;

  return 0;

}


