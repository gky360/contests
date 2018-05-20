// ARC091
// D - Remainder Reminder

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int N, K;

int main() {
    cin >> N >> K;

    ll ans = 0;
    for (int b = K + 1; b <= N; b++) {
        ans += 1LL * N / b * (b - K);
        ans += max(0LL, N - (1LL * N / b * b + K - 1));
    }
    if (K == 0) {
        ans -= N;
    }

    cout << ans << endl;

    return 0;
}
