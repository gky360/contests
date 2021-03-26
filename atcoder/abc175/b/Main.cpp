/*
[abc175] B - Making Triangle
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

int N;
int L[MAX_N];

ll solve() {
    ll ans = 0;
    REP(i, N) for (int j = i + 1; j < N; j++) for (int k = j + 1; k < N; k++) {
        vector<int> l = {L[i], L[j], L[k]};
        sort(ALL(l));
        if (l[0] != l[1] && l[1] != l[2] && l[0] + l[1] > l[2]) ans++;
    }

    return ans;
}

int main() {
    cin >> N;
    REP(i, N) cin >> L[i];

    cout << solve() << endl;

    return 0;
}
