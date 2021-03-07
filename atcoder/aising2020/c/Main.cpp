/*
[aising2020] C - XYZ Triplets
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

const int MAX_N = 1e4;

int N;
ll ans[MAX_N + 1];

void solve() {
    for (int x = 1; x * x < N; x++) {
        for (int y = 1; y * y < N; y++) {
            for (int z = 1; z * z < N; z++) {
                ll n = x * x + y * y + z * z + x * y + y * z + z * x;
                if (n <= N) ans[n]++;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << endl;
    }
}

int main() {
    cin >> N;

    solve();

    return 0;
}
