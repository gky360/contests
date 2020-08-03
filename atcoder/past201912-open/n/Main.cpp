/*
[past201912-open] N - 整地 / Land Clearing
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

typedef tuple<int, int, int> Stone;

const int MAX_N = 100000;
const ll INF = 1e18;

int N, W, C;
Stone sts[MAX_N];

ll solve() {
    sort(sts, sts + N);

    priority_queue<pii, vector<pii>, greater<pii>> q;

    q.push({0, 0});
    int i = 0;
    ll s = 0;
    ll ans = INF;
    while (!q.empty()) {
        pii item = q.top();
        q.pop();
        int r = item.first, p = item.second;
        if (r + C > W) {
            break;
        }
        s -= p;
        for (; i < N && get<0>(sts[i]) < r + C; i++) {
            int il, ir, ip;
            tie(il, ir, ip) = sts[i];
            s += ip;
            q.push({ir, ip});
        }
        ans = min(ans, s);
    }

    return ans;
}

int main() {
    cin >> N >> W >> C;
    for (int i = 0; i < N; i++) {
        int l, r, p;
        cin >> l >> r >> p;
        sts[i] = Stone(l, r, p);
    }

    cout << solve() << endl;

    return 0;
}
