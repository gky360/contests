/*
[abc183] D - Water Heater
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
const int MAX_T = 2e5;

int N;
ll W;
int S[MAX_N], T[MAX_N];
ll P[MAX_N];
ll x[MAX_T + 1];

bool solve() {
    REP(i, N) x[S[i]] += P[i], x[T[i]] -= P[i];
    REP(i, MAX_T) x[i + 1] += x[i];
    return *max_element(x, x + MAX_T + 1) <= W;
}

int main() {
    cin >> N >> W;
    REP(i, N) cin >> S[i] >> T[i] >> P[i];

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
