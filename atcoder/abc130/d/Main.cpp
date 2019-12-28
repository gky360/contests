/*
[abc130] D - Enough Array
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;

int N;
ll K;
int a[MAX_N];

ll solve() {
    ll s = 0;
    int r = 0;
    ll ans = 0;
    for (int l = 0; l < N; l++) {
        while (r < N && s < K) {
            s += a[r];
            r++;
        }
        if (s >= K) {
            ans += N - r + 1;
        }

        s -= a[l];
    }

    return ans;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << solve() << endl;

    return 0;
}
