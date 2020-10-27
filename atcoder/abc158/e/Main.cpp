/*
[abc158] E - Divisible Substring
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 200000;
const int MAX_P = 10000;

int N, P;
string S;
int m[MAX_P];

ll solve() {
    if (P == 2 || P == 5) {
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            if ((S[i] - '0') % P == 0) {
                ans += i + 1;
            }
        }
        return ans;
    }

    int u = 0, o = 1;
    m[0] = 1;

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        u += (S[N - i - 1] - '0') * o;
        u %= P;

        ans += m[u];
        m[u]++;

        o *= 10;
        o %= P;
    }

    return ans;
}

int main() {
    cin >> N >> P;
    cin >> S;

    cout << solve() << endl;

    return 0;
}
