/*
[abc162] D - RGB Triplets
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

const int MAX_N = 4000;

int N;
int S[MAX_N];
int cnt[3][MAX_N + 1];

ll solve() {
    REP(i, N) {
        REP(j, 3) cnt[j][i + 1] = cnt[j][i];
        cnt[S[i]][i + 1]++;
    }

    ll ans = 0;
    REP(i, N) for (int j = i + 1; j < N; j++) {
        if (S[i] == S[j]) continue;
        int x = 3 - S[i] - S[j];
        ans += cnt[x][N] - cnt[x][j + 1];
        if (2 * j - i < N && S[2 * j - i] == x) ans--;
    }

    return ans;
}

int main() {
    cin >> N;
    string s;
    cin >> s;
    for (int i = 0; i < N; i++) {
        if (s[i] == 'R') {
            S[i] = 0;
        } else if (s[i] == 'G') {
            S[i] = 1;
        } else {
            S[i] = 2;
        }
    }

    cout << solve() << endl;

    return 0;
}
