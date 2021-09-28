/*
[past202012-open] D - Leading Zeros
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
typedef pair<string, int> psi;

const int MAX_N = 1e5;

int N;
string S[MAX_N];

void solve() {
    vector<psi> v;
    REP(i, N) {
        size_t l = S[i].find_first_not_of('0');
        if (l == string::npos) {
            v.push_back({"", S[i].length()});
        } else {
            v.push_back({S[i].substr(l), l});
        }
    }
    sort(ALL(v), [](psi a, psi b) -> bool {
        if (a.first.length() != b.first.length())
            return a.first.length() < b.first.length();
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    });

    REP(i, N) cout << string(v[i].second, '0') + v[i].first << endl;
}

int main() {
    cin >> N;
    REP(i, N) cin >> S[i];

    solve();

    return 0;
}
