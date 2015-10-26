// Algorithms and Data Structures I
// 2 - Sort I
// C - Stable Sort

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_N 36


typedef pair<int, char> P;

int N;
P orig_cards[MAX_N], cards[MAX_N];

bool operator<(P p1, P p2) {
  return p1.first < p2.first;
}

void print_cards() {
  for (int i = 0; i < N; i++) {
    printf("%c%d%c", cards[i].second, cards[i].first, (i == N - 1) ? '\n' : ' ');
  }
}

int main() {

  int mini;
  char buff[3];

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%s", buff);
    orig_cards[i] = P(buff[1] - '0', buff[0]);
  }

  // Bubble Sort
  memcpy(cards, orig_cards, sizeof(P) * N);
  for (int i = 0; i < N; i++) {
    for (int j = N - 1; j > i; j--) {
      if (cards[j] < cards[j - 1]) {
        swap(cards[j - 1], cards[j]);
      }
    }
  }
  print_cards();
  printf("Stable\n");

  // Selection Sort
  swap(cards, orig_cards);
  for (int i = 0; i < N; i++) {
    mini = i;
    for (int j = i + 1; j < N; j++) {
      if (cards[j] < cards[mini]) {
        mini = j;
      }
    }
    if (i != mini) {
      swap(cards[i], cards[mini]);
    }
  }
  print_cards();

  for (int i = 0; i < N; i++) {
    if (cards[i] != orig_cards[i]) {
      printf("Not stable\n");
      return 0;
    }
  }
  printf("Stable\n");

  return 0;

}


