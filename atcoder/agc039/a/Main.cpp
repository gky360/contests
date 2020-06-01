/*
[agc039] A - Connection and Disconnection
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

string S;
ll K;
int N;

ll solve() {
    N = S.length();
    if (S == string(N, S[0])) {
        return N * K / 2;
    }

    vector<int> cs;
    for (int i = 1, cnt = 1; i <= N; i++) {
        if (i < N && S[i - 1] == S[i]) {
            cnt++;
        } else {
            cs.push_back(cnt);
            cnt = 1;
        }
    }

    ll ans = 0;
    for (int c : cs) {
        ans += (c / 2) * K;
    }
    if (S[0] == S[N - 1]) {
        int x = *cs.begin();
        int y = *cs.rbegin();
        ans += ((x + y) / 2 * (K - 1)) - (x / 2) * (K - 1) - (y / 2) * (K - 1);
    }

    return ans;
}

int main() {
    cin >> S;
    cin >> K;

    cout << solve() << endl;

    return 0;
}
