/*
[agc047] A - Integer Product
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

const int MAX_N = 200000;
const int K = 18;

int N;
string A[MAX_N];
ll cnt[K + 1][K + 1];

ll solve() {
    REP(i, N) {
        string g, s = A[i];
        if (count(s.begin(), s.end(), '.') != 0) {
            while (s.back() != '.') {
                g.push_back(s.back());
                s.pop_back();
            }
            s.pop_back();
            reverse(g.begin(), g.end());
        }
        while ((int)g.length() < 9) g.push_back('0');
        ll a = stoi(s) * 1000000000LL + stoi(g);

        int p = 0, q = 0;
        for (; a % 2 == 0; a /= 2) p++;
        for (; a % 5 == 0; a /= 5) q++;
        cnt[min(p, K)][min(q, K)]++;
    }

    ll ans = 0;
    REP(s, K + 1) REP(t, K + 1) REP(p, K + 1) REP(q, K + 1) {
        if (s + p >= K && t + q >= K) {
            if (s == p && t == q) {
                ans += cnt[s][t] * (cnt[s][t] - 1);
            } else {
                ans += cnt[s][t] * cnt[p][q];
            }
        }
    }

    return ans / 2;
}

int main() {
    cin >> N;
    REP(i, N) cin >> A[i];

    cout << solve() << endl;

    return 0;
}
