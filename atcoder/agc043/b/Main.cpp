/*
[agc043] B - 123 Triangle
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

const int MAX_N = 1e6;
const int D = 21;

int N;
int a[MAX_N];

int calc(int n, int k) {
    REP(i, D + 1) {
        if (((n >> i) & 1) < ((k >> i) & 1)) return 0;
    }
    return 1;
}

ll solve() {
    int s = 0, cnt = 0;
    REP(i, N) {
        s += a[i];
        if (a[i] % 2 == 1) {
            cnt ^= calc(N - 1, i);
        }
    }
    if (s == 0) return 0;
    if (cnt & 1) return 1;
    REP(i, N) if (a[i] == 1) return 0;
    REP(i, N) a[i] /= 2;
    return 2 * solve();
}

int main() {
    cin >> N;
    string s;
    cin >> s;
    REP(i, N) { a[i] = s[i] - '1'; }

    cout << solve() << endl;

    return 0;
}
