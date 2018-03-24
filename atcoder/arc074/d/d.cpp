// AtCoder Regular Contest 074
// D - 3N Numbers

#include <cstdio>
#include <queue>
#define MAX_N 100000
using namespace std;
typedef long long int ll;
typedef pair<ll, int> PLI;


int N;
ll a[3 * MAX_N];
priority_queue<ll, vector<ll>, greater<ll>> ql;
priority_queue<ll> qr;
ll suml[MAX_N + 1], sumr[MAX_N + 1];
ll ans;

int main() {

  scanf("%d", &N);
  for (int i = 0; i < 3 * N; i++) {
    scanf("%lld", &a[i]);
  }

  suml[0] = 0;
  sumr[N] = 0;
  for (int i = 0; i < N; i++) {
    suml[0] += a[i];
    ql.push(a[i]);

    sumr[N] += a[3 * N - i - 1];
    qr.push(a[3 * N - i - 1]);
  }

  for (int i = 1; i <= N; i++) {
    suml[i] = suml[i - 1];
    suml[i] += a[N - 1 + i];
    ql.push(a[N - 1 + i]);
    suml[i] -= ql.top();
    ql.pop();

    sumr[N - i] = sumr[N - i + 1];
    sumr[N - i] += a[2 * N - i];
    qr.push(a[2 * N - i]);
    sumr[N - i] -= qr.top();
    qr.pop();
  }

  ans = suml[0] - sumr[0];
  for (int i = 1; i <= N; i++) {
    ans = max(ans, suml[i] - sumr[i]);
  }

  printf("%lld\n", ans);

  return 0;

}


