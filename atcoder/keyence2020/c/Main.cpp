/*
[keyence2020] C - Subarray Sum
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int N, K, S;

void solve() {
    for (int i = 0; i < K; i++) {
        cout << S << " ";
    }
    int ns = S == 1 ? 2 : S - 1;
    for (int i = K; i < N; i++) {
        cout << ns << " ";
    }
    cout << endl;
}

int main() {
    cin >> N >> K >> S;

    solve();

    return 0;
}
