/*
[abc182] C - To 3
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

ll N;

ll solve() {
    int s = 0, l = 0;
    int cnt[3] = {0, 0, 0};
    for (ll n = N; n > 0; n /= 10) {
        (s += n % 10) %= 3;
        l++;
        cnt[(n % 10) % 3]++;
    }
    if (s == 0) return 0;
    if (cnt[s] > 0 && l > 1) return 1;
    if (cnt[3 - s] >= 2 && l > 2) return 2;
    return -1;
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
