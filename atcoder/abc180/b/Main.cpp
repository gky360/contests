/*
[abc180] B - Various distances
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;

int N;
int x[MAX_N];

void solve() {
    ll md = 0, us = 0;
    int cd = 0;
    for (int i = 0; i < N; i++) {
        md += abs(x[i]);
        us += 1LL * x[i] * x[i];
        cd = max(cd, abs(x[i]));
    }
    double ud = sqrt(us);

    cout << md << endl;
    cout << setprecision(15) << ud << endl;
    cout << cd << endl;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    solve();

    return 0;
}
