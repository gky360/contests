// AtCoder Regular Contest 067
// C - Factors of Factorial

#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#define MAX_N 1000
#define MOD ((ll)1e9 + 7)
using namespace std;
typedef long long int ll;


int N;
bool is_not_prime[MAX_N + 1];
vector<int> primes;
map<int, int> factors;
ll ans;


int main() {

  int n;

  scanf("%d", &N);

  memset(is_not_prime, 0, sizeof(is_not_prime));
  for (int i = 2; i <= N; i++) {
    if (is_not_prime[i]) {
      continue;
    }
    primes.push_back(i);
    for (int j = 1; i * j <= N; j++) {
      is_not_prime[i * j] = true;
    }
  }

  for (int i = 2; i <= N; i++) {
    n = i;
    for (int j = 0; j < (int)primes.size(); j++) {
      while (n % primes[j] == 0) {
        factors[primes[j]] = factors[primes[j]] + 1;
        n /= primes[j];
      }
    }
  }

  ans = 1;
  for (auto itr = factors.begin(); itr != factors.end(); itr++) {
    ans *= itr->second + 1;
    ans %= MOD;
  }

  printf("%lld\n", ans);

  return 0;

}


