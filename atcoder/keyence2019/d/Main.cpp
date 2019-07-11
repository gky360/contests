/*
[keyence2019] D - Double Landscape
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
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
typedef pair<ll, ll> pll;

const ll MOD = 1e9 + 7;

int NM[2];
vector<int> AB[2];

ll solve() {
    for (int d = 0; d < 2; d++) {
        AB[d].push_back(NM[0] * NM[1] + 1);
        sort(AB[d].begin(), AB[d].end());
        if (unique(AB[d].begin(), AB[d].end()) != AB[d].end()) {
            return 0;
        }
    }

    ll ans = 1;
    for (int i = NM[0] * NM[1]; i > 0; i--) {
        int idx[2];
        for (int d = 0; d < 2; d++) {
            idx[d] = lower_bound(AB[d].begin(), AB[d].end(), i) - AB[d].begin();
        }

        ll t = 1;
        if (AB[0][idx[0]] != i && AB[1][idx[1]] != i) {
            t = (NM[0] - idx[0]) * (NM[1] - idx[1]) - (NM[0] * NM[1] - i);
        } else if (AB[0][idx[0]] != i) {
            t = (NM[0] - idx[0]);
        } else if (AB[1][idx[1]] != i) {
            t = (NM[1] - idx[1]);
        }

        (ans *= t) %= MOD;
    }

    return ans;
}

int main() {
    cin >> NM[0] >> NM[1];
    for (int d = 0; d < 2; d++) {
        AB[d].resize(NM[d]);
        for (int i = 0; i < NM[d]; i++) {
            cin >> AB[d][i];
        }
    }

    cout << solve() << endl;

    return 0;
}
