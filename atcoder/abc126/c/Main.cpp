/*
[abc126] C - Dice and Coin
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int N, K;

double solve() {
    double ans = 0;
    for (int k = 1; k <= N; k++) {
        int p = 0;
        while ((k << p) < K) {
            p++;
        }
        ans += pow(0.5, p);
    }
    ans /= N;

    return ans;
}

int main() {
    cin >> N >> K;

    cout << setprecision(15) << solve() << endl;

    return 0;
}
