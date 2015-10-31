// Algorithms and Data Structures I
// 04 - Search
// C - Dictionary

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
using namespace std;


int N;
set<string> dic;

int main() {

  char buf[16], str[16];

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%s", buf);
    scanf("%s", str);
    if (strcmp(buf, "insert") == 0) {
      dic.insert(str);
    } else {
      if (dic.find(str) == dic.end()) {
        puts("no");
      } else {
        puts("yes");
      }
    }
  }

  return 0;

}


