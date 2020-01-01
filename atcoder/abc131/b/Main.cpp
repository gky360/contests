/*
[abc131] B - Bite Eating
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_L = 100;

int N, L;

ll solve() {
    int ans = 0;
    int m = MAX_L;
    int mi;
    for (int i = 0; i < N; i++) {
        if (m > abs(L + i)) {
            m = abs(L + i);
            mi = i;
        }
        ans += L + i;
    }
    ans -= L + mi;

    return ans;
}

int main() {
    cin >> N >> L;

    cout << solve() << endl;

    return 0;
}
