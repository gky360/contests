/*
[abc156] A - Beginner
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int N, R;

ll solve() {
    if (N >= 10) {
        return R;
    }

    return R + 100 * (10 - N);
}

int main() {
    cin >> N >> R;

    cout << solve() << endl;

    return 0;
}
