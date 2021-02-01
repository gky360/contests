/*
[abc170] D - Not Divisible
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
const int MAX_A = 1e6;

int N;
int A[MAX_N];
bool dp[MAX_A + 1];

ll solve() {
    sort(A, A + N);

    ll ans = 0;
    REP(i, N) {
        if (!dp[A[i]] && !(i + 1 < N && A[i] == A[i + 1])) ans++;
        if (!dp[A[i]])
            for (int x = A[i]; x <= MAX_A; x += A[i]) dp[x] = true;
    }

    return ans;
}

int main() {
    cin >> N;
    REP(i, N) cin >> A[i];

    cout << solve() << endl;

    return 0;
}
