// Algorithms and Data Structures I
// 3 - Elementary data structures
// A - Stack

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <stack>
using namespace std;


stack<int> s;

int main() {

  int l, r;
  char buff[10];

  while (scanf("%s", buff) > 0) {
    if (isdigit(buff[0])) {
      s.push(atoi(buff));
    } else {
      r = s.top(); s.pop();
      l = s.top(); s.pop();
      switch (buff[0]) {
      case '+':
        s.push(l + r);
        break;
      case '-':
        s.push(l - r);
        break;
      case '*':
        s.push(l * r);
        break;
      }
    }
  }

  printf("%d\n", s.top());

  return 0;

}


