// Algorithms and Data Structures I
// 1 - Getting Started
// C - Prime Numbers

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_N 10000
#define MAX_E 10000


int N;
bool table[MAX_E + 1];
vector<int> primes;
int ans;

int main() {

  bool is_prime;
  int num;

  memset(table, 0, sizeof(table));
  ans = 0;
  for (int i = 2; i <= MAX_E; i++) {
    if (table[i]) {
      continue;
    }
    primes.push_back(i);
    for (int j = i * 2; j <= MAX_E; j += i) {
      table[j] = true;
    }
  }

  scanf("%d", &N);
  ans = 0;
  for (int i = 0; i < N; i++) {
    scanf("%d", &num);
    is_prime = true;
    for (int j = 0; j < primes.size() && primes[j] * primes[j] <= num; j++) {
      if (num % primes[j] == 0) {
        is_prime = false;
        break;
      }
    }
    if (is_prime) {
      ans++;
    }
  }

  printf("%d\n", ans);

  return 0;

}


