// Algorithms and Data Structures I
// 2 - Sort I
// D - Shell Sort

#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

#define MAX_N 1000000


int N;
int a[MAX_N];
int cnt;

void insertion_sort(int g) {
  int tmp;

  for (int i = 0; i < N; i++) {
    tmp = a[i];
    int j = i - g;
    while (j >= 0 && a[j] > tmp) {
      a[j + g] = a[j];
      j -= g;
      cnt++;
    }
    a[j + g] = tmp;
  }
}

int main() {

  stack<int> s;
  int g;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  s.push(1);
  for (g = 4; g < N; g = 3 * g + 1) {
    s.push(g);
  }

  printf("%d\n", (int)s.size());

  cnt = 0;
  while (!s.empty()) {
    printf("%d%c", s.top(), (s.size() == 1) ? '\n' : ' ');
    insertion_sort(s.top());
    s.pop();
  }

  printf("%d\n", cnt);

  for (int i = 0; i < N; i++) {
    printf("%d\n", a[i]);
  }

  return 0;

}


