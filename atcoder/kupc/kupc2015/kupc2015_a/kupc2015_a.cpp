// 京都大学プログラミングコンテスト 2015 A - 東京都

#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

#define MAX_N 100


string str;
int ans;

int main() {

  char buff[MAX_N + 1];
  int a, b;
  int t;

  for (scanf("%d%*c", &t); t > 0; t--) {
    scanf("%s", buff);

    str = buff;
    ans = 0;
    int i = 0;
    while (i < str.length()) {
      a = str.find("tokyo", i);
      b = str.find("kyoto", i);
      if (a == string::npos) {
        a = MAX_N;
      }
      if (b == string::npos) {
        b = MAX_N;
      }
      i = min(a, b) + 5;
      if (a == MAX_N && b == MAX_N) {
        break;
      }
      ans++;
    }
    printf("%d\n", ans);
  }

  return 0;

}


