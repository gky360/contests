// Algorithms and Data Structures I
// 3 - Elementary data structures
// D - Areas on the Cross-Section Diagram

#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
#include <utility>
using namespace std;


typedef pair<int, int> P;

stack<int> slope;
// first: x, second: puddle
vector<P> puddles;

int puddle;
int sum;

int main() {

  char c;

  sum = 0;
  for (int i = 0; scanf("%c", &c) > 0 && c != '\n'; i++) {
    if (c == '\\') {
      slope.push(i);
    } else if (c == '/' && !slope.empty()) {
      puddle = i - slope.top();
      while (!puddles.empty() && slope.top() < puddles[puddles.size() - 1].first) {
        puddle += puddles[puddles.size() - 1].second;
        sum -= puddles[puddles.size() - 1].second;
        puddles.pop_back();
      }
      sum += puddle;
      puddles.push_back(P(i, puddle));
      slope.pop();
    }
  }

  printf("%d\n%d", sum, (int)puddles.size());
  for (int i = 0; i < puddles.size(); i++) {
    printf(" %d", puddles[i].second);
  }
  putchar('\n');

  return 0;

}


