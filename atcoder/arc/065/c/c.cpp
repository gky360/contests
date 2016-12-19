// AtCoder Regular Contest 065
// C - 白昼夢 / Daydream

#include <cstdio>
#include <cstring>
#include <string>
#define MAX_S 100000
using namespace std;
typedef long long int ll;


char S[MAX_S + 2];
int len;
string strs[4] = { "dream", "dreamer", "erase", "eraser" };

bool dfs(int idx) {
  bool ret = false;
  bool matched = true;
  if (idx >= len) {
    return true;
  }
  for (int j = 0; j < 4; j++) {
    matched = true;
    for (int i = 0; i < (int)strs[j].size(); i++) {
      if ((idx + i >= len) || (S[idx + i] != strs[j][i])) {
        matched = false;
        break;
      }
    }
    ret = (matched && dfs(idx + strs[j].size())) || ret;
  }
  return ret;
}

int main() {

  scanf("%s", S);
  len = strlen(S);

  printf("%s\n", dfs(0) ? "YES" : "NO");

  return 0;

}


