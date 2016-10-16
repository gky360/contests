// Kyoto University Programming Contest 2016
// D - 長い黒板 / Long Blackboard

#include <cstdio>
#include <deque>
#include <string>
#define R 2
using namespace std;


int N;
deque<char> d[2];

int main() {

  char c;
  char buff[256];
  bool dir, updated;

  scanf("%d", &N);
  dir = true;
  for (int n = 0; n < N; n++) {
    updated = false;
    for (int b = 0; b < (1 << R); b++) {
      for (int j = 0; j < R; j++) {
        c = (b & (1 << j)) > 0 ? '#' : '.';
        if (dir) {
          d[j].push_back(c);
        } else {
          d[j].push_front(c);
        }
        printf("%s\n", string(d[j].begin(), d[j].end()).c_str());
      }
      fflush(stdout);
      scanf("%s", buff);
      if (buff[0] == 'T') {
        updated = true;
        break;
      } else if (buff[0] != 'F') {
        return 0;
      }
      for (int j = 0; j < R; j++) {
        if (dir) {
          d[j].pop_back();
        } else {
          d[j].pop_front();
        }
      }
    }
    if (!updated) {
      dir = !dir;
      n--;
    }
  }

  return 0;

}


