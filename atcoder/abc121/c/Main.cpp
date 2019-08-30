/*
[abc121] C - Energy Drink Collector
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;

int N, M;
pii AB[MAX_N];

ll solve() {
    sort(AB, AB + N);

    ll ans = 0;
    for (int i = 0, m = M; i < N && m > 0; i++) {
        int d = min(m, AB[i].second);
        m -= d;
        ans += 1LL * d * AB[i].first;
    }

    return ans;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> AB[i].first >> AB[i].second;
    }

    cout << solve() << endl;

    return 0;
}
