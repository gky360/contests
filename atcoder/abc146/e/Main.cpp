/*
[abc146] E - Rem of Sum is Num
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 2e5;

int N, K;
int A[MAX_N];
int S[MAX_N + 1];

ll solve() {
    S[0] = 0;
    for (int i = 1; i <= N; i++) {
        S[i] = S[i - 1] + A[i - 1] - 1;
        S[i] %= K;
    }

    map<int, int> cnt;
    ll ans = 0;
    for (int i = 0; i <= N; i++) {
        if (i - K >= 0) {
            cnt[S[i - K]]--;
        }
        ans += cnt[S[i]];
        cnt[S[i]]++;
    }

    return ans;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
