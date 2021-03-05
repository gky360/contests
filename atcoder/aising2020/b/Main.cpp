/*
[aising2020] B - An Odd Problem
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
int a[MAX_N];

ll solve() {
    ll ans = 0;
    REP(i, N) {
        if (i % 2 == 0 && a[i] % 2 == 1) ans++;
    }
    return ans;
}

int main() {
    cin >> N;
    REP(i, N) cin >> a[i];

    cout << solve() << endl;

    return 0;
}
