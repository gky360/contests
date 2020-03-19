/*
[abc136] B - Uneven Numbers
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int N;

ll solve() {
    int ans = 0;
    for (int k = 1; k <= N; k *= 100) {
        ans += min(N, k * 10 - 1) - k + 1;
    }

    return ans;
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
