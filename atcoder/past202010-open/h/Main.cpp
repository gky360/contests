/*
[past202010-open] H - マス目のカット
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

const int MAX_N = 30;

int N, M, K;
string s[MAX_N];

bool can(int p, int q, int n) {
    vector<int> cnt(10);
    for (int i = p; i < p + n; i++) {
        for (int j = q; j < q + n; j++) {
            int x = s[i][j] - '0';
            cnt[x]++;
            if (cnt[x] >= n * n - K) return true;
        }
    }
    return false;
}

ll solve() {
    int ans = 0;
    REP(i, N) REP(j, M) {
        for (int k = 1; i + k <= N && j + k <= M; k++) {
            if (can(i, j, k)) {
                ans = max(ans, k);
            }
        }
    }

    return ans;
}

int main() {
    cin >> N >> M >> K;
    REP(i, N) cin >> s[i];

    cout << solve() << endl;

    return 0;
}
