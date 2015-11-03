// Paiza learning
// プログラミングスキルチェック
// C017:ハイアンドロー・カードゲーム

#include <cstdio>
#include <algorithm>
using namespace std;


struct Card {
  int a, b;
};

bool operator<(Card c1, Card c2) {
  return (c1.a == c2.a) ? (c1.b > c2.b) : (c1.a < c2.a);
}

int N;

int main() {

  Card parent, child;
  int a, b;

  scanf("%d%d", &a, &b);
  parent.a = a;
  parent.b = b;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &a, &b);
    child.a = a;
    child.b = b;
    printf("%s\n", child < parent ? "High" : "Low");
  }

  return 0;

}


