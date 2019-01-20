/*
[agc026] C - String Coloring
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

typedef pair<string, string> pss;

int N;
string S;

ll solve() {
    string s[2];
    map<pss, ll> m[2];
    s[0] = string(S.begin(), S.begin() + N);
    s[1] = string(S.rbegin(), S.rbegin() + N);

    for (int k = 0; k < 2; k++) {
        for (ll b = 0; b < (1LL << N); b++) {
            pss key;
            for (int i = 0; i < N; i++) {
                if (b & (1LL << i)) {
                    key.first.push_back(s[k][i]);
                } else {
                    key.second.push_back(s[k][i]);
                }
            }
            m[k][key]++;
        }
    }

    ll ans = 0;
    for (auto& kv : m[0]) {
        pss key = kv.first;
        ll val = kv.second;
        ans += val * m[1][key];
    }

    return ans;
}

int main() {
    cin >> N;
    cin >> S;

    cout << solve() << endl;

    return 0;
}
