// Paiza learning
// プログラミングスキルチェック
// C016:Leet文字列

#include <cstdio>
#include <algorithm>
using namespace std;

#define ALPHABETS 26
#define MAX_LENGTH 100


char table[ALPHABETS];
char str[MAX_LENGTH + 1];

int main() {

  for (int i = 0; i < ALPHABETS; i++) {
    table[i] = 'A' + i;
  }
  table['A' - 'A'] = '4';
  table['E' - 'A'] = '3';
  table['G' - 'A'] = '6';
  table['I' - 'A'] = '1';
  table['O' - 'A'] = '0';
  table['S' - 'A'] = '5';
  table['Z' - 'A'] = '2';

  scanf("%s", str);
  for (int i = 0; str[i] != '\0'; i++) {
    str[i] = table[str[i] - 'A'];
  }

  printf("%s\n", str);

  return 0;

}


