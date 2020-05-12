/*
[abc140] F - Many Slimes
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 18;

int N;
int S[1 << MAX_N];

bool solve() {
    multiset<int> ms;
    for (int i = 0; i < (1 << N); i++) {
        ms.insert(-S[i]);
    }

    vector<int> p = {*ms.begin()};
    ms.erase(ms.begin());

    for (int l = 1; l < (1 << N); l <<= 1) {
        for (int i = 0; i < l; i++) {
            int x = p[i];
            auto iter = ms.upper_bound(x);
            if (iter == ms.end()) {
                return false;
            }
            p.push_back(*iter);
            ms.erase(iter);
        }
    }

    return true;
}

int main() {
    cin >> N;
    for (int i = 0; i < (1 << N); i++) {
        cin >> S[i];
    }

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
