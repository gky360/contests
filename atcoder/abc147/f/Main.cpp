/*
[abc147] F - Sum Difference
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int N;
ll X, D;

ll calc(vector<pll> &secs) {
    vector<ll> v;
    for (pll &sec : secs) {
        v.push_back(sec.first);
        v.push_back(sec.second);
    }
    sort(ALL(v));
    v.erase(unique(ALL(v)), v.end());

    int K = v.size();
    vector<int> s(K + 1);
    for (pll &sec : secs) {
        int l = lower_bound(ALL(v), sec.first) - v.begin();
        int r = lower_bound(ALL(v), sec.second) - v.begin();
        s[l]++;
        s[r]--;
    }
    for (int i = 1; i <= K; i++) {
        s[i] += s[i - 1];
    }

    ll ret = 0;
    for (int i = 0; i < K; i++) {
        if (s[i] > 0) {
            ret += v[i + 1] - v[i];
        }
    }
    return ret;
}

ll solve() {
    if (D == 0) {
        if (X == 0) {
            return 1;
        }
        return N + 1;
    }
    if (D < 0) {
        D = -D, X = -X;
    }

    map<int, vector<pll>> msecs;
    for (int k = 0; k <= N; k++) {
        int m = (k * X) % D;
        (m += D) %= D;
        ll t = (k * X - m) / D;
        msecs[m].push_back(
            {t + k * (k - 1LL) / 2LL, t + (2LL * N - k - 1LL) * k / 2LL + 1});
    }

    ll ans = 0;
    for (auto &p : msecs) {
        ans += calc(p.second);
    }

    return ans;
}

int main() {
    cin >> N >> X >> D;

    cout << solve() << endl;

    return 0;
}
