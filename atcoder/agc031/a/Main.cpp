/*
[agc031] A - Colorful Subsequence
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const ll MOD = 1e9 + 7;
const int Z = 'z' - 'a' + 1;

int N;
string S;
ll cnt[Z];

ll solve() {
    for (int i = 0; i < N; i++) {
        cnt[S[i] - 'a']++;
    }

    ll ans = 1;
    for (int i = 0; i < Z; i++) {
        (ans *= cnt[i] + 1) %= MOD;
    }
    (ans += MOD - 1) %= MOD;

    return ans;
}

int main() {
    cin >> N;
    cin >> S;

    cout << solve() << endl;

    return 0;
}
