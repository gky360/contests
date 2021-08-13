/*
[agc049] B - Flip Digits
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

const int MAX_N = 5e5;

int N;
string S, T;
int f[2][MAX_N + 1];

ll solve() {
    int a[MAX_N + 1], b[MAX_N + 1];
    a[0] = b[0] = 0;
    REP(i, N) {
        a[i + 1] = a[i] ^ (S[i] - '0');
        b[i + 1] = b[i] ^ (T[i] - '0');
    }

    ll ans = 0;
    int x = 0;
    REP(i, N + 1) {
        x = max(x, i);
        if (a[x] == b[i]) continue;
        while (x + 1 <= N && a[x] == a[x + 1]) x++;
        if (x == N) return -1;
        x++;
        ans += x - i;
    }

    return ans;
}

int main() {
    cin >> N;
    cin >> S >> T;

    cout << solve() << endl;

    return 0;
}
