/*
[abc189] B - Alcoholic
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

const int MAX_N = 1e3;

int N, X;
int V[MAX_N], P[MAX_N];

ll solve() {
    int s = 0;
    REP(i, N) {
        s += V[i] * P[i];
        if (s > X * 100) return i + 1;
    }

    return -1;
}

int main() {
    cin >> N >> X;
    REP(i, N) cin >> V[i] >> P[i];

    cout << solve() << endl;

    return 0;
}
