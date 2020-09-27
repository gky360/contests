/*
[abc154] D - Dice in Line
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 200000;

int N, K;
int p[MAX_N];

double solve() {
    double ans = 0;
    ll s = 0;
    for (int i = 0; i < K; i++) s += p[i] + 1;
    for (int i = K; i <= N; i++) {
        ans = max(ans, s * 0.5);
        if (i < N) {
            s += p[i] + 1;
            s -= p[i - K] + 1;
        }
    }

    return ans;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }

    cout << fixed << setprecision(12) << solve() << endl;

    return 0;
}
