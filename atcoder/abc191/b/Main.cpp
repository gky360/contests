/*
[abc191] B - Remove It
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

int N, X;
vector<int> A;

void solve() {
    A.erase(remove(ALL(A), X), A.end());
    for (int a : A) cout << a << " ";
    cout << endl;
}

int main() {
    cin >> N >> X;
    A.resize(N);
    REP(i, N) cin >> A[i];

    solve();

    return 0;
}
