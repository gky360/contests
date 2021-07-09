/*
[past202010-open] A - 中央値
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

pii A[3];

char solve() {
    sort(A, A + 3);

    char ans = A[1].second + 'A';
    return ans;
}

int main() {
    REP(i, 3) cin >> A[i].first, A[i].second = i;

    cout << solve() << endl;

    return 0;
}
