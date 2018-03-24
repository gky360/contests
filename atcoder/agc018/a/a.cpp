// AtCoder Grand Contest 018
// A - Getting Difference

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


int N;
ll K;

ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}


int main() {

    ll a, max_a;
    ll res;

    cin >> N >> K;
    cin >> res;
    max_a = res;
    for (int i = 1; i < N; i++) {
        cin >> a;
        max_a = max(max_a, a);
        res = gcd(res, a);
    }
    cout << ((K <= max_a) && (K % res == 0) ? "POSSIBLE" : "IMPOSSIBLE") << endl;

    return 0;

}



