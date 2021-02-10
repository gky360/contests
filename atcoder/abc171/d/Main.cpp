/*
[abc171] D - Replacing
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

const int MAX_N = 1e5;
const int MAX_Q = 1e5;

int N;
int A[MAX_N];
int Q;
int B[MAX_Q], C[MAX_Q];

void solve() {
    map<int, int> cnt;
    ll S = 0;
    REP(i, N) {
        S += A[i];
        cnt[A[i]]++;
    }

    REP(i, Q) {
        S += (C[i] - B[i]) * cnt[B[i]];
        cnt[C[i]] += cnt[B[i]];
        cnt[B[i]] = 0;
        cout << S << endl;
    }
}

int main() {
    cin >> N;
    REP(i, N) cin >> A[i];
    cin >> Q;
    REP(i, Q) cin >> B[i] >> C[i];

    solve();

    return 0;
}
