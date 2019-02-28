/*
[arc103] D - Robot Arms
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 1000;

int N;
ll X[MAX_N], Y[MAX_N];

void solve() {
    char op[4] = {'L', 'D', 'U', 'R'};
    int M = 31;
    int odd = (X[0] + Y[0] + (1LL << M)) % 2;
    string w[MAX_N];

    for (int n = 0; n < N; n++) {
        if ((X[n] + Y[n] + (1LL << M)) % 2 != odd) {
            cout << -1 << endl;
            return;
        }

        ll u = X[n] + Y[n] + (1 - odd);
        ll v = X[n] - Y[n] + (1 - odd);
        ll ub = (u + (1LL << M) - 1) / 2;
        ll vb = (v + (1LL << M) - 1) / 2;

        w[n].resize(M + (1 - odd));
        for (int i = 0; i < M; i++) {
            int pat = ((ub >> i) & 1) * 2 + ((vb >> i) & 1);
            w[n][i] = op[pat];
        }
        if (odd == 0) {
            w[n][M] = 'L';
        }
    }

    cout << M + (1 - odd) << endl;
    ll p = 1;
    for (int i = 0; i < M; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << p;
        p <<= 1;
    }
    if (odd == 0) {
        cout << " " << 1 << endl;
    } else {
        cout << endl;
    }
    for (int i = 0; i < N; i++) {
        cout << w[i] << endl;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    solve();

    return 0;
}
