/*
[abc187] C - 1-SAT
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

const int MAX_N = 2e5;

int N;
string S[MAX_N];

string solve() {
    set<string> s0, s1;
    REP(i, N) {
        if (S[i][0] == '!') {
            s1.insert(S[i].substr(1));
        } else {
            s0.insert(S[i]);
        }
    }
    for (auto s : s0) {
        if (s1.count(s) > 0) return s;
    }

    return "satisfiable";
}

int main() {
    cin >> N;
    REP(i, N) cin >> S[i];

    cout << solve() << endl;

    return 0;
}
