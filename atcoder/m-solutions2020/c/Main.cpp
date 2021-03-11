/*
[m-solutions2020] C - Marks
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

const int MAX_N = 200000;

int N, K;
int A[MAX_N];

void solve() {
    for (int i = K; i < N; i++) {
        cout << (A[i - K] < A[i] ? "Yes" : "No") << endl;
    }
}

int main() {
    cin >> N >> K;
    REP(i, N) cin >> A[i];

    solve();

    return 0;
}
