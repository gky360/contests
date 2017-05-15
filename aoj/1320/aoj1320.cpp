// ICPC Asia 2011 @ aoj
// F: City Merger

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX_N 14
#define INF ((int)1e8)
using namespace std;
typedef long long int ll;


int N, NS;
vector<string> names_pre, names;
int cost[MAX_N][MAX_N];
int dp[1 << MAX_N][MAX_N];

int solve_tsp() {
  for (int b = (1 << NS) - 1; b >= 0; b--) {
    fill(dp[b], dp[b] + NS, INF);
  }
  for (int i = 0; i < NS; i++) {
    dp[1 << i][i] = names[i].length();
  }

  for (int b = 0; b < (1 << NS); b++) {
    for (int from = 0; from < NS; from++) {
      if (!(b >> from) & 1) {
        continue;
      }
      for (int to = 0; to < NS; to++) {
        if ((b >> to) & 1) {
          continue;
        }
        dp[b | (1 << to)][to] = min(dp[b | (1 << to)][to], dp[b][from] + cost[from][to]);
      }
    }
  }

  return *min_element(dp[(1 << NS) - 1], dp[(1 << NS) - 1] + NS);
}

int main() {

  string s;
  bool contained;

  while ((cin >> N) && N) {
    names_pre.clear();
    names.clear();
    for (int i = 0; i < N; i++) {
      cin >> s;
      names_pre.push_back(s);
    }
    for (int i = 0; i < N; i++ ) {
      contained = false;
      for (int j = 0; j < N; j++) {
        if (i != j && names_pre[j].find(names_pre[i]) != string::npos) {
          contained = true;
          break;
        }
      }
      if (!contained) {
        names.push_back(names_pre[i]);
      }
    }
    NS = names.size();

    memset(cost, 0, sizeof(cost));
    for (int i = 0; i < NS; i++) {
      for (int j = 0; j < NS; j++) {
        for (int k = min(names[i].length(), names[j].length()); k >= 0; k--) {
          string sa = names[i].substr(names[i].length() - k);
          string sb = names[j].substr(0, k);
          if (sa == sb) {
            cost[i][j] = names[j].length() - k;
            break;
          }
        }
      }
    }

    cout << solve_tsp() << endl;
  }

  return 0;

}


