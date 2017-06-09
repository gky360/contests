// AtCoder Regular Contest 075
// E - Meaningful Mean

#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<ll, int> PLI;

const int MAX_N = 200000;
const int MAX_BIT_IDX = MAX_N + 1;


template <typename T>
class BIT {
public:
  T b[MAX_BIT_IDX + 1];
  int n;
  void init(int num);
  T sum(int i);
  void add(int i, T x);
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


int N;
ll K;
PLI b[MAX_N + 1];
BIT<int> bit;
ll ans;

int main() {

    ll a;

    scanf("%d%lld", &N, &K);
    b[0] = PLI(0, 0);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &a);
        b[i].first = b[i - 1].first + a - K;
        b[i].second = i;
    }

    sort(b, b + N + 1);

    ans = 0;
    bit.init(N + 1);
    for (int i = 0; i <= N; i++) {
        ans += bit.sum(b[i].second + 1);
        bit.add(b[i].second + 1, 1);
    }

    printf("%lld\n", ans);

    return 0;

}



