// ARC096
// D - Static Sushi

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 100000;

int N;
ll C;
pli xv[MAX_N];

ll solve() {
    ll mr[MAX_N + 1], ml[MAX_N + 1], mr2, ml2;
    ll ans;

    ll s[MAX_N + 1];
    s[0] = 0;
    for (int i = 0; i < N; i++) {
        s[i + 1] = s[i] + xv[i].second;
    }

    mr[0] = mr2 = 0;
    ml[N] = ml2 = 0;

    for (int i = 0; i < N; i++) {
        mr[i + 1] = max(mr[i], s[i + 1] - xv[i].first);
    }
    for (int i = N - 1; i >= 0; i--) {
        ml[i] = max(ml[i + 1], s[N] - s[i] - (C - xv[i].first));
    }

    ans = max(mr[N], ml[0]);
    for (int i = 0; i < N; i++) {
        mr2 = max(mr2, s[i + 1] - 2LL * xv[i].first);
        ans = max(ans, mr2 + ml[i + 1]);
    }
    for (int i = N - 1; i >= 0; i--) {
        ml2 = max(ml2, s[N] - s[i] - 2LL * (C - xv[i].first));
        ans = max(ans, ml2 + mr[i]);
    }

    return ans;
}

int main() {
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> xv[i].first >> xv[i].second;
    }

    cout << solve() << endl;

    return 0;
}
