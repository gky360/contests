/*
[abc169] E - Count Median
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

const int MAX_N = 2e5;

int N;
ll A[MAX_N], B[MAX_N];

ll solve() {
    sort(A, A + N);
    sort(B, B + N);

    ll ans = N % 2 == 0
                 ? (B[N / 2 - 1] + B[N / 2]) - (A[N / 2 - 1] + A[N / 2]) + 1
                 : B[N / 2] - A[N / 2] + 1;
    return ans;
}

int main() {
    cin >> N;
    REP(i, N) cin >> A[i] >> B[i];

    cout << solve() << endl;

    return 0;
}
