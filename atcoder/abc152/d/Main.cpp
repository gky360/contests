/*
[abc152] D - Handstand 2
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int N;
int cnt[10][10];

ll solve() {
    int k = 1;
    for (int i = 1; i <= N; i++) {
        int s = i / k, t = i % 10;
        if (s >= 10) {
            s = 1;
            k *= 10;
        }
        cnt[s][t]++;
    }

    ll ans = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            ans += 1LL * cnt[i][j] * cnt[j][i];
        }
    }
    return ans;
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
