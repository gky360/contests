/*
[abc190] B - Magic 3
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

const int MAX_N = 100;

int N, S, D;
int X[MAX_N], Y[MAX_N];

bool solve() {
    REP(i, N) {
        if (X[i] < S && Y[i] > D) return true;
    }
    return false;
}

int main() {
    cin >> N >> S >> D;
    REP(i, N) cin >> X[i] >> Y[i];

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
