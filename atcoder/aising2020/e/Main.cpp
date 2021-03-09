/*
[aising2020] E - Camel Train
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double DD;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 2e5;

int N;
int K[MAX_N], L[MAX_N], R[MAX_N];

ll solve() {
    vector<pii> z[2];
    ll ans = 0;
    REP(i, N) {
        ans += min(L[i], R[i]);
        int d = L[i] - R[i];
        if (d >= 0) {
            z[0].push_back({K[i], d});
        } else {
            z[1].push_back({N - K[i], -d});
        }
    }
    REP(s, 2) {
        sort(ALL(z[s]));
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto& p : z[s]) {
            int k = p.first, d = p.second;
            q.push(d);
            while ((int)q.size() > k) q.pop();
        }
        while (!q.empty()) {
            ans += q.top();
            q.pop();
        }
    }

    return ans;
}

int main() {
    int T;
    cin >> T;
    REP(t, T) {
        cin >> N;
        REP(i, N) cin >> K[i] >> L[i] >> R[i];
        cout << solve() << endl;
    }

    return 0;
}
