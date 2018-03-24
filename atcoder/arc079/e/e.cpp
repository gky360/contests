// AtCoder Regular Contest 079
// E - Decrease (Judge ver.)

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_N = 50;
const ll MAX_A = (ll)1e16 + 1000;

int N;
ll a[MAX_N];

ll can(ll k) {
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        sum += (max(a[i] + k - (N - 1), 0LL) + N) / (N + 1);
    }
    return sum <= k;
}

int main() {

    ll sum_a = 0;
    ll ans;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        sum_a += a[i];
    }

    for (ll k = max(sum_a - (N - 1) * N, 0LL); k <= MAX_A * N; k++) {
        if (can(k)) {
            ans = k;
            break;
        }
    }

    cout << ans << endl;

    return 0;

}



