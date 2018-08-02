// AGC023
// A - Zero-Sum Ranges

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 200000;
const ll INF = 1e18;

int N;
int a[MAX_N];

ll comb2(int n) { return 1LL * n * (n - 1LL) / 2LL; }

ll solve() {
    ll s[MAX_N + 2];

    s[0] = 0;
    for (int i = 0; i < N; i++) {
        s[i + 1] = s[i] + a[i];
    }
    sort(s, s + N + 1);
    s[N + 1] = INF;

    ll ans = 0;
    int prev_i = 0;
    ll prev_s = s[0];
    for (int i = 1; i <= N + 1; i++) {
        if (s[i] != prev_s) {
            ans += comb2(i - prev_i);
            prev_i = i;
            prev_s = s[i];
        }
    }
    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << solve() << endl;

    return 0;
}
