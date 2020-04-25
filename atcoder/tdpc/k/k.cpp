// TDPC
// K - ターゲット

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

struct Circle {
    ll x, r;
    bool operator<(Circle c) {
        if (x + r == c.x + c.r) {
            return -x + r < -c.x + r;
        }
        return -x - r < -c.x - c.r;
    }
};

const int MAX_N = 100000;
const ll INF = 1e17;

int N;
Circle cc[MAX_N];
ll dp[MAX_N];

int main() {
    int ans;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> cc[i].x >> cc[i].r;
    }
    sort(cc, cc + N);

    fill(dp, dp + N, INF);
    for (int i = 0; i < N; i++) {
        int idx = lower_bound(dp, dp + N, cc[i].x - cc[i].r) - dp;
        dp[idx] = cc[i].x - cc[i].r;
    }

    ans = lower_bound(dp, dp + N, INF) - dp;
    cout << ans << endl;

    return 0;
}
