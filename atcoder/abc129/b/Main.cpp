/*
[abc129] B - Balance
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 100;
const int INF = 1e9;

int N;
int W[MAX_N];

ll solve() {
    int ans = INF;
    for (int t = 0; t < N; t++) {
        ans = min(ans,
                  abs(accumulate(W, W + t, 0) - accumulate(W + t, W + N, 0)));
    }
    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }

    cout << solve() << endl;

    return 0;
}
