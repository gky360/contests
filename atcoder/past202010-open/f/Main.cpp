/*
[past202010-open] F - 構文解析
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

const int MAX_N = 1e5;

int N, K;
string S[MAX_N];

string solve() {
    map<string, int> m;

    REP(i, N) m[S[i]]++;

    vector<pair<int, string>> v;
    for (auto [s, n] : m) {
        v.push_back({-n, s});
    }
    sort(ALL(v));

    if ((K - 2 >= 0 && v[K - 2].first == v[K - 1].first) ||
        (K < (int)v.size() && v[K].first == v[K - 1].first)) {
        return "AMBIGUOUS";
    }
    return v[K - 1].second;
}

int main() {
    cin >> N >> K;
    REP(i, N) cin >> S[i];

    cout << solve() << endl;

    return 0;
}
