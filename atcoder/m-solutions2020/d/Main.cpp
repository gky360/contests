/*
[m-solutions2020] D - Road to Millionaire
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

const int MAX_N = 80;

int N;
int A[MAX_N];

ll solve() {
    ll s = 0, y = 1000;
    REP(i, N - 1) {
        if (A[i] < A[i + 1]) {
            ll c = y / A[i];
            y -= A[i] * c;
            s += c;
        } else {
            y += s * A[i];
            s = 0;
        }
    }

    ll ans = y + s * A[N - 1];
    return ans;
}

int main() {
    cin >> N;
    REP(i, N) cin >> A[i];

    cout << solve() << endl;

    return 0;
}
