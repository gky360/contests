/*
[nikkei2019-final] C - Come Together
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_H = 1e5;
const int MAX_K = 1e5;
const ll INF = 1e18;

int HW[2], K;
int RC[2][MAX_K];

ll solve() {
    ll ans = 0;

    for (int d = 0; d < 2; d++) {
        ll s[MAX_H + 1], c[MAX_H + 1];
        memset(s, 0, sizeof(s));
        memset(c, 0, sizeof(c));
        for (int i = 0; i < K; i++) {
            s[RC[d][i]] += RC[d][i];
            c[RC[d][i]]++;
        }
        for (int i = 0; i < HW[d]; i++) {
            s[i + 1] += s[i];
            c[i + 1] += c[i];
        }

        ll cand = INF;
        for (ll i = 1; i <= HW[d]; i++) {
            ll l = (i - 1) * i / 2 * HW[d ^ 1] - (c[i - 1] * i - s[i - 1]);
            ll r = (HW[d] - i) * (HW[d] - i + 1) / 2 * HW[d ^ 1] -
                   (s[HW[d]] - s[i] - (c[HW[d]] - c[i]) * i);
            cand = min(cand, l + r);
        }
        ans += cand;
    }

    return ans;
}

int main() {
    cin >> HW[0] >> HW[1] >> K;
    for (int i = 0; i < K; i++) {
        cin >> RC[0][i] >> RC[1][i];
    }

    cout << solve() << endl;

    return 0;
}
