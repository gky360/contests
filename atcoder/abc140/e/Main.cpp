/*
[abc140] E - Second Sum
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;

int N;
int P[MAX_N];

ll solve() {
    vector<pii> ps;
    for (int i = 0; i < N; i++) {
        ps.push_back({P[i], i + 1});
    }
    sort(ALL(ps), greater<pii>());

    ll ans = 0;
    set<int> s;
    s.insert(0);
    s.insert(N + 1);
    for (int i = 0; i < N; i++) {
        auto iter = s.insert(ps[i].second).first;
        auto l = iter, r = iter;
        int a, b, c, d, e;
        b = *(--l);
        a = (l == s.begin()) ? b : *(--l);
        c = ps[i].second;
        d = *(++r);
        e = (++r == s.end()) ? d : *r;

        ans += 1LL * ((b - a) * (d - c) + (c - b) * (e - d)) * ps[i].first;
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    cout << solve() << endl;

    return 0;
}
