/*
[abc188] B - Orthogonality
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

const int MAX_N = 100000;

int N;
int A[MAX_N], B[MAX_N];

bool solve() {
    ll ans = 0;
    REP(i, N) ans += A[i] * B[i];
    return ans == 0;
}

int main() {
    cin >> N;
    REP(i, N) cin >> A[i];
    REP(i, N) cin >> B[i];

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
