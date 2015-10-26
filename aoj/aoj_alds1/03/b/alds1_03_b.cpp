// Algorithms and Data Structures I
// 3 - Elementary data structures
// B - Queue

#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_NAME_LENGTH 10


typedef pair<string, int> Process;

int N, Q;
queue<Process> q;

int main() {

  char name[MAX_NAME_LENGTH + 1];
  int t;

  scanf("%d%d", &N, &Q);
  for(int i = 0; i < N ; i++) {
    scanf("%*c%s %d", name, &t);
    q.push(Process(name, t));
  }

  t = 0;
  while (!q.empty()) {
    Process p = q.front();
    q.pop();
    if (p.second > Q) {
      t += Q;
      p.second -= Q;
      q.push(p);
    } else {
      t += p.second;
      printf("%s %d\n", p.first.c_str(), t);
    }
  }

  return 0;

}


