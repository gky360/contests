/*
[abc183] C - Travel
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

const int MAX_N = 8;

int N, K;
int T[MAX_N][MAX_N];

int calc(vector<int>& ord) {
    int d = T[0][ord[0]] + T[ord[ord.size() - 1]][0];
    for (int i = 0; i < (int)ord.size() - 1; i++) {
        d += T[ord[i]][ord[i + 1]];
    }
    return d;
}

ll solve() {
    vector<int> ord;
    REP(i, N - 1) ord.push_back(i + 1);
    ll ans = 0;
    do {
        if (calc(ord) == K) ans++;
    } while (next_permutation(ALL(ord)));
    return ans;
}

int main() {
    cin >> N >> K;
    REP(i, N) REP(j, N) cin >> T[i][j];

    cout << solve() << endl;

    return 0;
}
