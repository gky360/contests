/*
[abc156] F - Modularness
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_K = 5000;

int K, Q;
int D[MAX_K];

ll solve(int n, int x, int m) {
    int d[MAX_K];
    for (int i = 0; i < K; i++) {
        d[i] = D[i] % m;
    }

    int cnt = 0;
    ll a = x;
    for (int i = 0; i < K; i++) {
        int c = ((n - 1) / K + ((i < (n - 1) % K) ? 1LL : 0LL));
        a += 1LL * c * d[i];
        if (d[i] == 0) {
            cnt += c;
        }
    }

    return n - 1 - (a / m - x / m) - cnt;
}

int main() {
    cin >> K >> Q;
    for (int i = 0; i < K; i++) {
        cin >> D[i];
    }
    for (int i = 0; i < Q; i++) {
        int n, x, m;
        cin >> n >> x >> m;
        cout << solve(n, x, m) << endl;
    }

    return 0;
}
