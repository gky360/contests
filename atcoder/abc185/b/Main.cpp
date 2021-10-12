/*
[abc185] B - Smartphone Addiction
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

const int MAX_M = 1000;

ll N;
int M, T;
int A[MAX_M + 1], B[MAX_M + 1];

bool solve() {
    A[M] = B[M] = T;

    ll r = N;
    int t = 0;
    REP(i, M + 1) {
        r -= A[i] - t;
        if (r <= 0) return false;
        r = min(N, r + B[i] - A[i]);
        t = B[i];
    }
    return true;
}

int main() {
    cin >> N >> M >> T;
    REP(i, M) cin >> A[i] >> B[i];

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
