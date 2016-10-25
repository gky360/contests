// CODE FESTIVAL 2016 qual C
// E - 順列辞書 / Encyclopedia of Permutations

#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX_N 500000
#define MOD 1000000007LL
#define MAX_BIT_IDX MAX_N
using namespace std;

typedef long long int ll;


template <typename T>
class BIT {
public:
  T b[MAX_BIT_IDX + 1];
  int n;
private:
public:
  void init(int num);
  T sum(int i);
  void add(int i, T x);
private:
};

template <typename T>
void BIT<T>::init(int num) {
  n = num;
  for (int i = 0; i <= n; i++) {
    b[i] = 0;
  }
  return;
}

template <typename T>
T BIT<T>::sum(int i) {
  T s = 0;

  for (; i > 0; i -= i & -i) {
    s += b[i];
  }
  return s;
}

template <typename T>
void BIT<T>::add(int i, T x) {
  for (; i <= n; i += i & -i) {
    b[i] += x;
  }
  return;
}


int N, K;
int P[MAX_N];
int cnt_less[MAX_N + 1];
ll sum_unused, sum_cnt_more;
ll fac[MAX_N + 1];
BIT<int> bit;
ll ans;

int main() {

  ll t1, t2, cur_k;
  ll inv2 = (MOD + 1) / 2;

  scanf("%d", &N);
  fill(cnt_less, cnt_less + N, 1); cnt_less[0] = 0;
  fac[0] = 1;
  for (int i = 1; i <= N; i++) {
    fac[i] = (fac[i - 1] * i) % MOD;
  }
  bit.init(N);

  sum_unused = (ll)N * (N + 1) / 2 % MOD;
  for (int i = 0; i < N; i++) {
    scanf("%d", &P[i]);
    if (P[i] == 0) {
      K++;
    } else {
      cnt_less[P[i]] = 0;
      sum_unused = (sum_unused - P[i] + MOD) % MOD;
    }
  }
  for (int i = 1; i <= N; i++) {
    cnt_less[i] += cnt_less[i - 1];
  }

  cur_k = 0;
  sum_cnt_more = 0;
  ans = 0;
  for (int i = 0; i < N; i++) {
    if (P[i] == 0) {
      t1 = (sum_unused * fac[K - 1] - fac[K] + MOD) % MOD;
      t2 = (sum_cnt_more * fac[K - 1] % MOD + cur_k * fac[K] % MOD * inv2 % MOD) % MOD;
      cur_k++;
    } else {
      t1 = (P[i] - 1) * fac[K] % MOD;
      t2 = ((ll)bit.sum(P[i]) * fac[K] % MOD + cur_k * cnt_less[P[i] - 1] % MOD * fac[max(K - 1, 0)] % MOD) % MOD;
      sum_cnt_more = (sum_cnt_more + K - cnt_less[P[i]]) % MOD;
      bit.add(P[i], 1);
    }
    ans = (ans + (t1 - t2 + MOD) % MOD * fac[N - 1 - i]) % MOD;
  }
  ans = (ans + fac[K]) % MOD;

  printf("%lld\n", ans);

  return 0;

}


