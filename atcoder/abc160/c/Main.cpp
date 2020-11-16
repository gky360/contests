/*
[abc160] C - Traveling Salesman around Lake
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

int K, N;
int A[MAX_N + 1];

ll solve() {
    sort(A, A + N);
    A[N] = A[0] + K;

    int ans = K;
    for (int i = 0; i < N; i++) {
        ans = min(ans, K - (A[i + 1] - A[i]));
    }
    return ans;
}

int main() {
    cin >> K >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
