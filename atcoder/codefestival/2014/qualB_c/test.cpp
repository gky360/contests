#include <cstdio>
#include <cstring>
#include <random>
using namespace std;

#define MAX_S 100000


int main() {
  char str[MAX_S + 1];

  for (int j = 0; j < 3; j++) {
    std::random_device rnd;     // 非決定的な乱数生成器を生成
    std::mt19937 mt(rnd());     //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
    std::uniform_int_distribution<> rand26(0, 26 - 1);        // [0, 26 - 1] 範囲の一様乱数
    for (int i = 0; i < MAX_S; i++) {
      str[i] = 'A' + rand26(mt);
    }
    str[MAX_S] = '\0';
    printf("%s\n", str);
  }

  return 0;
}
