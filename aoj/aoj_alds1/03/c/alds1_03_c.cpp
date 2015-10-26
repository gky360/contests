// Algorithms and Data Structures I
// 3 - Elementary data structures
// C - Doubly Linked List

#include <cstdio>
#include <string>
#include <algorithm>
#include <list>
using namespace std;


int N;
list<int> l;

int main() {

  int x;
  char tmp[16];
  string cmd;
  list<int>::iterator itr;

  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%s", tmp);
    cmd = tmp;
    if (cmd == "insert") {
      scanf("%d", &x);
      l.push_front(x);
    } else if (cmd == "delete") {
      scanf("%d", &x);
      for (itr = l.begin(); itr != l.end(); itr++) {
        if (*itr == x) {
          l.erase(itr);
          break;
        }
      }
    } else if (cmd == "deleteFirst") {
      l.pop_front();
    } else if (cmd == "deleteLast") {
      l.pop_back();
    }
  }

  itr = l.begin();
  while (true) {
    printf("%d", *itr);
    itr++;
    if (itr == l.end()) {
      putchar('\n');
      break;
    } else {
      putchar(' ');
    }
  }

  return 0;

}


