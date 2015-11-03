// Paiza learning
// プログラミングスキルチェック
// C005:アドレス調査

#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define MAX_N 100


int M;

int main() {

  char buf[MAX_N + 1];
  string address;
  vector<string> elements;
  int prev_dot;
  bool valid;

  scanf("%d", &M);
  for (int i = 0; i < M; i++) {
    scanf("%s", buf);
    address = buf;
    address += '.';
    elements.clear();

    prev_dot = -1;
    valid = true;
    for (int i = 0; i < address.length(); i++) {
      if (address.at(i) == '.') {
        elements.push_back(address.substr(prev_dot + 1, i - (prev_dot + 1)));
        prev_dot = i;
      }
    }
    if (elements.size() != 4) {
      valid = false;
    } else {
      for (int i = 0; i < 4; i++) {
        if (elements[i].empty()) {
          valid = false;
          break;
        }
        if (stoi(elements[i]) > 255) {
          valid = false;
          break;
        }
      }
    }

    printf("%s\n", valid ? "True" : "False");
  }

  return 0;

}


