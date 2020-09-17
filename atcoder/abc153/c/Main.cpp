/*
[abc153] C - Fennec vs Monster
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
int H[MAX_N];

ll solve() {
    sort(H, H + N);

    ll ans = 0;
    for (int i = 0; i < N - K; i++) {
        ans += H[i];
    }

    return ans;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    cout << solve() << endl;

    return 0;
}
