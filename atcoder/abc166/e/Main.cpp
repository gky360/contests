/*
[abc166] E - This Message Will Self-Destruct in 5s
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 2e5;

int N;
int A[MAX_N];

ll solve() {
    ll ans = 0;
    map<int, int> cnt;
    for (int i = 0; i < N; i++) {
        ans += cnt[i - A[i]];
        cnt[i + A[i]]++;
    }
    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
