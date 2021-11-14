/*
[abc188] C - ABC Tournament
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

const int MAX_N = 16;

int N;
int A[1 << MAX_N];

ll solve() {
    int l = max_element(A, A + (1 << (N - 1))) - A;
    int r = max_element(A + (1 << (N - 1)), A + (1 << N)) - A;

    ll ans = A[l] < A[r] ? l : r;
    return ans + 1;
}

int main() {
    cin >> N;
    REP(i, 1 << N) cin >> A[i];

    cout << solve() << endl;

    return 0;
}
