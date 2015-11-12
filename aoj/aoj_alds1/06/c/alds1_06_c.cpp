// Algorithms and Data Structures I
// 06 - Sort II
// C - Quick Sort

#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 100000


struct Card {
  char suit;
  int num;
};

Card a[MAX_N], b[MAX_N];
int N;

bool operator<(Card c1, Card c2) {
  return c1.num < c2.num;
}

bool operator<=(Card c1, Card c2) {
  return c1.num <= c2.num;
}

// [p, r]
int part(int p, int r) {
  Card x;
  int i, j;

  x = a[r];
  i = p;
  for (j = p; j <= r; j++) {
    if (a[j] <= x) {
      swap(a[i], a[j]);
      i++;
    }
  }

  return i - 1;
}

void quick_sort(int p, int r) {
  if (p >= r) {
    return;
  }
  int q = part(p, r);
  quick_sort(p, q - 1);
  quick_sort(q + 1, r);
  return;
}

int main() {

  bool is_stable;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%*c%c%d", &a[i].suit, &a[i].num);
    b[i] = a[i];
  }

  quick_sort(0, N - 1);
  stable_sort(b, b + N);

  is_stable = true;
  for (int i = 0; i < N; i++) {
    is_stable = is_stable && (a[i].suit == b[i].suit);
  }
  printf("%s\n", (is_stable) ? "Stable" : "Not stable");
  for (int i = 0; i < N; i++) {
     printf("%c %d\n", a[i].suit, a[i].num);
  }

  return 0;

}


